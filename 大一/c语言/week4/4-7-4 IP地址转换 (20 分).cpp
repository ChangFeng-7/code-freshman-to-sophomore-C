//一个IP地址是用四个字节（每个字节8个位）的二进制码组成。请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。
//输入格式：
//输入在一行中给出32位二进制字符串。
//输出格式:
//在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。
//输入样例：
//11001100100101000001010101110010
//输出样例：
//204.148.21.114
//IP地址转换
#include <stdio.h>
#include <math.h>
int main(){
    char a[32];
    int i,j,sum=0;
    for(i=0;i<=32;i++){
        scanf("%c",&a[i]);
    }
    for(i=0,j=7;i<=31;i++){
        sum+=(a[i]-'0')*((int)pow(2,j--));
        if(j==-1) {
            j = 7;
            printf("%d",sum);
            if(i!=31)
                printf(".");
            sum=0;
        }
    }
    return 0;
}