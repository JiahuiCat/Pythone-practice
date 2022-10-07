/* 6.6 if...else语句和switch语句的区别 
1.语法的比较
if需要配合else关键字进行使用，switch需要配合case关键字进行使用；if语句是先对条件进行判断，而switch语句是后进行判断。

2.效率的比较
if ... else结构对少量的检验，判断速度比较快，但是随则检验的增长，会逐渐变慢，其中的默认情况最慢。
使用if else结构可以判断表达式，同样存在随着深度增加检验速度逐渐变慢的问题，也不容易进行后续的添加扩充。

switch结构中，除了default默认情况下，对其他每一项case的检验速度都是相同的。default默认情况比其他情况都快。

结论:当需要判定的情况较少时，使用if...else结构比使用switch结构检验速度快。
eg,分支在3个或4个一下，用if...else结构比较好，否则应选择switch结构*/

/* eg 6.13 if语句和switch语句的综合应用
设计程序:输入一年中的月份，得到这个月所包含的天数。用户需判断数量的情况，根据需求选择使用if语句或switch语句 */
#include<stdio.h>
int main(){
    int iMonth=0,iDay=0;//定义iMonth，iDay变量
    printf("Enter the month you want to know the days\n");//提示信息
    scanf("%d",&iMonth);//输入数据
    switch (iMonth)//检验变量
    {
        //多路开关模式switch语句进行检验
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        iDay=31;//iDay赋值为31
        break;//跳出switch结构
    case 4:
    case 6:
    case 9:
    case 11:
        iDay=30;//iDay赋值为30
        break;  //跳出switch结构
    case 2:
        iDay=28;//iDay赋值为28
        break;  //跳出switch结构
    default://默认情况
        iDay=-1;//赋值为-1
        break;
    }
    if(iDay ==-1){//使用if语句判断iDay的值
        printf("There is a error with you enter\n");
    }
    else//默认情况
    {
        printf("2022.%d has %d days\n",iMonth,iDay);
    }
    return 0;
}
/* 程序分析:判断一年中12个月份所包含的日期数，就要对12种不同的情况进行检验。
由于检验数量比较多,所以使用switch结构判断月份比较合适，并且可以使用多路开关模式，程序更简洁。
其中case语句用来判断月份iMonth的情况，并且为iDay赋相应的值。default默认处理为输入的月份不符合检验条件时,iDay赋值为-1。
*/