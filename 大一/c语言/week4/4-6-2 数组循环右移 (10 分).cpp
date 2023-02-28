#include <stdio.h>
#define MAXN 10
void ArrayShift(int a[], int n, int m);
int main() {
    int a[MAXN], n, m;
    int i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ArrayShift(a, n, m);
    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
//其中a[]是用户传入的数组；n是数组的大小；m是右移的位数。
void ArrayShift( int a[], int n, int m ){
    int i,j,b[n];
    if(m<=n){
        L1:for(i=0;i+m!=n;i++){
        b[i+m]=a[i];
    }
        for(j=0;j<m;j++,i++)
            b[j]=a[i];
        for(i=0;i!=n;i++)
            a[i]=b[i];
        return;
    }
    else{
        for(;m>n;m=m-n);
        goto L1;
    }
}