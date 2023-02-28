//申请一个10个单元的整型数组，输入10个整数，去掉一个最大值和一个最小值后，剩下的8个数求和
//
//        输入格式:
//输入10个整数，空格分隔
//
//        输出格式:
//去掉最大值和最小值后，求剩下8个数的和
//
#include <stdio.h>
int main(){
    int a[10],max,min,i,sum=0;
    for(i=0;i!=10;i++)
        scanf("%d",&a[i]);
    for(i=0,max=a[0],min=a[0];i!=10;i++){
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    for(i=0;i!=10;i++){
        sum+=a[i];
    }
    printf("%d",sum-max-min);
    return 0;
}