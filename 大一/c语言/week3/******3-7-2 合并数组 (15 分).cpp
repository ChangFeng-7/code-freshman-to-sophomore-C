//实验五：数组
//
//        实验目的：
//
//掌握一维数组和二维数组的定义、赋值和输入输出的方法。
//掌握字符数组和字符串函数的使用。
//题目描述
//
//        已知两个升序数组，将它们合并成一个升序数组并输出。例如：数组array1={3,6,13,35,54}，数组array2={14,19,26,32}， 合并为新的数组array={3,6,13,14,19,26,32,35,54}。
//
//输入格式:
//输入两行升序整数，当每行输入0时，表示输入结束。每行整数的个数1<=N<=10。
//
//输出格式:
//输出合并后的升序数组。（最后一个数据后有一个空格）
#include <stdio.h>
int main()
{
    int a[10];
    int b[10];
    int c[20];
    int m = 0, n = 0,l;
    while (1)
    {
        scanf("%d", &a[n]);
        if (a[n] == 0)
            break;
        else
            n++;
    }
    while (1)
    {
        scanf("%d", &b[m]);
        if (b[m] == 0)
            break;
        else
            m++;
    }
    int i=0 ,j=0 ,k=0 ;
    while (a[i]!=0||b[j]!=0)
    {
        if (a[i] > b[j])
        {
            if(b[j]==0)
                c[k++] = a[i++];
            else
                c[k++]=b[j++];
        }
        if(a[i] < b[j])
        {
            if(a[i]==0)
                c[k++] = b[j++];
            else
                c[k++]=a[i++];
        }
    }
    for (l = 0; l < m + n; l++)
        printf("%d ",c[l]);
    return 0;
}
