#include <iostream>
using namespace std;
class CMyClassA {
    int val;
public:
    CMyClassA(int);
    void virtual print();
};
CMyClassA::CMyClassA(int arg) {
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print() {
    printf("%d\n", val);
    return;
}

/* 在这里填写代码 */
//
class CMyClassB:public CMyClassA{
    int val;
public:
    CMyClassB(int val0):CMyClassA(val0*3){
        val=val0;
        cout<<"B:"<<val<<endl;
    }
    void print(){
        cout<<val<<endl;
    }
};
//
int main(int argc, char** argv) {
    CMyClassA a(3), *ptr;
    CMyClassB b(5);
    ptr = &a;
    ptr->print();
    a = b;
    a.print();
    ptr = &b;
    ptr->print();
    return 0;
}
