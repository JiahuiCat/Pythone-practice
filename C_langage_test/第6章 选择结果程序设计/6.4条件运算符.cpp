/* 6.4 if语句，可以通过判断表达式为“真”或“假”，从而执行相应的表达式。
if(a>b)
    {max=a;}
else
    {max=b}

使用条件运算符“？:”，简化以上的程序。

max=(a,b) ? a:b;
分析:首先判断表达式a>b是否成立，成立则说明结果为真，否则为假。当为真时，将a的值赋给max变量；如果为假，则将b的值赋给max变量

条件运算符可对一个表达式的值的真假情况进行检验，根据检验结果返回另外两个表达式中的一个。
条件运算符的一般形式:

表达式 1 ? 表达式 2 : 表达式 3；

分析:先对第一个表达式的值进行检验。如果值为真，则返回第二个表达式的结果值；如果值为假，则返回第3个表达式的结果值。

 */

/* 条件运算符计算欠款金额。
还欠款的时间如果过期，则会在欠款的金额上增加10%的罚款。条件运算符进行判断选择。*/
#include<stdio.h>
int main(){
    float fDues; /* 定义变量表示欠款数 */
    float fAmount;/* 表示要还的总欠款数 */
    int iOntime;/* 表示是否按时归还 */
    char cChar;/* 用来接收用户输入的字符 */

    printf("Enter dues amount\n");/* 提示输入欠款金额 */
    scanf("%f",&fDues);/* 用户输入 */
    printf("On Time? (y/n)\n");/* 显示信息，提示还款是否按时还款 */
    getchar();/* 得到回车符 */
    cChar=getchar();/* 得到输入的字符 */
    iOntime=(cChar == 'y') ? 1 : 0;/* 使用条件运算符更具字符选择进行选择操作 */
    fAmount=iOntime ? fDues : (fDues*1.1);/* 使用条件运算符根据iOntime值的真假进行选择操作 */
    printf("The Amount is : %.2f\n",fAmount);/* 将计算应还的总欠款数输出 */
    return 0;
}
/* 程序分析:
1)iOntime=(cChar == 'y') ? 1 : 0 条件运算符判断表达式 cChar == 'y'是否成立。
成立为真时，将“？”号后的值1赋给iOntime变量；不成立为假时，将0赋给iOntime变量。因为成立cChar == 'y'的表达式不成立，所以iOntime的值为0
2)使用条件运算符对iOntime的值进行判断。如果iOntime为真，则说明按时还款，还款金额为原欠款，返回fDues值给fAmount变量。若iOntime值为假，
则说明没有按时还款，要加上10%的罚金，返回表达式fDues*1.1的值给fAmount。iOntime为0，因此fAmount值为fDues*1.1的结果。
 */