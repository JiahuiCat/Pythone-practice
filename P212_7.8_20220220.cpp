/* example7.8.   有两个班，学生数不同，编写一个函数，用来分别求各班的平均成绩。
Resolve    :用同一个函数求不同人数的班级平均成绩。规定在定义形参时不指定数组的大小，函数对不同人数的班级都是适用的
            根据用数组名作函数形参的规定，数组名传递的是数组首元素的地址，而不是数组元素。
            可以用同一个函数来求人数不同的班的平均成绩，在定义average函数时，增加一个参数n，用来指定当前班级的人数。
 */
#include<stdio.h>
float average(float array[],int n){//没有指定形参数组的大小，形参n用来接收本班人数
    int i;
    float aver,sum=array[0];//sum的初值是第一个学生的成绩
    for(i=1;i<n;i++){
        sum=sum+array[i];//将array[1]到array[n]界加到sum中
        aver=sum/n;//求平均成绩
        return(aver);//将平均成绩作为函数值带回主函数
    }
}

int main(){
    float average(float array[],int n);//对average函数的声明
    float score_1[5]={97.5,65.5,92,94,70.5};//第一班有5名学生;
    float score_2[10]={89,90,75.5,68.5,85,34,56,70,45,78};//对第二班有10学生
    printf("The average of classA is %6.2f\n",average(score_1,5));//输出第一班平均成绩
    printf("The average of classB is %6.2f\n",average(score_2,10));//输出第二班平均成绩
    return 0;
}