/* 6.2.3 else if语句形式
利用if和else关键字的组合可以实现else if语句，这是对一系列互斥的条件进行检验，形式为

if(表达式1) 语句1
else if(表达式2) 语句2
else if(表达式3) 语句3
...
else if(表达式 m) 语句m
else 语句n

eg1
if(Selection ==1)
    {...}
else if(iSelection ==2)
    {...}
else if(iSelection ==3)
    {...}
else
    {...}

代码解析:使用if语句判断变量iSelection的值是否为1，如果为1，则执行后面语句快中的内容，然后跳过后面的else if判断和else语句的执行
:如果iSelection的值不为1，那么else if判断iSelection的值是否为2，如果值为2，则条件为真，执行后面紧跟着的语句快，执行完后跳过后面
else if和else的操作:如果iSelection的值也不为2，那么接下来的else if语句判断iSelection是否等于数值3，如果等于，则执行后面语句块中的内容，
否则执行else语句块中的内容。也就是，当前面所有的判断都不成立(为假值)时，才执行else语句块中的内容。

*/

/*使用else if语句编写屏幕菜单程序。
既然要对菜单进行选择，那么首先要显示菜单。利用格式输出函数将菜单中所有的信息进行输出。
*/

#include<stdio.h>

int main(){
    int iSelection;/* 定义变量，表示菜单的选项 */
    printf("Menu\n");
    printf("1= load\n");
    printf("2=Save\n");
    printf("3=Open\n");
    printf("other = Quit\n");
    printf("enter Selection\n");/* 提示信息 */
    scanf("%d", &iSelection);/* 用户输入选项 */
    if(iSelection ==1)/* 选项为1 */
    {
        printf("Processing load\n");
    }
    else if(iSelection ==2)/* 选项为2 */
    {
        printf("Processing Save\n");
    }
    else if(iSelection ==3)/* 选项为3 */
    {
        printf("Processing Open\n");
    }
    else/* 当数值为其他数值时 */
    {
        printf("Processing Quit\n");
    }
    return 0;
}
/* 程序解析：1)printf函数输出选择的菜单显示输出
            2)假设输入的数字为3，变量iSelection将输入的数值保持，用来执行后续判断 
            3)判断iSelection，使用if语句判断iSelection是否等于1，使用else if语句判断iSelection等于2和等于3的情况，
            若不满iSelection的条件，则执行else处的语句。因为iSelection的值为3，
            所以iSelection ==3关系表达式为真，执行相应else if处的语句块，输出提示信息*/
