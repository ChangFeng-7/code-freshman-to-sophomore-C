#include <stdio.h>
#define N 5
float Fun(  int *p, int n,int *max);
int main()
{
    int a[10],i,max;
    int *pa=a;
    float ave;
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    ave=Fun(pa,N,&max);
    printf("max=%d,average=%.2f",max,ave);
    return 0;
}
/* 请在这里填写答案 */
float Fun(  int *p, int n,int *max){
    float sum;
    int i;
    for(i=0,*max=*p,sum=0;i!=n;i++,p++){
        if(*max<*p)
            *max=*p;
        sum+=*p;
    }
    return sum/n;
}