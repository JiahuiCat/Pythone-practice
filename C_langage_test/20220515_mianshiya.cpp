#include<stdio.h>
int main(){
    int a,b,x;
    a=1;
    b=2;
    x=0;
    if(!(--a))
        x--;  //--a的结果是0，!0的结果是1，所以第一个if满足条件,x--;此时x为-1
    if(!b)x=7;//!b的结果是0,所以第二个if不满足条件,执行else ++x所以 x为0
        else ++x;
        printf("%d",x);
}