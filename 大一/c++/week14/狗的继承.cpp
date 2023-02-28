#include <iostream>
#include <cstring>
using namespace std;
class Animal{
public:
    int old;
    Animal(int a){ old=a; }
    int getAge(){ return old; }
};
class Dog:public Animal{
public:
    char colour[10];
    Dog(int a,char s[10]):Animal(a){
        strcpy(colour,s);
    }
    void showInfor(){
        cout<<"age:"<<old<<endl<<"color:"<<colour;
    }
};
int main(){
    Animal ani(5);
    cout<<"age of ani:"<<ani.getAge()<<endl;
    Dog dog(5,"black");
    cout<<"infor of dog:"<<endl;
    dog.showInfor();
}

