//本题要求编写一个解密英文藏头诗的程序。建议使用动态内存分配方法处理字符串的输入。
//输入格式:
//输入为一首英文藏头诗，每句一行，小于20行，每行不超过80个字符，以#作为藏头诗的输入结束标志。
//输出格式:
//取出每句的第一个字符，连接在一起形成一个字符串并输出。
//输入样例:
//I come into a dream
//Leaves fall down but spring
//over a lake birds flying
//village have its nice morning
//everywhere can feel happiness
//Years have never been
//owners don't need anything
//until the sun bring another wind
//#
//输出样例:
//ILoveYou
#include <stdio.h>
int main(){
    char s[20][80];
    int i=0;
    scanf("%s\n",s[0]);
    for(i=1;s[i][0]!='#';i++){
        scanf("%s\n",s[i]);
    }
    int n=i;
    for(i=0;i<n;i++){
        printf("%c",s[i][0]);
    }
    return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//    char str[90];
//    int i,n=0;
//    gets(str);
//    while(str[0]!='#'){
//        printf("%c",str[0]);
//        gets(str);
//    }
//    return 0;
//}