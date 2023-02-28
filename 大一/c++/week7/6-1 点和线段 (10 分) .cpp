//��֪��ʾ�����CPoint�ͱ�ʾ�߶ε�CLine�࣬
//��CPoint��������1������λ�õ�˽�����ݳ�Աx,y
//��2�����캯�������ƹ��캯��
// ��CLine������
//��1������CPoint�ĵ���󣨸�����ֱ�Ϊ�߶ε������˵㣩
//��2�����캯������ʾ�����캯�����ó�ʼ���б����Ƕ������г�ʼ����
//��3�����г�Ա����GetLen���书��Ϊ�����߶εĳ��ȣ�����ֵ����Ϊ����
//��4�������Գ�Աcount���ڼ�¼������CLine�����ĸ�������������ʾcountֵ��ShowCount������
//Ҫ��
//��1��ʵ�������������Ժ���Ϊ��CPoint�༰CLine�ඨ�壻
//��2����֤��������������ȷ���С�
//����������
//���������һ�����롣���磺
//1 1
//4 5
//���������
//�����������Ӧ����������磺
//The length of line1 is:5
//The length of line2 is:5
//The count of Line is:2
/* ����������д�� */
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