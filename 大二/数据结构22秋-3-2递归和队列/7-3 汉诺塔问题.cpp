#include <iostream>
using namespace std;
void move(int n,char a,char b){
    printf("No.%d disk: %c->%c\n",n,a,b);
}
void hannoi(int n,char a,char b,char c){
    if(n==1){
        move(n,a,c);
        return;
    }else{
        hannoi(n-1,a,c,b);
        move(n,a,c);
        hannoi(n-1,b,a,c);
    }
}
int main(){
    int n;
    char a='a',b='b',c='c';
    cin>>n;
    hannoi(n,a,b,c);
    return 0;
}