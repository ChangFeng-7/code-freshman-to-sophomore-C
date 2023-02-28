#include <stdio.h>
char *getmonth( int n );
int main()
{
    int n;
    char *s;
    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);
    return 0;
}
/* 你的代码将被嵌在这里 */
char *getmonth( int n ){
    int type=n;
    char *month[] = {"January","February","March","April",
                     "May","June","July","August","September","October",
                     "November","December"};
    switch(type){
        case 1:return month[0];
        case 2:return month[1];
        case 3:return month[2];
        case 4:return month[3];
        case 5:return month[4];
        case 6:return month[5];
        case 7:return month[6];
        case 8:return month[7];
        case 9:return month[8];
        case 10:return month[9];
        case 11:return month[10];
        case 12:return month[11];
        default:return NULL;
    }
}