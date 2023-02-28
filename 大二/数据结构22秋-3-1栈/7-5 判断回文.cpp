//回文是指正读反读均相同的字符序列，如“abba”和“abdba”均是回文，但“good”不是回文。
//试写一个程序判定给定的字符向量是否为回文，用栈实现。(提示：将一半字符入栈)
//输入格式:
//输入任意字符串。
//输出格式:
//若字符串是回文，输出：xxxx是回文。
//若字符串不是回文，输出：xxxx不是回文。
//输入样例:
//abba
//输出样例:
//abba是回文。
//输入样例:
//abdba
//输出样例:
//abdba是回文。
//输入样例:
//good
//输出样例:
//good不是回文。
#include<iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int main(){
    char a[100];
    int i=0,j=0,step=1;
    int num=0;
    for(i=0;i<100;i++){
        a[i]='\0';
    }
    i=0;
    char ch;
    while((ch=getchar())!='\n'){
        a[i++]=ch;
        num++;
    }
    if(num%2==0){
        for(i=num-1,j=num;i>0;i--,j++){
            if(a[i]!=a[j]) step=false;
        }
    }
    if(num%2!=0){
        num=(num+1)/2;
        for(i=num-2,j=num;i>=0;i--,j++){
            if(a[i]!=a[j]) step=false;
        }
    }
    i=0;
    if(step) {
        while (a[i]!='\0') {
            cout<<a[i];
            i++;
        }
        cout<<"是回文。";
        return 0;
    }
    while (a[i]!='\0') {
        cout<<a[i];
        i++;
    }
    cout<<"不是回文。";
    return 0;
}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int flag=1;
//    int i,j;
//    int len=0;
//    char a[10];
//    gets(a);
//    len=strlen(a);
//    for(i=0,j=len-1;i<len/2;i++,j--)
//    {
//        if(a[i]!=a[j])
//        { printf("%s不是回文。",a);
//            flag=0;
//            break;}
//    }
//    if(flag)
//        printf("%s是回文。",a);
//}