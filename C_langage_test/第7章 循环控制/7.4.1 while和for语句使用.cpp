/* eg 7.5使用while语句模仿for语句的一般形式
先使用for语句实现一个有循环功能的操作，在使用while语句实现相同的功能。注意for语句中的表达式与while语句中的表达式所对应的位置 */
#include<stdio.h>

int main(){
    int iNumber;//定义变量,表示1~100之间的数字
    int iSum=0;//保存计算后的结果
    for (iNumber=0;iNumber<=100;iNumber++)//iNumber为循环次数
    {
        iSum=iNumber+iSum;//累加计算
    }
    printf("The result is:%d\n",iNumber);//输出计算结果

    iSum=0;//恢复计算结果
    iNumber=1;//设定循环控制变量的初值

    while (iNumber<=100)
    {
        iSum=iSum+iNumber;//累加计算
        iNumber++;//循环变量自增
    }
    printf("The result is:%d\n",iSum);//输出计算结果
    return 0;
    
}