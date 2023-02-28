//输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），组成一个新的表示十六进制数字的字符串，然后将其转换为十进制数后输出。如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。
//输入格式:
//输入在一行中给出一个以#结束的非空字符串。
//输出格式：
//在一行中输出转换后的十进制数。题目保证输出在长整型范围内。
//输入样例：
//+-P-xf4+-1!#
//输出样例：
//-3905
#include <stdio.h>
#include <math.h>
int main(){
    int i,n=0,j,x;
    double m;
    bool t=0;
    char a[100],b[100];
    a[0]=getchar();
    while(a[n]!='#'){
        scanf("%c",&a[++n]);
    }
    for(i=0;i!=n;i++){
        if((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='F')||(a[i]>='a'&&a[i]<='f'))
            break;
    }
    i-=1;
    for(j=0;j!=i;j++){
        if(a[j]=='-') t=1;
    }
    for(i=0,j=0;i!=n;i++){
        if((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='F')||(a[i]>='a'&&a[i]<='f'))
            b[j++]=a[i];
    }
    m=j-1;
    long int sum=0;
    for(i=0;i<=j-1;i++){
        if(b[i]<='9'&&b[i]>='0')
            x=(b[i]-'0')*((int)pow(16,m--));
        else {
            if (b[i] <= 'f' && b[i] >= 'a')
                x = (b[i] - 'a' + 10) * ((int) pow(16, m--));
            else
                x = (b[i] - 'A' + 10) * ((int) pow(16, m--));
        }
        sum+=x;
    }
    if(t&&sum!=0)
        printf("-%ld",sum);
    else
        printf("%ld",sum);
    return 0;
}