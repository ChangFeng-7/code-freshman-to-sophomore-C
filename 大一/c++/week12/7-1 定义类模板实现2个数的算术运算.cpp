#include <iostream>
using namespace std;
template <class T>
class A{
public:
    T a,b;
    ~A(){};
    A(T c,T d):a(c),b(d){};
    void paixu(T a,T b);
    void jia(T a,T b);
    void jian(T a,T b);
    void cheng(T a,T b);
    void chu(T a,T b);
};
template <class T>
void A<T>::paixu(T a, T b) {
    T max,min;
    if(a>b){
        max=a;
        min=b;
    }else{
        max=b;
        min=a;
    }
    cout<<max<<" "<<min<<" ";
}
template <class T>
void A<T>::cheng(T a, T b) {
    cout<<a*b<<" ";
}
template <class T>
void A<T>::jia(T a, T b) {
    cout<<a+b<<" ";
}
template <class T>
void A<T>::jian(T a, T b) {
    cout<<a-b<<" ";
}
template <class T>
void A<T>::chu(T a, T b) {
    cout<<a/b;
}
int main(){
    int a,b;
    double c,d;
    cin>>a>>b>>c>>d;
    A<int>p(a,b);
    A<double>q(c,d);
    p.paixu(a,b);
    p.jia(a,b);
    p.jian(a,b);
    p.cheng(a,b);
    p.chu(a,b);
    cout<<endl;
    q.paixu(c,d);
    q.jia(c,d);
    q.jian(c,d);
    q.cheng(c,d);
    q.chu(c,d);
    return 0;
}
//下面是自己写的：
//#include <iostream>
//using namespace std;
//template <class T>
//class complex{
//public:
//    T a,b;
//    ~complex(){};
//    complex(T a,T b){
//        this->a=a;
//        this->b=b;
//    }
//    void Max(){
//        if(a>b){
//            cout<<a<<" "<<b<<" ";
//        }
//        else {
//            cout<<b<<" "<<a<<" ";
//        }
//    }
//    T jia(){
//        return a+b;
//    }
//    T jian(){
//        return a-b;
//    }
//    T cheng(){
//        return a*b;
//    }
//    T chu(){
//        return a/b;
//    }
//};
//int main(){
//    int a,b;
//    double c,d;
//    cin>>a>>b>>c>>d;
//    complex<int> p(a,b);
//    complex<double> q(c,d);
//    p.Max();
//    cout<<p.jia()<<" "<<p.jian()<<" "<<p.cheng()<<" "<<p.chu()<<endl;
//    q.Max();
//    cout<<q.jia()<<" "<<q.jian()<<" "<<q.cheng()<<" "<<q.chu();
//    return 0;
//}