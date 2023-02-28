//读入n个整数，调用max_min()函数求这n个数中的最大值和最小值。
//输入格式:
//输入有两行：
//第一行是n值；
//第二行是n个数。
//输出格式:
//输出最大值和最小值。
//输入样例:
//在这里给出一组输入。例如：
//5
//8 9 12 0 3
//输出样例:
//在这里给出相应的输出。例如：
//max = 12
//min = 0
#include <stdio.h>
int main(){
    int n,i=0;
    scanf("%d",&n);
    int a[n];
    while(i<n) scanf("%d",&a[i++]);
    int max_min(int *a,int n);
    max_min(a,n);
    return 0;
}
int max_min(int *a,int n){
    int i,j,max;
    for(i=n;i!=0;i--) {
        for (j = 1; j != i; j++) {
            if (a[j-1] > a[j]) {
                max=a[j-1];
                a[j - 1] = a[j];
                a[j] = max;
            }
        }
    }
    printf("max = %d\nmin = %d",a[n-1],a[0]);
    return 0;
}