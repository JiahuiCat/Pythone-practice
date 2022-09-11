#include <stdio.h>

/* if...else语句形式
if-else可以指定在条件为真时执行某些语句外，还可以在条件为假时执行另外一段代码。

if(表达式)
    语句块1;
else
    语句块2;

*/
int main()
{
    int iNumber;                                        /* 定义变量*/
    printf("Enter a number\n");                         /* 输出提示信息 */
    scanf("%d", &iNumber);                              /* 输入数字 */
    if (iNumber)                                        /* 判断变量的值 */
    {
        printf("the Value is true and the number is:%d\n",iNumber); /* 判断为真时执行输出 */
    }
    else /* 不需要添加判断条件,判断结果为假时输出语句 */
    {
        printf("the Value is false and the number is:%d\n", iNumber);
    }
    return 0;
}


