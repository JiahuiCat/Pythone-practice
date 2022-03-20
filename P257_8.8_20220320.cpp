/* example 8.8 将数组a中n个整数按相反顺序存放

    resolve:将a[0]与a[n-1]对换，再将a[1]与a[n-2]对换... ...直到将a[int(n-1)/2]与a[n-int((n-1)/2)-1]对换.
        循环处理此问题,设两个""位置指示变量"i和j,i的初值为0，j的初值为n-1.将a[i]与a[j]交换,然后使i的值加1，j的值减1，再将a[i]与a[j]对换,
        直到i=(n-1)/2为止。
 */
#include <stdio.h>
void inv(int x[ ],int n){//形参x是数组名
    int temp,i,j,m=(n-1)/2;
    for(i=0;i<=m;i++){
        j=n-1-i;
        temp=x[i];
        x[i]=x[j];
        x[j]=temp;
    }
    return;
}

int main(){
    void inv(int x[],int n);
    int i,a[10]={3,7,9,11,0,6,7,5,4,2};
    printf("The original array:\n");
    for(i=0;i<10;i++)
        printf("%d",a[i]);
        printf("\n");
        inv(a,10);
        printf("The array has been inverted:\n");
        for(i=0;i<10;i++)
            printf("%d",a[i]);
        printf("\n");
        return 0;
}