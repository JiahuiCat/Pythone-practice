/* eg 7.9打印乘法口诀
在乘法口诀表中有行和列线的相乘得出乘法结果。
*/
#include<stdio.h>
int main(){
    int iRow,iColum;//定义整型变量
    for(iRow=1;iRow<=9;iRow++){
        printf("%d",iRow);

        for(iColum=1;iColum<=iRow;iColum++){//根据iRow,iColum进行iRow循环次数
            printf("%d*%d=%d", iRow, iColum, iRow * iColum);
        }
        printf("\n");
    }
    return 0;
}