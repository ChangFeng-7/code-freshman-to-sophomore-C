//本题目要求读入1个正整数n，然后编写递归函数reverse(int n)实现将该正整数逆序输出。
//输入格式:
//输入在一行中给出1个正整数n。
//输出格式:
//对每一组输入，在一行中输出n的逆序数。
//输入样例:
//12345
//输出样例:
//54321
#include <iostream>
using namespace std;
void reverse(int n);
int main(){
    int n;
    cin>>n;
    reverse(n);
    return 0;
}
void reverse(int n){
    if(n==0){
        return;
    }
    printf("%d",n%10);
    reverse(n/10);
}