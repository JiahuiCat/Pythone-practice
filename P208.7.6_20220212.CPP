//数组元素作函数实参，用法与变量相同。数组名也可以作实参和形参，传递的是数组首元素的地址。

/* 用数组元素作函数实参
    数组元素可以是表达式的组成部分，数组元素作为函数的实参，传递方式是单向传递，即""值传送"
 */

/* question:两个运动队 a 和 b,各有10个队员，每个队员有一个综合成绩。将两个队的每个队员的成绩一一对应地逐个比较(a队1队员与b队1队员).
如果a队队员的成绩高于 b队相应队员成绩的数目多于 b队队员成绩高于 a队相应队员成绩的数目,则认为a队胜。统计两队队员比较成绩的结果。
 */

/* resolve:设a，b两个数组有10个元素，存放10个队员的成绩，将两个数组的相应元素逐个比较，用 3个变量 c,d,e累计a队员高于,等于和低于b队的次数
用一个函数higher来判断每个比较的结果。ifa队员高于b队员，结果为1，二者相等，结果为0；a队员低于 b队员，结果为-1.最后比较c和e得出结果。
 */

#include<stdio.h>

int higher(int x,int y){//定义higher函数
    int flag;//定义一个flag的变量
    if(x>y) flag=1;//如果x队员成绩高于y对应的队员，flag等于1
    else if(x<y) flag=-1;//否则如果x队员成绩低于y队队员，flag的值等于-1
    else flag=0;//如x队成绩等于y队员，flag的值为0
    return(flag); //返回flag的值
}

int main(){
    int higher(int x,int y);//对higher函数声明
    int a[10],b[10],i,c=0,d=0,e=0;//声明数据类型，a数组，b数组，变量i,c,d,e
    printf("enter array a:\n");
    for(i=0;i<10;i++) scanf("%d",&a[i]);//输入a队队员成绩
    printf("\n");
    
    printf("enter array b:\n");
    for(i=0;i<10;i++) scanf("%d",&b[i]);//输入b队员成绩
    printf("\n");

    for(i=0;i<10;i++) {//比较10个队员
        if(higher(a[i],b[i])==1)//如a队员成绩高于b队相应队员
            c++;//使c累加1
        else if(higher(a[i],b[i])==0)//a队员成绩等于b队相应
            d++;
        else e=e+1;
    }
    printf("b %d times \na equal to b %d times \nb higher a %d times \n",c,d,e);//输出c,d,e的值
    if(c>d) printf("a wins!\n");
    else if(c<e) printf("b wins\n");
    else printf("a is equal to b\n");
    return 0;
}
//这程序有个缺点就是当使用逗号分割需要输入的成绩的时候，无法进入输入b程序的输入栏，需要修改

