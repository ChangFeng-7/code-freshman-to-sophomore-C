//本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。
//输入格式：
//输入是一个以回车结束的非空字符串（少于80个字符）。
//输出格式：
//输出去重排序后的结果字符串。
//输入样例：
//ad2f3adjfeainzzzv
//输出样例：
//23adefijnvz
#include <stdio.h>
#include <string.h>
//void re(char *s,int j);
//int main(){
//    string s;
//    cin>>s;
//    int i,j;
//    for(i=0,j=0;s[i]!='/0';i++){
//        for(j=i+1;s[j]!='/0';j++){
//            if(s[j]==s[i])
//                re(s,j);
//        }
//    }
//    for(i=0;s[i]!='/n';i++){
//        for(j=)
//    }
//    cout<<s;
//    return 0;
//}
//void re(char *s,int j){
//    int i;
//    for(i=j+1;s[j]!='/0';j++)
//        s[i++]=s[j];
//}
//先排序再去重：
int main(){
    char s[100]={0};
    int i,j,n;
    for(n=0;s[n]!='\n';n++) {
        scanf("%c", &s[n]);
    }
    return 0;
}
//利用数组赋值自动使其排序
#include<iostream>
using namespace std;
int cha[300];
int main(){
    char c;
    c=getchar();
    while(c!='\n'){
        cha[c]=1;
        c=getchar();
    }
    for(int i=0;i<128;i++){
        if(cha[i]>0){
            printf("%c",i);
        }
    }
    return 0;
}