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
/* ��Ĵ��뽫��Ƕ������ */
//����palindrome�ж������ַ���char *s�Ƿ�Ϊ���ġ������򷵻�true�����򷵻�false��
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