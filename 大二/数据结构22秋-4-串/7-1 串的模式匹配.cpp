#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str1[1000005],str2[1000005];
    int  i,n;
    gets(str1);
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(str2);
        char *p=strstr(str1,str2);
        if(p!=NULL)
        {
            for( ;*p!='\0';p++)
                printf("%c",*p);
            printf("\n");
        }
        else
            printf("Not Found\n");
    }
    return 0;
}