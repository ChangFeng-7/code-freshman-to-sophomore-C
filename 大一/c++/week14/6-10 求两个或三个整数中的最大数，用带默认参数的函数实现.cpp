#include <iostream>
using namespace std;
int main()
{

    int max( int a,int b,int c=0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"max(a,b,c)="<<max(a,b,c)<<endl;
    cout<<"max(a,b)="<<max(a,b)<<endl;
    return 0;
}
/* 请在这里填写答案 */
int max(int a,int b,int c){
    if(a>=b&&a>=c){ return a; }
    if(b>=a&&b>=c){return b; }
    else return c;
}