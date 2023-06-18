#coding=gbk

my_name='Zed A. Shaw'
my_age=35#not a lie
my_height=74#inches
my_weight=180#lbs
my_eyes='Blue'
my_teeth='White'
my_hair='Brown'

print(f"Let's talk about {my_name}.")
print(f"He's {my_height} inches tall.")
print(f"He's {my_weight} pounds heavy.")
print("Actually that's not too heavy.")
print(f"He's got {my_eyes} eyes and {my_hair} hair.")
print(f"His teeth are usually {my_teeth} depending on the coffee.")

#this line is tricky,try to get it exactly right
total =my_age + my_height +my_weight
print(f"If I add {my_age},{my_height},and {my_weight} I get {total}.")

#定义变量 1='Zed shaw',1不是一个有效的变量名称。变量名要以字母开头，所有a1可以，而1不行。
#将浮点数四舍五入，可以使用round()函数，如round(1.7333)
