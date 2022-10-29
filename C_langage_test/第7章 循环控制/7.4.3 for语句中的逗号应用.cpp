/* 7.4.3 for语句中的逗号应用
for语句中，表达式1和表达式3处，除了可以使用简单的表达式外，还可以使用逗号表达式。
    如for(iSum=0,iCount=1;iCount<10;iCount++){
        iSum=iCount+iSum;
    }
    
    或者执行循环变量自加操作两次；
    如for(iCount=0;iCount<10;iCount++,iCount++){
        iSum=iSum+iCount;
    } 
    相当于
    for(iCount=0;iCount<10;iCount=iCount+2){

    }
    eg7.7计算1~100之间所有偶数的累加结果。
        为变量赋初值的操作都放在for语句中，并且对循环变量进行两次自加操作，这样所求出的结果就是所有偶数之和。
    */
#include<stdio.h>
int main(){
    int iSum,iCount;//定义变量
    //在for循环中，为变量赋值，对循环变量进行两次自增运算
    for (iSum=0,iCount=0;iCount<=100;iCount++,iCount++)
    {
        iSum=iSum+iCount;//进行累加计算
    }
    printf("The result is:%d\n",iSum);//输出结果
    return 0;
}