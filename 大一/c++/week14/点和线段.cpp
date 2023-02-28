#include <iostream>
#include <math.h>
using namespace std;
class CPoint{
private:
    int x;
    int y;
public:
    CPoint(int a,int b):x(a),y(b){};
    friend class CLine;
};
class CLine{
public:
    static int count;
    int x1,y1,x2,y2;
    CLine(CPoint &a,CPoint &b){
        x1=a.x;
        y1=a.y;
        x2=b.x;
        y2=b.y;
        count++;
    }
    CLine(CLine &a){
        x1=a.x1;
        x2=a.x2;
        y1=a.y1;
        y2=a.y2;
        count++;
    }
    int GetLen(){
        int len;
        len=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        len=(int)sqrt(len);
        return len;
    }
    static int ShowCount(){return count;}
};
int CLine::count=0;//不知道为什么去掉这一行就开始报错。。。:-(
int main(){
    int x,y;
    cin>>x>>y;
    CPoint p1(x,y);
    cin>>x>>y;
    CPoint p2(x,y);
    CLine line1(p1,p2);
    cout<<"the length of line1 is:"<<line1.GetLen()<<endl;
    CLine line2(line1);
    cout<<"the length of line2 is:"<<line2.GetLen()<<endl;
    cout<<"the count of CLine is:"<<CLine::ShowCount()<<endl;
    return 0;
}
