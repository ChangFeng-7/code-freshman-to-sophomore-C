#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {};

    friend ostream &operator<<(ostream &os, const Complex &c);

    friend istream &operator>>(istream &is, Complex &c);
};

ostream &operator<<(ostream &os, const Complex &c) {
    os << c.real << "+" << c.imag << "i";
    return os;
}

istream &operator>>(istream &is, Complex &c) {//这里不能const的原因：const complex &c
    string s;                                 // 表示传递一个complex类对象的引用，但是不能改变实参的值，这里要改变实参的值
    is>>s;
    int pos=s.find("+",0);
    string sTmp=s.substr(0,pos);
    c.real=atof(sTmp.c_str());
    sTmp=s.substr(pos+1,s.length()-pos-2);
    c.imag=atof(sTmp.c_str());
    return is;
}
int main(){
    Complex c;
    int n;
    cin>>c>>n;
    cout<<c<<","<<n;
    return 0;
}
//输入13.2+133i 87
//关于s.find和其他函数的用法：https://blog.csdn.net/qq_52292442/article/details/116240426
//s.substr:https://www.cnblogs.com/xzxl/p/7243490.html#:~:text=%E5%BD%A2%E5%BC%8F%EF%BC%9As.substr%20%28pos%2C%20n%29%202.,%E8%A7%A3%E9%87%8A%EF%BC%9A%E8%BF%94%E5%9B%9E%E4%B8%80%E4%B8%AAstring%EF%BC%8C%E5%8C%85%E5%90%ABs%E4%B8%AD%E4%BB%8Epos%E5%BC%80%E5%A7%8B%E7%9A%84n%E4%B8%AA%E5%AD%97%E7%AC%A6%E7%9A%84%E6%8B%B7%E8%B4%9D%EF%BC%88pos%E7%9A%84%E9%BB%98%E8%AE%A4%E5%80%BC%E6%98%AF0%EF%BC%8Cn%E7%9A%84%E9%BB%98%E8%AE%A4%E5%80%BC%E6%98%AFs.size%20%28%29%20-%20pos%EF%BC%8C%E5%8D%B3%E4%B8%8D%E5%8A%A0%E5%8F%82%E6%95%B0%E4%BC%9A%E9%BB%98%E8%AE%A4%E6%8B%B7%E8%B4%9D%E6%95%B4%E4%B8%AAs%EF%BC%89%203.
// atof\atoi:http://c.biancheng.net/cpp/html/124.html
//c_str():https://www.cnblogs.com/cyx-b/p/12411673.html