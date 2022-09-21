/* 6.3if的嵌套形式 
在if语句中包含一个或多个if语句，称为if语句的嵌套。

if(表达式 1)
    if(表达式 2)    语句块 1
    else 语句块 2
else
    if(表达式 3)    语句块3
    else 语句块 4

if语句的嵌套形式，可对判断的条件进行细化，然后进行相应的操作
if语句判断表达式 1，就像判断今天是不是星期六。如果if语句判断表达式 2为真，那么执行语句块 1中的内容: 
如果不为真，那么执行语句块 2中的内容

eg1,如果为星期六，就陪朋友逛街，如果为星期日，就陪家人在家。外面的else语句表示不为休息日时的相应操作。

if(iDay>Friday) //判断为休息日的情况
{
    if(iDay == Saturday)    //判断为周六时的操作
    {}
    else    //为周日时的操作
    {}
}
else    //不为休息日的情况
{   
    if(iDay == Monday)  //判断为周一时的情况
    {}
    else
    {}
}
 */
/* eg6.8 使用if嵌套语句选择日程安排。
使用if嵌套语句对输入的数据逐步进行判断，最终选择执行相应的操作。
*/
#include<stdio.h>

int main(){
    int iDay=0;//定义变量表示输入的星期
    /* 定义变量代表一周中的每一天 */
    int Monday=1,Tuesday=2,Wednesday=3,Thursday=4,Friday=5,Saturday=6,Sunday=7;
    printf("Enter a day of week to get course:\n");//提示信息
    scanf("%d",&iDay);//iDay接受输入的值,int型

    if(iDay>Friday){//休息日的情况
        if(iDay==Saturday){//当为星期六的时候
            printf("Go shopping with friends\n");
        }
        else//否则为星期日
        {
            printf("Stay at home with families\n");
        }
    }
    else//工作日的情况
    {
        if (iDay==Monday)//当iDay的值等于Monday
        {
            printf("have a meeting in the corporation\n");
        }
        else//为其他星期的时候
        {
            printf("Working with partner\n");
        }
    }
    return 0;
}
/* 程序分析:
1）定义变量iDay用来保存后面用户输入的数值，而其他变量如Monday...表示每周中的每一天
2）当输入6时。if语句判断表达式iDay>Friday,如果成立，则表示输入的数值为休息日，否则else表示工作日的部分。
如果判断为真，则再用if语句判断iDay是否等于Saturday变量的值，如果等于，表示为星期六，执行后面的语句;
else语句表示星期日，执行后面的语句。
 */