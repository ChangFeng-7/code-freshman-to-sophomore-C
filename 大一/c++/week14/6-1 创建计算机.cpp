#include <iostream>
using namespace std;
class COMPUTER{
public:
    int rank;
    int frequency;
    int voltage;
    int volumn;
    int speed;
    COMPUTER(int a,int b,int c,int d,int e){
        rank=a;
        frequency=b;
        voltage=c;
        volumn=d;
        speed=e;
        cout<<"create a CPU!"<<endl<<"create a RAM!"<<endl<<"create a CDROM!"<<endl<<"create a COMPUTER with para!"<<endl;
    }
    COMPUTER(){
        rank=1;
        frequency=2;
        voltage=100;
        volumn=1;
        speed=16;
        cout<<"create a CPU!"<<endl<<"create a RAM!"<<endl<<"create a CDROM!"<<endl<<"no para to create a COMPUTER!"<<endl;
    }
    COMPUTER(COMPUTER &a){
        rank=a.rank;
        frequency=a.frequency;
        voltage=a.voltage;
        volumn=a.volumn;
        speed=a.speed;
        cout<<"create a CPU by copy!"<<endl<<"create a RAM by copy!"<<endl<<"create a CDROM by copy!"<<endl<<"create a COMPUTER by copy!"<<endl;
    }
    ~COMPUTER(){
        cout<<"destruct a COMPUTER!"<<endl<<"destruct a CDROM!"<<endl<<"desturct a RAM!"<<endl<<"desturct a CPU!"<<endl;
    }
    void showinfo(){
        cout<<"cpu parameter:"<<endl<<"rank:"<<rank<<endl<<"frequency:"<<frequency<<endl<<"voltage:"<<voltage<<endl<<"ram parameter:"<<endl<<"volumn:"<<volumn<<" GB"<<endl<<"cdrom parameter:"<<endl<<"speed:"<<speed<<endl;
    }
};
int main()
{
    COMPUTER cpt1(6,4.0,200,60,32);  //测试带参数构造
    cout<<"cpt1's parameter:"<<endl;
    cpt1.showinfo();
    cout<<"------------------------------"<<endl;
    COMPUTER cpt2; //测试不带参数构造
    cout<<"cpt2's parameter:"<<endl;
    cpt2.showinfo();
    cout<<"------------------------------"<<endl;
    COMPUTER cpt3(cpt1); //测试复制构造
    cout<<"cpt3's parameter:"<<endl;
    cpt3.showinfo();
    cout<<"------------------------------"<<endl;
}

