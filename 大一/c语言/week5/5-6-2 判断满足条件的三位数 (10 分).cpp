//本题要求实现一个函数，统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数。
//
//函数接口定义：
//int search( int n );
//其中传入的参数int n是一个三位数的正整数（最高位数字非0）。函数search返回[101, n]区间内所有满足条件的数的个数。
//输入样例：500
//输出样例：count=6
#include <stdio.h>
#include <math.h>
int search( int n );
int main()
{
    int number;
    scanf("%d",&number);
    printf("count=%d\n",search(number));
    return 0;
}
/* 你的代码将被嵌在这里 */
int search( int n ){
    double x=101;
    int count,i,a[3],num;
    for(count=0;x<=n;x++){
        if(sqrt(x)==((int)sqrt(x))){
            for(i=0,num=x;i<=2;i++){
                a[i]=num%10;
                num/=10;
            }
            if(a[0]==a[1]||a[0]==a[2]||a[1]==a[2])
                count++;
        }
    }
    return count;
}