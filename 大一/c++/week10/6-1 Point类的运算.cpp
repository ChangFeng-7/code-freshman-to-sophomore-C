#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class Point
{
    int x,y;
public:
    Point(int a=0,int b=0):x(a),y(b){}
    friend Point operator+(const Point &pp,const Point &p);
    friend Point operator-(const Point &pp,const Point &p);
    friend bool operator==(const Point &p,const Point &pp);
    friend Point operator+=(Point &pp,Point &p);
    friend ostream& operator<<(ostream&, Point&);
} ;

Point operator+(const Point &pp,const Point &p)
{
    return Point(pp.x+p.x,pp.y+p.y);
}

Point operator-(const Point &pp,const Point &p)
{
    return Point(pp.x-p.x,pp.y-p.y);
}

bool operator==(const Point &p,const Point &pp)
{
    if(p.x==pp.x&&p.y==pp.y) return true;
    else return false;
}
Point operator+=(Point &pp,Point &p)
{
    pp.x+=p.x;
    pp.y+=p.y;
    return Point(pp.x,pp.y);
}

ostream &operator<<(ostream &out, Point &p)
{
    out<<p.x<<","<<p.y;
    return out;
}
// 请在这里填写答案
int main(int argc, char const *argv[])
{
    Point p1(2,3);
    cout<<p1<<endl;
    Point p2(4,5);
    cout<<p2<<endl;
    Point p3 = p1+p2;
    cout<<p3<<endl;
    p3 = p2-p1;
    cout<<p3<<endl;
    p1 += p2;
    cout<<p1<<endl;
    cout<<(p1==p2)<<endl;
    return 0;
}
