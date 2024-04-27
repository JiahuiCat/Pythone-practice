#Python 编写的文本冒险游戏
#导入模块
from sys import exit

#定义函数
def gold_room():
    print("This room is full of gold.How much do you take?")

    #此行提示用户从控制台输入文本。
    #input() 函数会显示一个提示（在本例中是 > 字符）并等待用户输入内容。
    #然后将用户的输入存储在名为 choice 的变量中。
    #语句不仅可以捕获用户输入，还可以将其分配给名为 choice 的变量。
    #此变量随后可用于后续代码中处理用户的输入并确定程序的流程。
    choice=input("> ")

    #这是一个检查条件的 if 语句。
    #条件 if "0" in choice 检查字符串“0”是否存在于 choice 变量的任何位置。
    #or 关键字将此条件与另一个条件组合在一起：if "1" in choice。
    #这意味着如果在 choice 中找到“0”或“1”之一，则整个条件为真。
    #只有当 if 语句中的条件为真（即在 choice 中找到“0”或“1”）时，此行才会执行。
    #它使用 int() 函数尝试将存储在 choice 中的值转换为整数。
    #如果转换成功（因为 choice 只包含“0”或“1”），则转换后的整数值将存储在变量 how_much 中。
    if "0" in choice or "1" in choice:
        how_much=int(choice)
        
    else:
        dead("Man,learn to type a number.")

    if how_much < 50:
        print("Nice,you're not greedy,you win!")
        exit(0)
    else:
        dead("You greedy bastard!")

def bear_room():
    print("There is a bear here.")
    print("There bear has bunch of honey.")
    print("The fat bear is in front of another door.")
    print("How are you going to move the bear?")
    bear_moved=False

    while True:
        choice=input("> ")

        if choice=="take honey":
            dead("The bear looks at you then slaps your face off.")
        elif choice=="taunt bear" and not bear_moved:
            print("The bear has moved from the door.")
            print("You can go through it now.")
            bear_moved =True
        elif choice=="taunt bear"and bear_moved:
            dead("The bear gets pissed off and chews your leg off.")
        elif choice=="open door" and bear_moved:
            gold_room()
        else:
            print("I got no idea what that means.")
        
def cthulhu_room():
    print("Here you see the great evil Cthulhu.")
    print("He,it,whatever stares at you and you go insane.")
    print("Do you flee for your life or eat your head?")

    choice=input("> ")

    if "flee" in choice:
        start()
    elif "head" in choice:
        dead("Well that was tasty！")
    else:
        cthulhu_room()

def dead(why):
    print(why,"Good jod!")
    exit(0)

def start():
    print("You are in a dark room.")
    print("There is a door to your right and left.")
    print("Which one do you take?")

    choice=input("> ")

    if choice=="left":
        bear_room()
    elif choice=="right":
        cthulhu_room()
    else:
        dead("You stumble around the room until you starve.")

start()