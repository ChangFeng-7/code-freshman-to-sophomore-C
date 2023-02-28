#include <stdio.h>
struct complex{
    int real;
    int imag;
};
struct complex multiply(struct complex x, struct complex y);
int main()
{
    struct complex product, x, y;
    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n",
           x.real, x.imag, y.real, y.imag, product.real, product.imag);
    return 0;
}
/* 你的代码将被嵌在这里 */
struct complex multiply(struct complex x, struct complex y){
//    (a+bi) (c+di)=ac+adi+bci+bdi 2 = (ac－bd)+ (bc+ad)i
     int a=x.real,b=x.imag,c=y.real,d=y.imag;
     struct complex fanhui;
     fanhui.real=(a*c-b*d);
     fanhui.imag=(b*c+a*d);
     return fanhui;
}