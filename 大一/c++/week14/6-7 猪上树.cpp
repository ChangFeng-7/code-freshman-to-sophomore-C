#include<iostream>
using namespace std;
/* ����������д�� */
class Pig{
public:
    virtual void climb(){
        cout<<"��ֻ�Ǹ�ƽ��������"<<endl;
    }
    Pig(){
        cout<<"Pig �����˿ռ�..."<<endl;
    }
    virtual ~Pig(){
        cout<<"Pig �ͷ��˿ռ�..."<<endl;
    }
};
class MagicPig:public Pig{
public:
    MagicPig():Pig(){
        cout<<"MagicPig �����˿ռ�..."<<endl;
    }
    void climb(){
        cout<<"����������Ү��"<<endl;
    }
    ~MagicPig(){
        cout<<"MagicPig �ͷ��˿ռ�..."<<endl;
    }
};
int main()
{
    Pig *p1 = new Pig;
    Pig *p2 = new MagicPig;
    cout << endl;

    p1->climb();
    p2->climb();
    cout << endl;

    delete p1;
    delete p2;
    return 0;
}
