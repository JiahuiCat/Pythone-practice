/* 代码缩进统一为4个字符 */
#include<stdio.h>
int main(){/* 主函数 */
    int iResult=0;/* 定义变量 */
    int i;
    printf("The result of going from 1 to 100 is :");/* 由1加到100的结果是 输出语句 */
    for(i=1;i<100;i++){
        iResult=i+iResult;
    }
    printf("%d\n",iResult);/* 输出结果 */
    return 0;/* 结果返回 */
}