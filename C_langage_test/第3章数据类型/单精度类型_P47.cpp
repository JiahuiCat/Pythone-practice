#include<stdio.h>

/* 单精度类型 */
/* int main(){
    float fFloatStyle;
    fFloatStyle=1.23f;
    printf("%f\n",fFloatStyle);
} */

/* 双精度类型 */
/* int main(){
    double dDoubleStyle;定义变量为双精度类型
    dDoubleStyle=61.458; 赋值 
    printf("%d\n",dDoubleStyle);
    return 0;
} */

/* 长双精度类型 */
int main(){
    long double fLongDouble;
    fLongDouble=4.25;
    printf("%f\n",fLongDouble);/* 注意格式字符为%f */
    return 0;/* 这程序有问题，在VSCode上输出的结果为 -0.0000 */
}

