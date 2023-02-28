#include<iostream>
using namespace std;
/* ����������д�� */
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
    cout<<c1.area()<<endl;//����Բ���
    cout<<c2.perimeter()<<endl;//����Բ�ܳ�
    return 0;
}
//����һ��Բ��������캯�����������캯���Լ���������(Բ����ȡֵ3.14��
