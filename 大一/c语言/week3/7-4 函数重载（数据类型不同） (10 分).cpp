#include <stdio.h>
#include <iostream>
using namespace std;
void Sort(int n,double b[n]){
    int i,j;
    double min;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++) {
            if (b[j] < b[j + 1]) {
                min = b[j];
                b[j] = b[j + 1];
                b[j + 1] = min;
            }
        }
    }
}
void Sort(int n,int a[n]){
    int i=0,j=0,min;
    for(;i<n-1;i++){
        for(j=0;j<n-1-i;j++) {
            if (a[j] < a[j + 1]) {
                min = a[j];
                a[j] = a[j + 1];
                a[j + 1] = min;
            }
        }
    }
}
int main(){
    int i=0,n;
    scanf("%d",&n);
    int m=n,a[m];
    double b[m];
    for(;i!=n;i++)
        scanf("%d",&a[i]);
    for(i=0;i!=n;i++)
        scanf("%lf",&b[i]);
    Sort (n,a);
    Sort (n,b);
    for(i=n-1;i>=0;i--)
        printf("%d ",a[i]);
    printf("\n");
    for(i=n-1;i>=0;i--)
        printf("%.2f ",b[i]);
    return 0;
}

