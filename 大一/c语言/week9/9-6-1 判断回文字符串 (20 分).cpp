#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 20
bool palindrome( char *s );
int main()
{
    char s[MAXN];
    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);
    return 0;
}
/* 你的代码将被嵌在这里 */
//函数palindrome判断输入字符串char *s是否为回文。若是则返回true，否则返回false。
bool palindrome( char *s ){
    int i=strlen(s),j=0;
    while(i>=0){
        if(s[i-1]!=s[j]){
            return false;
        }
        i--;
        j++;
    }
    return true;
}