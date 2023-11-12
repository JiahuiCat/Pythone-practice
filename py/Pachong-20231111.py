#coding=gbk
import requests #发送HTTP请求
from lxml import etree #用于解析HTML
import random #生成随机数
import os #用于文件操作
from multiprocessing.dummy import Pool #使用多线程池提高爬取效率

# 检查视频存储目录是否存在，如果不存在则创建
if not os.path.exists('./梨视频'):
    os.mkdir('./梨视频')
save_path = './梨视频/'

# URL列表
host_url_list = ['https://www.pearvideo.com/category_1', 'https://www.pearvideo.com/panorama']
# 设置host_headers请求头
host_headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 Edg/119.0.0.0"
}


# 获取网站标题信息
site_titles = []
for host_url in host_url_list:
    page_text = requests.get(host_url, headers=host_headers).text
    tree = etree.HTML(page_text)
    site_title = tree.xpath('//title/text()')[0]
    site_titles.append(site_title)

# 用户选择URL
print("欢迎使用梨视频下载工具")
print("请选择要爬取的网站:")

for i, (url, title) in enumerate(zip(host_url_list, site_titles), 1):
    print(f"{i}. {title}")

while True:
    try:
        choice = int(input("请输入数字 1 或 2 来选择: "))
        if 1 <= choice <= 2:
            break
        else:
            print("请输入有效的选择 (1 或 2) ")
    except ValueError:
        print("请输入有效的选择 (1 或 2)")

selected_url = host_url_list[choice - 1]
# 获取用户选择的URL
host_url = selected_url

# 发送GET请求获取主页host_url的HTML内容
page_text = requests.get(url=host_url, headers=host_headers).text
tree = etree.HTML(page_text)

# 提取host主页中的inner视频链接
inner_href_list = tree.xpath('//div[@class="vervideo-bd"]/a/@href')

# 输出inner_href链接对应的标题
print("\n以下是可供下载的视频标题:")
inner_url_list = []
for i, inner_href in enumerate(inner_href_list, 1):
    inner_url = 'https://www.pearvideo.com/' + inner_href
    inner_url_list.append(inner_url)
    inner_text = requests.get(url=inner_url, headers=host_headers).text
    title = etree.HTML(inner_text).xpath('//h1[@class="video-tt"]/text()')[0]
    print(f"{i}. {title}")

# 用户选择要下载的inner_href视频
selected_indices = input("输入要下载的视频序号（用逗号分隔，如1,3,5），或者直接按回车下载所有视频：")
if selected_indices:
    selected_indices = [int(i) - 1 for i in selected_indices.split(",")]
else:
    selected_indices = range(len(inner_href_list))

# 使用多线程池提高爬取效率
pool = Pool(6)

# 定义一个下载视频的函数
def download_video(index):
    inner_url = inner_url_list[index]
    # 4.对详情页源代码进行分析，找出视频链接。
    #   但是通过分析，我们可以发现视频的详情页源代码中是不含有视频链接的，也就是说详情页中的视频 是动态加载出来的，这时候就需要我们去分析ajax文件了。
    #   通过抓包工具，我们可以看到Fetch/XHD中存在这样一个请求：https://www.pearvideo.com/videoStatus.jsp?contId=1156899&mrd=0.13727699405356097。但是打开这个链接，发现并不是我们想要的视频，而是这样的：
    # {
    # "resultCode":"5",
    # "resultMsg":"该文章已经下线！",
    # "systemTime": "1676187693726"
    # }
    #   其实这是网站使用的一种反爬机制，即——防盗链（Referer）
    #   通过抓包工具，我们可以看到该请求的Referer是：https://www.pearvideo.com/video_1156899 这个链接就是我们的inner_url

    # 5.找出ajax文件发出请求url，并找到参数 contId 和 mrd
    #   经常分析，我们可以看出参数 mrd 是一个随机的浮点数，这个浮点数范围是0-1之间

    # 获取详情页的HTML内容
    inner_text = requests.get(url=inner_url, headers=host_headers).text
    # 提取视频标题和contId
    title = etree.HTML(inner_text).xpath('//h1[@class="video-tt"]/text()')[0] + '.mp4'
    contId = etree.HTML(inner_text).xpath('//div[@id="poster"]/@data-cid')[0]

    # 生成一个随机的mrd参数
    mrd = random.random()

    # 构造用于获取视频真实链接的ajax请求url
    ajax_url = 'https://www.pearvideo.com/videoStatus.jsp?'
    params = {
        "contId": contId,
        "mrd": mrd
    }

    # 6.设置ajax请求的头部，包括Referer
    ajax_headers = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 Edg/119.0.0.0",
        "Referer": inner_url
    }

    # 发送ajax请求，获取视频信息的JSON数据
    response = requests.get(url=ajax_url, headers=ajax_headers, params=params)

    # 提取JSON中的systemTime和srcUrl
    systemTime = response.json()['systemTime']
    srcUrl = response.json()['videoInfo']['videos']['srcUrl']

    # print(srcUrl)

    # 7.此时我们找到了json文件中包含的视频url，但是我们打开发现网页404报错，这就意味着这个链接其实并不是真正的视频链接；那么，我们开始对视频进行分析，
    # 发现视频的真正链接是：https://video.pearvideo.com/mp4/short/20170915/cont-1156899-10890623-hd.mp4
    # 通过对比分析，可以发现这两个链接只有一处不同的地方(systemTime)，那么接下来我们就要把伪装的链接通过字符串替换，拿到真正的视频链接

    # 8.替换伪装的视频链接中的systemTime参数，获取真正的视频链接
    srcUrl = str(srcUrl).replace(str(systemTime), f'cont-{contId}')

    # 发送请求获取视频内容
    content = requests.get(url=srcUrl, headers=ajax_headers).content

    # 9.将视频内容保存到指定目录下，以视频标题命名
    with open(save_path + title, mode='wb') as fp:
        fp.write(content)
        fp.close()

    # 打印提示信息
    print(f'{title} 下载完毕！！！')

# 遍历用户选择的视频链接，将每个链接加入到并行下载任务
pool.map(download_video, selected_indices)

# 等待所有任务完成
pool.close()
pool.join()
