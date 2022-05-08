/* 例8.11有一个字符数组a,在其中存放字符串""I am a boy",要把该字符串复制到字符数组b中。
Resolve 从第一个字符开始，将数组a中的字符逐个复制到数组b中，直到遇到a数组中的某一个元素值为'\0'为止。
        此时表示数值a中的字符串结束，然后在已复制到b数组中的字符最后加一个'\0'，表示字符串结束 */
#include<stdio.h>
int main(){
    char a[ ]="I am a boy.",b[20];
    int i;
    for(i=0;* (a+i)!='\0';i++)
        *(b+i)=*(a+i);//用地址发访问数组元素
    *(b+i)='\0';//在已复制到b数组中的字符最后加'\0',表示字符串结束
    printf("string a is :%s\n",a);
    printf("string b is :");
    for(i=0;b[i]!='\0';i++)
        printf("%c",b[i]);//用下标法访问数组元素
    printf("\n");
    return 0;
}