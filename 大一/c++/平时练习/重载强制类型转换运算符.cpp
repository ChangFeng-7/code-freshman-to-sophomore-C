#include <iostream>
using namespace std;
class Complex{
    double real,imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){};
    operator double (){ return real; }
};
int main(){
    Complex c{1.2,3.4};
    cout<<(double)c<<endl;
    double n=2+c;//c等价于c.operator double();
    cout<<n;
}
//直接运行