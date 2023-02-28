#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Bird{
public:
    void speak(){
        cout<<"Jiu-Jiu-Jiu"<<endl;
    }
};
class Duck:public Bird{
private:
    string name;
public:
    Duck(string s):Bird(){
        name=s;
    }
    void printName(){
        cout<<"Dird Name:"<<name<<endl;
    }
};
int main()
{
    Bird b;
    b.speak();
    Duck d("Donald"); //定义派生类对象
    d.printName();    //派生类对象使用本类成员函数
    d.speak();    //派生类对象使用基类成员函数
    return 0;
}
