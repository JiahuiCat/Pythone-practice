#include<stdio.h>
/* 13.下述程序段的输出结果是

 */
/* int main(){
    int a=2,b=3,c=4,d=5;
    int m=2,n=2;
    a=(m=a>b)&&(n=c>d)+5;
    printf("%d,%d",n,a);
} */
//13，输出结果是2,0

/* 31.以下程序的运行后的输出结果是

 */
/* int main(){
    int a=1,b=0;
    if(--a) b++;//因为if(--a) 所以a=0
    else if(a==0) b+=2;
    else b+=3;
    printf("%d\n",b);
} */
/* a--跟--a都是自减，如果放在运算中或逻辑判断中--a先执行自减，再参与运算或判断 */

/* 32.下列条件语句中，输出结果与其他语句不同的是
 */
/* int main(){
    if(a) printf("%d\n",x);else printf("%d\n",y);
    if(a==0) printf("%d\n",y);else printf("%d\n",x);
    if(a!=0) printf("%d\n",x);else printf("%d\n",y);
    if(a==0) printf("%d\n",x);else printf("%d\n",y);
} */
/* a等于0，它输出x,其他几个都是a不等于0,才输出a */

/*7.2.3怎样调用函数
定义函数的目的是为了用这个函数，因此要学会正确使用函数。
1.调用无参函数的形式 
调用有参函数的形式
函数名（实参表例）
例7.2     输入两个整数，求输出二者中的大者。要求在主函数中输入两个整数，用一个函数max求出其中的大者，并在主函数中输出此值。

解题思路:要求用一个max函数来实现比较两个整数，并将得到的大数带回主函数。
显然，两个整数中的大者也应该是整数，因此max函数应当是int型。
两个数是在主函数中输入的，在max函数中进行比较，因此应该定义为有参函数，在函数调用时进行数据的传递。
 */
int main(){
    int max(int x,int y);//max函数声明，表示在main函数中将要调用max函数
    int a,b,c;
    printf("please input two number:");
    scanf("%d,%d",&a,&b);//输入两个整数
    c=max(a,b);//调用max函数，得到一个值，赋给c
    printf("max is %d\n",c);//输出c的值就是两个整数中的大者
    return 0;
}
 int max(int x,int y)//定义max函数，函数类型为int型，两个参数为int型
 {
     int z;//变量z用来存放两个整数中的大者，int型
     if(x>y)
         z = x; //如果x大于y，将变量x输出给变量int型 z
    else 
        z=y;//否则将变量y输出给变量 int型 y
    return(z);//返回输出z的值
 }