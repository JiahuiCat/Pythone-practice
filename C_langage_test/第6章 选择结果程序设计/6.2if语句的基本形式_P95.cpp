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
    return 0;
}
