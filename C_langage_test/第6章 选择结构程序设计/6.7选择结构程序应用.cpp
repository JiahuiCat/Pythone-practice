/* eg 6.14使用switch语句计算运输公司的计费
某运输公司的收费按照用户运送货物的路程进行计费。路程(s)越远，每公里运费越低，收费标准
路程 s<250        运费 没有折扣
    250<=s<500   运费  2%折扣
    500<=s<1000  运费  5%折扣
    1000<=s<2000 运费  8%折扣
    2000<=s<3000 运费  10%折扣
    3000<=s      运费  15%折扣
 */
#include<stdio.h>
int main(){
    int iDiscount;//表示折扣
    int iSpace;//表示路程
    int iSwitch;//表示折扣的检验情况
    float fPrice, fWeight, fAllPrice; //定义float类型变量，float 类型小数点后有效位的位数是 Double 的 是 15 位。
    printf("Enter the price ,weight and space\n");
    scanf("%f%f%d",&fPrice,&fWeight,&iSpace);//接受输入数据
    if(iSpace>3000){
        iSwitch=12;//折扣的检验情况为12
    }
    else
    {
        iSwitch=iSpace/250;//计算折扣的检验情况
    }
    
    switch (iSwitch)//使用多路开关模式switch进行检验
    {
    case 0:
        iDiscount=0;
        break;
    
    case 1:
        iDiscount=2;
        break;
    
    case 2:
    case 3:
        iDiscount=5;
        break;
    
    case 5:
    case 6:
    case 7:
        iDiscount=8;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        iDiscount=10;
        break;
    case 12:
        iDiscount=15;
        break;
    
    default:
        break;
    }

    fAllPrice=fPrice*fWeight*iSpace*(1-iDiscount/100.0);//计算总价格
    printf("AllPrice is :%.4f\n",fAllPrice);//输出结果
    return 0;
}
/* 程序分析:定义的变量 fPrice,fWeight和fAllPrice分别表示单价，重量和最终得到的总价格。
通过对路程执行除法得到条件，然后使用switch语句进行检验
其中需要注意的是，在计算iSwitch=iSpace/250时，由于iSwitch定义的类型为整型，所以iSwitch的值为计算后得到的整数部分。 */