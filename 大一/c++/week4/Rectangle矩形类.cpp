#include<iostream>
using namespace std;
class Rectangle{
public:
    int w,h;
    void init(int w_,int h_);
    int area();
    int perimeter();
};
void Rectangle::init(int w_, int h_) {
    w=w_;
    h=h_;
}
int Rectangle::area() {
    return w*h;
}
int Rectangle::perimeter() {
    return (h+w)*2;
}
int main(){
    int w,h;
    Rectangle r;
    cin>>w>>h;
    r.init(w,h);
    cout<<r.area()<<endl;
    cout<<r.perimeter();
    cout<<sizeof(Rectangle)<<endl;
    return 0;
}