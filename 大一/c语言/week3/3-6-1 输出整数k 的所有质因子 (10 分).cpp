#include <stdio.h>
int fun(int n );
int main()
{
    int j, k;
    scanf( "%d", &k );
    for( j = 2; j <= k; j++ )
        if( ( !( k%j ) )&&(fun( j ) ) ) printf( "%4d", j );
    printf("\n");
    return 0;
}
/* 请在这里填写答案 */
int fun(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i ==0) {
            return 0;
        }
    }
    return 1;
}
//输出一个整数k (2≤k≤5000)的所有质因子（即所有为素数的因子）。例如，若输入整数：2310，则应输出：2. 3. 5. 7. 11。。
//函数接口定义：
//int fun(int n );
//其中 n 是用户传入的参数。函数判断 n 是否是素数，是须返回1，不是返回0.