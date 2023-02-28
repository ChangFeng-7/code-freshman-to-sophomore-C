//本题要求实现一个简单函数，找出两个数中的最大值。
//函数接口定义：
//void findmax( int *px, int *py, int *pmax );
//其中px和py是用户传入的两个整数的指针。函数findmax应找出两个指针所指向的整数中的最大值，存放在pmax指向的位置。
//输入样例：
//3 5
//输出样例：
//5
#include <stdio.h>
void findmax( int *px, int *py, int *pmax );
int main()
{
    int max, x, y;
    scanf("%d %d", &x, &y);
    findmax( &x, &y, &max );
    printf("%d\n", max);
    return 0;
}
/* 你的代码将被嵌在这里 */
void findmax( int *px, int *py, int *pmax ){
    int max;
    if(*px>*py) max=*px;
    if(*px<*py) max=*py;
    *pmax=max;
}