//图书使用国际标准书号（International Standard Book Number (ISBN-10)）来编码，是一个 10 位码。前 9 位（0−9之间的数字）
// 分别用于表示语言、出版商和 图书信息。第 10 位是校验位，可以是0−9之间的数字或者是字母 X （用于表示数字10）；
//将求和的结果对11取余数，如果余为0，则说明该ISBN-10码是一个有效码，否则，就不是一个有效的ISBN-10码。
//现输入一批ISBN-10图书编码，请你验证该编码是否是有效的国际标准书号
//输入格式:
//输入第一行给出正整数N（≤10）是输入的ISBN-10图书编号的个数。随后N行，每行给出1个10位的ISBN-10图书编号。
//输出格式:
//按照输入的顺序每行输出1个有问题的ISBN-10编码。这里并不检验前9位是否合理，只检查前9位是否全为数字且最后1位校验码计算准确。
// 如果所有号码都正常，则输出 All passed。
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int main ()
//{
//    int n;
//    cin>>n;
//    bool a=1;
//    for(int i=0;i<n;i++){
//        string s;
//        bool b=1;
//        int sum=0;
//        cin>>s;
//        for(int j=0;j<10;j++)
//        {
//            if(s[j]>='0' && s[j]<='9')
//                sum+=(s[j]-'0')*(j+1);
//            else if(s[j]=='X' && j==9)
//                sum+=100;
//            else
//            {cout<<s<<endl;a=b=0;break;}
//        }
//        if(b)
//            if(sum%11!=0)
//            {a=0;cout<<s<<endl;}
//    }
//    if(a) cout<<"All passed";
//    return 0;
//}
#include <stdio.h>
//ISBN-10
int main(){
    int i,n;
    bool c=1;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        bool b=1;
        char a[20];
        scanf("%s",a);
        int j,sum=0;
        for(j=0;j<=9&&b==1;j++){
            if(a[j]-'0'<=9&&a[j]-'0'>=0){
                sum+=(a[j]-'0')*(j+1);
            }
            else{
                if(j!=9) b=0;
            }
        }
        if(a[9]=='X') sum+=100;
        if(b==0||sum%11!=0){
            puts(a);
            c=0;
        }
    }
    if(c==1) printf("All passed");
}