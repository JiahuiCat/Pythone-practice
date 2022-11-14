/* 8.1  一维数组的定义和引用
一维数组的定义

一维数组用以存储一维数列中数据的集合。其一般形式:
    类型说明符 数组标识符[常量表达式]
        类型说明符表示数值中所有元素的类型
        数组标识符表示该数组型变量的名称，命名规则与变量名一致。
        常量表达式定义数组中存放的数据元素个数，即数组长度. eg. iArrage[5],5表示数组中有5个元素，下标从0开始，到4结束
    定义一个数组:
        int iArrage[5];
    int为数组元素数据类型,而iArrage为数组变量名，括号中的5为数组中包含的元素个数。

        注意:在数组iArrage[5]中，只能使用iArrage[0],...不能使用iArrage[5],则会出现下标越界的错误。

一维数组的引用   

引用数组元素的方式使用该数组中的元素。数组元素的一般表示形式:
    数组表示符[下标]
    eg.引用一个数组变量iArrage中的第3个变量:
    iArrage[2];
        数组的下标从0开始，所以下标为2表示为第3个数组元素。

        注意下标可以是整型常量或整型表达式。
*/

/* eg. 8.1使用数组保存数据。 使用数组保存用户输入的数据，当输入完毕后逆向输出数据。*/
#include<stdio.h>

int main(){
    int iArrage[5],index,temp;//定义数组及变量为基本整型
    printf("Please enter a Array:\n");

    for (index = 0; index<5; index++) // 逐个输入数组元素
    { 
        scanf("%d",&iArrage[index]);
    }

    printf("Original Array is:\n");//显示数组中的元素

    for(index=0;index<5;index++){
        printf("%d",iArrage[index]);
    }
    printf("\n");

    for(index=0;index<2;index++){//将数组中元素的前后位置互换
        temp=iArrage[index];//元素位置互换的过程借助中间变量temp
        iArrage[index]=iArrage[4-index];
        iArrage[4-index]=temp;
    }
    printf("Now Array is:\n");

    for (index = 0; index < 5; index++)
    {
        printf("%d",iArrage[index]);
    }
    printf("\n");
    return 0;
}

