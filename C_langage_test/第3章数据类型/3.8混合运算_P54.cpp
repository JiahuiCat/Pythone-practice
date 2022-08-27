#include<stdio.h>
/* 不同类型之间可以进行运算，不同类型的数据要先转换成同一类型，然后再进行运算。 */
/* eg13.混合运算
在本实例中，将int型变量与char变量，float型变量进行相加，将其结果存放在double类型的result变量中，最后使用printf函数将其输出。 */

 int main(){
    int int1=1;/* 定义整型变量 */
    char cChar='A';/* ASCII码为65 */
    float fFloat=2.2f;/* 定义单精度整型变量 */
    double result=int1+cChar+fFloat;/* 相加得到的结果 */
    printf("%f\n",result);/* 显示变量值 */
    return 0;
 }