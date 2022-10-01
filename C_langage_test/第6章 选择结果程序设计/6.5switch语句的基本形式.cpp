/* 6.5.1 switch语句的基本形式

switch语句是多分支选择语句。switch语句的一般形式:

switch(表达式){
    case 情况 1:
        语句块 1;
        break;
    case 情况 2:
        语句块 2;
        break;
    ...
    case 情况 n:
        语句块 n;
        break;
    default:
        默认情况语句块;
        break;
}

switch的表达式就是要进行判断的条件。
在switch的语句块中，case关键字表示检验条件符合的各种情况，其后的语句是相应的操作。
其中还有一个default关键字，作用是如果没有符合条件的情况，那么执行default后的默认情况语句。

注意:
switch语句检验的条件必须是一个整型表达式，意味着其中也可以包含运算符和函数调用。
而case语句检验的值必须是整型常量，即常量表达式或者常量运算。

 */
#include<stdio.h>
int main(){
    switch (selection)//selection形参没值。所以该程序无法执行。
    {
    case 1:
        printf("Processing Receivables\n");
        break;
    
    case 2:
        printf("Processing Payables\n");
        break;
    case 3:
        printf("Quitting\n");
        break;
    
    default:
        printf("Error\n");
        break;
    }
}
/* 程序分析：其中switch判断selection变量的值，利用case语句检验selection的值的不同情况。
假设selection的值为2，那么执行case为2时的情况，执行后跳出switch语句。
如果selection的值不是case中所检验列出的情况，那么执行default中的语句。在每一个case或default语句后都有一个break关键字。
break语句用于跳出switch结构，不在执行switch下面的代码。
 */
/* 注意:在使用switch语句时，如果没有一个case语句后面的值能匹配switch语句的条件，就执行defaul语句后面的代码，
其中，任意两个case语句都不能使用相同的常量值；每个switch结构只能有一个default语句，default可以省略。 */