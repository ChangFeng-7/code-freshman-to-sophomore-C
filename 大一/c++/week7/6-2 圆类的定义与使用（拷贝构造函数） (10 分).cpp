#include<iostream>
using namespace std;
/* 请在这里填写答案 */
class Circle{
public:
    float r;
    float area(){return 3.14*r*r;}
    float perimeter(){return 6.28*r;}
    Circle(float a){
        r=a;
        cout<<"Constructor called"<<endl;
    }
    Circle(Circle &c1){
        r=c1.r;
        cout<<"Copy constructor called"<<endl;
    }
    ~Circle(){
        cout<<"Destructor called"<<endl;
    }
};
int main()
{
    float r;
    cin>>r;
    Circle c1(r);
    Circle c2(c1);
    cout<<c1.area()<<endl;//计算圆面积
    cout<<c2.perimeter()<<endl;//计算圆周长
    return 0;
}
//定义一个圆类包括构造函数、拷贝构造函数以及析构函数(圆周率取值3.14）
