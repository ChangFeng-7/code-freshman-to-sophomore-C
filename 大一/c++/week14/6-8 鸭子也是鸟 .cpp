#include <iostream>
#include <string>
using namespace std;

/* ����������д�� */
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
    Duck d("Donald"); //�������������
    d.printName();    //���������ʹ�ñ����Ա����
    d.speak();    //���������ʹ�û����Ա����
    return 0;
}
