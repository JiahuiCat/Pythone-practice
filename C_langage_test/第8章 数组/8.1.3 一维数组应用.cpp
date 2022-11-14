/* 8.1.3 一维数组的应用

eg. 8.5使用数组保存学生姓名
要使用数组保存学生的姓名，那么数组中的每一个元素都应该是可以保存字符串的类型，这里使用字符指针类型。
 */
#include<stdio.h>

int main(){
    char*iArrayName[5];//字符指针数组
    int index;//循环控制变量
    iArrayName[0]="One";//为数组元素赋值
    iArrayName[1]="Two";
    iArrayName[2]="Three";
    iArrayName[3]="Four";
    iArrayName[4]="Five";
    for (index=0;index<5;index++)
    {
        printf("%s\n",iArrayName[index]);
    }
    return 0;
}
/*程序分析:char*iArrayName[5]定义一个具有5个字符指针元素的数组，
然后利用每个元素保存字符串，使用for循环将其中数组保存的字符串数据进行输出 */