//已知表示点的类CPoint和表示线段的CLine类，
//类CPoint包含：（1）表达点位置的私有数据成员x,y
//（2）构造函数及复制构造函数
// 类CLine包含：
//（1）两个CPoint的点对象（该两点分别为线段的两个端点）
//（2）构造函数（提示：构造函数中用初始化列表对内嵌对象进行初始化）
//（3）公有成员函数GetLen，其功能为返回线段的长度，返回值类型为整型
//（4）类属性成员count用于记录创建的CLine类对象的个数，及用于显示count值的ShowCount函数；
//要求：
//（1）实现满足上述属性和行为的CPoint类及CLine类定义；
//（2）保证如下主函数能正确运行。
//输入样例：
//在这里给出一组输入。例如：
//1 1
//4 5
//输出样例：
//在这里给出相应的输出。例如：
//The length of line1 is:5
//The length of line2 is:5
//The count of Line is:2
/* 请在这里填写答案 */
#include <iostream>
#include <math.h>
using namespace std;
class CPoint{
    int x,y;
public:
    CPoint(int x,int y);
    CPoint(CPoint &p1);
    double GetX(){return x;}
    double GetY(){return y;}
};
class CLine{
public:
    CPoint cp1,cp2;
    int GetLen();
    CLine(CPoint a,CPoint b){
        cp1=a;
        cp2=b;
    }
    CLine(CLine &a);
    static int ShowCount();
};
static int i=0;
CPoint::CPoint(int x, int y) {
    i++;
    x=x;
    y=y;
}
CPoint::CPoint(CPoint &p1) {i++;}
int CLine::GetLen(){
    return sqrt(pow(cp1.GetX()-cp2.GetX(),2)+pow(cp1.GetY()-cp2.GetY(),2));
}

int CLine::ShowCount() {
    return i;
}
CLine::CLine(CLine &a) {
    x=a.x;
    y=a.y;
}






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
//#include <iostream>
//#include <math.h>
//using namespace std;
//class CPoint
//{
//    int x,y;
//public:
//    CPoint(int a=0,int b=0)
//    {
//        x=a;
//        y=b;
//    }
//    CPoint(const CPoint &c)
//    {
//        x=c.x;
//        y=c.y;
//    }
//    double GetX()
//    {
//        return x;
//    }
//    double GetY()
//    {
//        return y;
//    }
//};
//
//class CLine
//{
//    CPoint cp1,cp2;
//    static int count;
//public:
//    CLine(CPoint a,CPoint b)
//    {
//        cp1=a;
//        cp2=b;
//        count++;
//    }
//    int GetLen()
//    {
//        return sqrt(pow(cp1.GetX()-cp2.GetX(),2)+pow(cp1.GetY()-cp2.GetY(),2));
//    }
//    CLine(const CLine &l)
//    {
//        cp1=l.cp1;
//        cp2=l.cp2;
//        count++;
//    }
//    static int ShowCount()
//    {
//        return count;
//    }
//};
//int CLine::count=0;