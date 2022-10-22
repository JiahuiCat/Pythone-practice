/* eg 7.2 使用while循环语句为用户提供菜单显示
在使用程序时，根据程序的功能会有许多选项,为了使用户可以方便地观察到菜单的选项，要将其菜单进行输出。
在本实例中，利用while循环语句将菜单进行循环输出，这样可以使用户更为清楚地知道每一项选项所对应的操作。
 */
#include<stdio.h>

int main(){
    int iSelect=1;//定义变量,表示菜单的选项

    while (iSelect!=0)
    {
        /* 显示菜单内容 */
        printf("------Menu------\n");
        printf("----Sell----1\n");
        printf("----Buy-----2\n");
        printf("-ShowProduct-3\n");
        printf("---0-Out-----0\n");

        scanf("%d",&iSelect);//输入菜单的选项
        switch (iSelect)
        {
        case 1://选项第一项菜单的情况
            printf("You are buying something into store\n");
            break;

        case 2: //选项第二项菜单的情况
            printf("You are selling to consumer\n");
            break;

        case 3: //选项第三项菜单的情况
            printf("Checking the store\n");
            break;

        default:
            break;
        }
    }
    
}