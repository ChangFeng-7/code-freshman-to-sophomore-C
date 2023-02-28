//本题要求实现一个删除字符串中的指定字符的简单函数。
//函数接口定义：
//void delchar( char *str, char c );
//其中char *str是传入的字符串，c是待删除的字符。函数delchar的功能是将字符串str中出现的所有c字符删除。
//输入样例：
//a
//happy new year
//输出样例：hppy new yer
#include <stdio.h>
#define MAXN 20
void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */
int main()
{
    char str[MAXN], c;
    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);
    return 0;
}
/* 你的代码将被嵌在这里 */
void delchar( char *str, char c ){
    scanf("%c",&c);
    gets(str);
    int i,j;
    for(i=j=0;str[i]!='\0';i++){
        if(str[i]!=c){
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}
