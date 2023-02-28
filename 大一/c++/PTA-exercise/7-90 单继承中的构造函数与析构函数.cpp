#include <iostream>
#include<iomanip>
using namespace std;
const double PI=3.14;
class Dot{
private:
    float x,y;
    Dot(){
        cout<<"Dot constructor called"<<endl;
    }
    ~Dot(){
        cout<<"Dot destructor called"<<endl;
    }
    friend class Cir;
};
class Cir:public Dot{
private:
    float r;
public:
    float getArea(){
        return PI*r*r;
    }
    Cir(float _x,float _y,float _r):Dot(),r(_r){
        x=_x;
        y=_y;
        cout<<"Cir constructor called"<<endl;
    }
    ~Cir(){
        cout<<"Cir destructor called"<<endl;
    }
};
int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    return 0;
}
