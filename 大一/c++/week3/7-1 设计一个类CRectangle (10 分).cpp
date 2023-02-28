//设计一个类CRectangle，要求如下所述： (1) 该类中的私有成员变量存放CRectangle的长和宽，并且设置它们的默认值为1. (2) 通过成员函数设置其长和宽，并确保长和宽都在（0，50）范围之内。 (3) 求周长Perimeter
//        输入格式:
//输入在一行中给出2个绝对值不超过50的浮点数A和B。
//
//输出格式:
//在一行中输出周长的值。
//
//输入样例:
//在这里给出一组输入。例如：
//
//25 15
//输出样例:
//在这里给出相应的输出。例如：
//
//80
#define _CRT_SECURE_NO_WARINGS
#include<iostream>
using namespace std;
class CRectangle
{
public:
    void set_value();
    void display();
    CRectangle()
    {
        a = 1.0;
        b = 1.0;
    }
private:
    float a, b;
};
void CRectangle::set_value()
{
    cin >> a ;
    if (a > 50)
    {
        a = 1.0;
    }
    cin >> b;
    if (b > 50)
    {
        b = 1.0;
    }

}
void CRectangle::display()
{
    cout <<(a + b) * 2 << endl;
}
int main()
{
    CRectangle c;
    c.set_value();
    c.display();
    return 0;
}

