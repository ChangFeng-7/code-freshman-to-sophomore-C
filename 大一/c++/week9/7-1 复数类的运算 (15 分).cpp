#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double r=0, double i=0):real(r), imag(i){    }
    Complex operator+( Complex &c1,Complex &c2 ){
        return Complex(c1.real+c2.real,c1.imag+c2.imag);
    } const;//����˫Ŀ�����'+'
    Complex operator-=( Complex &c1,Complex &c2 ){
        return Complex(-c2.real,-c2.imag);
    }; //����˫Ŀ�����'-='
    friend Complex operator-( Complex &c1,Complex &c2  ){
        return Complex(c1.real-c2.real,c1.imag-c2.imag);
    } const;//����˫Ŀ�����'-'
    void Display() const;
private:
    double real;
    double imag;
};
void Complex::Display() const
{
    cout << "(" << real << ", " << imag << ")" << endl;
}
int main()
{
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1+c2;
    c3.Display();
    c3 = c1-c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}
