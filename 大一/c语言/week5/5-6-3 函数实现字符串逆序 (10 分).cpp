//本题要求实现一个字符串逆序的简单函数。
//函数接口定义：
//void f( char *p );
//函数f对p指向的字符串进行逆序操作。要求函数f中不能定义任何数组，不能调用任何字符串处理函数。
//输入样例：Hello World!
//输出样例：!dlroW olleH
#include <stdio.h>
#define MAXS 20
void f( char *p );
void ReadString( char *s ); /* 由裁判实现，略去不表 */
int main()
{
    char s[MAXS];
    ReadString(s);
    f(s);
    printf("%s\n", s);
    return 0;
}
/* 你的代码将被嵌在这里 */
void f( char *p ){
    char a;
    int i,j,t=0;
    while(p[i]!='\0')		//计算长度
        i++;
    j=i-1;
    while(t<=j){		//实现逆序
        a=p[t];
        p[t]=p[j];
        p[j]=a;
        t++;
        j--;
    }
}