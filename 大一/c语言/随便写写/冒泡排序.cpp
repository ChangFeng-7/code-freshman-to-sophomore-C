//在这里写一个冒泡排序
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],i,j,max;
    for(i=0;i!=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i!=0;i--) {
        for (j = 1; j != i; j++) {
            if (a[j-1] > a[j]) {
                max=a[j-1];
                a[j - 1] = a[j];
                a[j] = max;
            }
        }
    }
    for(i=0;i!=n;i++)
        printf("%d ",a[i]);
    return 0;
}