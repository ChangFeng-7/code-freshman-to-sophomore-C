//输入十进制整数N和待转换的进制x（2、8、16），分别代表十进制N转换成二进制、八进制和十六进制，输出对应的结果。十六进制中A~F用大写字母表示。
//输入格式:
//输入两个整数N（十进制整数N）和x（x进制），中间用空格隔开。
//输出格式:
//输出对应的结果。
//输入样例:
//在这里给出一组输入。例如：
//123 2
//输出样例:
//在这里给出相应的输出。例如：
//1111011
//输入样例:
//在这里给出一组输入。例如：
//123 16
//输出样例:
//在这里给出相应的输出。例如：
//7B
#include <iostream>
#include <string>
using namespace std;
int Sixteen(int N);
int eight(int N);
int two(int N);
int main(){
    int x,N;
    cin>>N>>x;
    switch(x){
        case 2:
            two(N);
            break;
        case 8:
            eight(N);
            break;
        case 16:
            Sixteen(N);
            break;
    }
    return 0;
}
int two(int N){
    int i=0;
    int a[100]={0};
    while(N){
        if(N!=1) {
            a[i++] = N % 2;
            N = N / 2;
        }else{
            a[i++]=1;
            N=0;
        }
    }
    for(int j=i-1;j>=0;j--){
        cout<<a[j];
    }
}
int eight(int N) {
    int i = 0;
    int a[100] = {0};
    while (N) {
        if (N != 1) {
            a[i++] = N % 8;
            N = N / 8;
        } else {
            a[i++] = 1;
            N = 0;
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
}
int Sixteen(int N) {
    int i = 0;
    char n;
    char a[100];
    while (N) {
        if (N != 1) {
            n = N % 16;
            if(0<=n&&n<=10){ a[i++]=n+'0'; }
            else{
                switch(n){
                    case 10:
                        n='A';
                        break;
                    case 11:
                        n='B';
                        break;
                    case 12:
                        n='C';
                        break;
                    case 13:
                        n='D';
                        break;
                    case 14:
                        n='E';
                        break;
                    case 15:
                        n='F';
                        break;
                }
                a[i++]=n;
            }
            N = N / 16;
        } else {
            a[i++] = 1;
            N = 0;
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
}