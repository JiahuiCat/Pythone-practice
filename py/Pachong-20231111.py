#coding=gbk
import requests #����HTTP����
from lxml import etree #���ڽ���HTML
import random #���������
import os #�����ļ�����
from multiprocessing.dummy import Pool #ʹ�ö��̳߳������ȡЧ��

# �����Ƶ�洢Ŀ¼�Ƿ���ڣ�����������򴴽�
if not os.path.exists('./����Ƶ'):
    os.mkdir('./����Ƶ')
save_path = './����Ƶ/'

# URL�б�
host_url_list = ['https://www.pearvideo.com/category_1', 'https://www.pearvideo.com/panorama']
# ����host_headers����ͷ
host_headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 Edg/119.0.0.0"
}


# ��ȡ��վ������Ϣ
site_titles = []
for host_url in host_url_list:
    page_text = requests.get(host_url, headers=host_headers).text
    tree = etree.HTML(page_text)
    site_title = tree.xpath('//title/text()')[0]
    site_titles.append(site_title)

# �û�ѡ��URL
print("��ӭʹ������Ƶ���ع���")
print("��ѡ��Ҫ��ȡ����վ:")

for i, (url, title) in enumerate(zip(host_url_list, site_titles), 1):
    print(f"{i}. {title}")

while True:
    try:
        choice = int(input("���������� 1 �� 2 ��ѡ��: "))
        if 1 <= choice <= 2:
            break
        else:
            print("��������Ч��ѡ�� (1 �� 2) ")
    except ValueError:
        print("��������Ч��ѡ�� (1 �� 2)")

selected_url = host_url_list[choice - 1]
# ��ȡ�û�ѡ���URL
host_url = selected_url

# ����GET�����ȡ��ҳhost_url��HTML����
page_text = requests.get(url=host_url, headers=host_headers).text
tree = etree.HTML(page_text)

# ��ȡhost��ҳ�е�inner��Ƶ����
inner_href_list = tree.xpath('//div[@class="vervideo-bd"]/a/@href')

# ���inner_href���Ӷ�Ӧ�ı���
print("\n�����ǿɹ����ص���Ƶ����:")
inner_url_list = []
for i, inner_href in enumerate(inner_href_list, 1):
    inner_url = 'https://www.pearvideo.com/' + inner_href
    inner_url_list.append(inner_url)
    inner_text = requests.get(url=inner_url, headers=host_headers).text
    title = etree.HTML(inner_text).xpath('//h1[@class="video-tt"]/text()')[0]
    print(f"{i}. {title}")

# �û�ѡ��Ҫ���ص�inner_href��Ƶ
selected_indices = input("����Ҫ���ص���Ƶ��ţ��ö��ŷָ�����1,3,5��������ֱ�Ӱ��س�����������Ƶ��")
if selected_indices:
    selected_indices = [int(i) - 1 for i in selected_indices.split(",")]
else:
    selected_indices = range(len(inner_href_list))

# ʹ�ö��̳߳������ȡЧ��
pool = Pool(6)

# ����һ��������Ƶ�ĺ���
def download_video(index):
    inner_url = inner_url_list[index]
    # 4.������ҳԴ������з������ҳ���Ƶ���ӡ�
    #   ����ͨ�����������ǿ��Է�����Ƶ������ҳԴ�������ǲ�������Ƶ���ӵģ�Ҳ����˵����ҳ�е���Ƶ �Ƕ�̬���س����ģ���ʱ�����Ҫ����ȥ����ajax�ļ��ˡ�
    #   ͨ��ץ�����ߣ����ǿ��Կ���Fetch/XHD�д�������һ������https://www.pearvideo.com/videoStatus.jsp?contId=1156899&mrd=0.13727699405356097�����Ǵ�������ӣ����ֲ�����������Ҫ����Ƶ�����������ģ�
    # {
    # "resultCode":"5",
    # "resultMsg":"�������Ѿ����ߣ�",
    # "systemTime": "1676187693726"
    # }
    #   ��ʵ������վʹ�õ�һ�ַ������ƣ���������������Referer��
    #   ͨ��ץ�����ߣ����ǿ��Կ����������Referer�ǣ�https://www.pearvideo.com/video_1156899 ������Ӿ������ǵ�inner_url

    # 5.�ҳ�ajax�ļ���������url�����ҵ����� contId �� mrd
    #   �������������ǿ��Կ������� mrd ��һ������ĸ������������������Χ��0-1֮��

    # ��ȡ����ҳ��HTML����
    inner_text = requests.get(url=inner_url, headers=host_headers).text
    # ��ȡ��Ƶ�����contId
    title = etree.HTML(inner_text).xpath('//h1[@class="video-tt"]/text()')[0] + '.mp4'
    contId = etree.HTML(inner_text).xpath('//div[@id="poster"]/@data-cid')[0]

    # ����һ�������mrd����
    mrd = random.random()

    # �������ڻ�ȡ��Ƶ��ʵ���ӵ�ajax����url
    ajax_url = 'https://www.pearvideo.com/videoStatus.jsp?'
    params = {
        "contId": contId,
        "mrd": mrd
    }

    # 6.����ajax�����ͷ��������Referer
    ajax_headers = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 Edg/119.0.0.0",
        "Referer": inner_url
    }

    # ����ajax���󣬻�ȡ��Ƶ��Ϣ��JSON����
    response = requests.get(url=ajax_url, headers=ajax_headers, params=params)

    # ��ȡJSON�е�systemTime��srcUrl
    systemTime = response.json()['systemTime']
    srcUrl = response.json()['videoInfo']['videos']['srcUrl']

    # print(srcUrl)

    # 7.��ʱ�����ҵ���json�ļ��а�������Ƶurl���������Ǵ򿪷�����ҳ404���������ζ�����������ʵ��������������Ƶ���ӣ���ô�����ǿ�ʼ����Ƶ���з�����
    # ������Ƶ�����������ǣ�https://video.pearvideo.com/mp4/short/20170915/cont-1156899-10890623-hd.mp4
    # ͨ���Աȷ��������Է�������������ֻ��һ����ͬ�ĵط�(systemTime)����ô���������Ǿ�Ҫ��αװ������ͨ���ַ����滻���õ���������Ƶ����

    # 8.�滻αװ����Ƶ�����е�systemTime��������ȡ��������Ƶ����
    srcUrl = str(srcUrl).replace(str(systemTime), f'cont-{contId}')

    # ���������ȡ��Ƶ����
    content = requests.get(url=srcUrl, headers=ajax_headers).content

    # 9.����Ƶ���ݱ��浽ָ��Ŀ¼�£�����Ƶ��������
    with open(save_path + title, mode='wb') as fp:
        fp.write(content)
        fp.close()

    # ��ӡ��ʾ��Ϣ
    print(f'{title} ������ϣ�����')

# �����û�ѡ�����Ƶ���ӣ���ÿ�����Ӽ��뵽������������
pool.map(download_video, selected_indices)

# �ȴ������������
pool.close()
pool.join()
