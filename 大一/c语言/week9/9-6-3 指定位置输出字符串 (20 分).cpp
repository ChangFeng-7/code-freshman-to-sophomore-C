#include <stdio.h>
#define MAXS 10
char *match( char *s, char ch1, char ch2 );
int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
//ָ��λ������ַ���
char *match( char *s, char ch1, char ch2 ){
    char *m;
    int i=0;
    while(s[i]!=ch1&&s[i]!='\0'){
        i++;
    }
    m=&s[i];
    while(s[i]!=ch2&&s[i]!='\0'){
        printf("%c",s[i++]);
    }
    if(s[i]!='\0') printf("%c\n",s[i]);
    else printf("\n");
    return m;
}