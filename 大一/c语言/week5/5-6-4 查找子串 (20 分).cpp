//本题要求实现一个字符串查找的简单函数。
//函数接口定义：
//char *search( char *s, char *t );
//函数search在字符串s中查找子串t，返回子串t在s中的首地址。若未找到，则返回NULL。
//输入样例1：
//The C Programming Language
//ram
//输出样例1：10
//输入样例2：
//The C Programming Language
//bored
//输出样例2：-1
#include <stdio.h>
#define MAXS 30
//查找子串
char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */
int main()
{
    char s[MAXS], t[MAXS], *pos;
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");
    return 0;
}
char *search( char *s, char *t )（正确答案）
{
    int i,j,ans=0;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=0;t[j]!='\0';j++)
        {
            ans=0;
            if(t[j]!=s[i+j])
                break;
            else
                ans=1;
        }
        if(ans==1)
        {
            return &s[i];
        }
    }
    return NULL;
}
//char *search(char *s, char *t){
//    int m,n,i,j,x,ans,a;
//    for(m=0;t[m]!='\0';m++);//子串长度
//    for(n=0;s[n]!='\0';n++);//母串长度
//    for(j=0,i=0;j<=n-1;j++){
//        if(s[j]==t[i]){
//            for(x=j,a=j,ans=1;i<=m-1,ans!=0;i++,x++){
//                if(t[i]!=s[x])
//                    ans=0;
//            }
//            if(ans)
//                break;
//        }
//    }
//    if(ans==0)
//        return &s[a-m+1];
//    return NULL;
//}
//void ReadString( char s[] ){
//    gets(s);
//}