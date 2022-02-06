#include<stdio.h>
/* 函数的嵌套调用和递归调用
（1）执行main函数的开头部分；
（2）遇函数调用语句，调用函数a，流程转去a函数；
（3）执行a函数的开头部分；
（4）遇函数调用语句，调用函数b，流程转去函数b；
（5）执行b函数，如果再无其他嵌套的函数，则完成b函数的全部操作；
（6）返回到a函数中嗲用b函数的位置；
（7）继续执行a函数中尚未执行的部分，直到a函数结束；
（8）返回main函数中调用a函数的位置；
（9）继续执行main函数的剩余函数部分直到结束
 */

/* 例7.3输入4个整数，找出其中最大的数。用一个函数来实现。
 */

/* 解题思路定义一个函数max_4来实现从4个数中找出最大的数。
先用max（a,b）找出a和b中的大者，赋给变量m。
再用max(m,c)函数求出a,b,c三者中的大者,再赋给m（因为m是a和b中的大者，因此max（m,c）就是a,b,c三者中的大者），把它赋给m。自用max（m,d）求出a,b,c,d四者中的大者，它就是a,b,c,d四个数中的最大者。
 在max中调用三次max函数，就求出4个数中的最大者。最后在主函数中输出结果。
 */

int max(int x, int y) //定义max函数
{
    if (x > y)
        return x;
    else
        return y; //函数返回值是x和y的最大者
}

int max_4(int a,int b,int c,int d)//定义max_4函数
{
    int max(int,int);
    int m;
    m=max(a,b);//调用max函数，找出a和b中的最大者
    m=max(m,c);//调用max函数，找出m,c中的最大者
    m=max(m,d);//调用max函数，找出m,d中的最大者
    return(m);//函数返回值是4个数中的最大者
}

int main(){
    int max_4(int a,int b,int c,int d);//对函数max_4函数的声明
    int a,b,c,d,max;//定义这a,b,c,d,max为int型
    printf("Please enter 4 integer numbers:");
    scanf("%d,%d,%d,%d", &a, &b, &c, &d); //%d表示以十进位制格式输入变数a的值
    max=max_4(a,b,c,d);//调用max_4函数，得到4个数中的最大者，赋给变量max
    printf("max=%d\n",max);
    return 0;
}
