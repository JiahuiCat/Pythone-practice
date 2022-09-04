#include <stdio.h>

/* 使用if语句模拟信号灯，指挥车辆行驶.

为了模拟十字路口的信号灯指挥系统，要使用if语句判断信号灯的状态。
如果信号灯为绿色，则说明车辆可以行驶通过，通过输出语句进行信息提示，说明车辆的行动状态 
*/
int main()
{
    int iSignal;/* 定义变量表示信号灯的状态 */
    printf("the red Light is 0,the green Light is 1\n");/* 输出提示信息 */
    scanf("%d", &iSignal);                              /* 输入iSignal变量 */
    if(iSignal == 1){
        printf("the Light is green,cars can run\n");/* 判断结果为真时输出 */
    }
    if(iSignal == 0){
        printf("The Light is red,cars can't run\n");/*判断结果为假时输出语句  */
    }
    return 0;
}
/* 编码分析:要根据信号灯的状态进行判断，需要一个变量表示信号灯的状态。在程序代码中，定义变量iSignal表示信号灯的状态。
            2.输出提示信息，输入iSignal变量，表示此时信号灯的状态。此时用键盘输入"1"，表示信号灯的状态是绿灯 
            3.使用if语句判断iSignal变量的值，如果为真，则表示信号灯为绿灯:
                如果为假，则表示信号灯是红灯。则程序中，此时变量iSignal== 1条件成立，因此判断的结果为真值，从而执行if语句大括号中的语句。
    if语句可以多次使用，通过连续使用进行进一步的判断，继而根据不同的分支条件给出相应的操作。*/

/* 使用if语句，两个判断需要注意
if(value){...} //判断变量值
if(value == 0){...}//判断表达式的值 
*/