//本题要求实现一个拆分实数的整数与小数部分的简单函数。
//函数接口定义：
//void splitfloat( float x, int *intpart, float *fracpart );
//其中x是被拆分的实数（0≤x<10000），*intpart和*fracpart分别是将实数x拆分出来的整数部分与小数部分。
//输入样例：
//2.718
//输出样例：
//The integer part is 2
//The fractional part is 0.718
#include <stdio.h>
void splitfloat( float x, int *intpart, float *fracpart );
int main()
{
    float x, fracpart;
    int intpart;
    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);
    return 0;
}
/* 你的代码将被嵌在这里 */
void splitfloat( float x, int *intpart, float *fracpart ){
    int i=0,y=x;
    *intpart=(int)y;
    *fracpart=x-*intpart;
    return;
}