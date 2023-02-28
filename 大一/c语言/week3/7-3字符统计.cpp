#include <iostream>
#include <string>
using namespace std;
//字符统计
int main(){
    int n1=0, n2=0, n3=0, n4=0, n5=0;
    string s;
    getline(cin,s);
    for (auto e : s) {
        if(isdigit(e)) ++n1;
        else if(isalpha(e) && e<='Z' && e>='A') ++n2;
        else if(isalpha(e) && e<='z' && e>='a') ++n3;
        else if(e ==' ') ++n4;
        else ++n5;
    }
    cout<<"n1="<<n1<<"  "
        <<"n2="<<n2<<"  "
        <<"n3="<<n3<<"  "
        <<"n4="<<n4<<"  "
        <<"n5="<<n5<<endl;
    return 0;
}