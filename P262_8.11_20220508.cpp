/* ��8.11��һ���ַ�����a,�����д���ַ���""I am a boy",Ҫ�Ѹ��ַ������Ƶ��ַ�����b�С�
Resolve �ӵ�һ���ַ���ʼ��������a�е��ַ�������Ƶ�����b�У�ֱ������a�����е�ĳһ��Ԫ��ֵΪ'\0'Ϊֹ��
        ��ʱ��ʾ��ֵa�е��ַ���������Ȼ�����Ѹ��Ƶ�b�����е��ַ�����һ��'\0'����ʾ�ַ������� */
#include<stdio.h>
int main(){
    char a[ ]="I am a boy.",b[20];
    int i;
    for(i=0;* (a+i)!='\0';i++)
        *(b+i)=*(a+i);//�õ�ַ����������Ԫ��
    *(b+i)='\0';//���Ѹ��Ƶ�b�����е��ַ�����'\0',��ʾ�ַ�������
    printf("string a is :%s\n",a);
    printf("string b is :");
    for(i=0;b[i]!='\0';i++)
        printf("%c",b[i]);//���±귨��������Ԫ��
    printf("\n");
    return 0;
}