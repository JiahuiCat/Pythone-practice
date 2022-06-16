/* example 8.14有两个字符串:字符串a的内容为""I am a teacher." 字符串b的内容为""You are a student"
要求把字符串b连接到字符串a的后面.字符串a的内容为""I am a teacher.You are a student."
resolves:
定义连个指针变量分别指向字符串a和b的首字符;
(2)使第一指针变量指向字符串a的末尾'\0'处；
(3)从第一个指针变量指向的元素处开始，将字符串b中的字符逐个复制到字符数组a中。用一个函数来实现字符串连接的功能
 */
#include<stdio.h>
int main(){
    void link_string(char * arrl,char * arr2);/* 函数声明 */
    char a[40]="I am a teacher.";//定义a为字符指针变量，指向一个字符串
    char b[]="You are a student.";//定义b为字符数组，内放一个字符串
    char * pl=a, * p2=b;//字符指针变量p指向字符数组b的首元素
    printf("string a:%s\nstring b:%s\n",p1,p2);//输出连接前的字符串
    link_string(p1,p2);//调用link_string函数，指针变量作形参
    printf("Now,\nstring a:%s\nstring b:%s\n",a,b);//输出连接后的字符串
    return 0;
}
    void link_string(char * arrl,char * arr2){//形参时字符指针变量
        int i;
        for(i=0;*arrl!='\0';i++)
            arrl++;//将指针变量指向'\0'
        for(;*arr2!='\0';arrl++,arr2++)//只要arr2串没结束就复制到arrl中
            *arrl=*arr2;
        *arrl='\0';//在复制完后加一个'\0'
    }