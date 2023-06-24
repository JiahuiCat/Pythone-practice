type_of_people = 10  # 将右边的值赋给左边的变量名

x=f"There are {type_of_people} type of people."#将type_of_people变量代入string字符串中

brinary="binary" #文本值赋给brinary
do_not = "don't"  # 文本值赋给do_not
y=f"Those who know {brinary} and those who {do_not}"

print(x)#输出x
print(y)#输出y
print(f"I said:{x}")#将变量x代入字符串中
print(f"I also said:'{y}'")#将变量y代入字符串中

hilarious=False
joke_evaluation="Isn't that joke so funny?{}!"

print(joke_evaluation.format(hilarious))#.format()语法的格式化方式,创建的字符串上应用格式化

w="This is the left side of ..."
e="a string with a right side"

print(w+e)

#变量是你用""名字=值"这样的代码设置出来
