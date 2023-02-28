//ʵ��һ����ģ�壬�����Խ���һ�����ݣ��ܶ���������Ҳ�������������ݡ�
//ÿ������ĵ�һ������Ϊ0��1��2��3:Ϊ0ʱ��ʾ��������� Ϊ1ʱ��ʾ������������Ϊ2ʱ��ʾ��������һλС���ĸ�������Ϊ3ʱ��ʾ�����ַ���
//�����һ�����ַ�0���������������һ������������ʾ������������ݵ�������
//��ÿ�е��������뿪ʼ����������ָ�����͵����ݡ�
//����������
//1 3 2 3 1
//2 4 1.5 2.6 3.7 0.5
//3 2 A a
//0
//���������
//1 2 3
//0.5 1.5 2.6 3.7
//A a
#include <iostream>
using namespace std;
/* ����������д�� */
template <class T>
class MyArray{
public:
    T* data;
    int size;
    MyArray (int size);
    bool check();
    void sort();
    void display();
    ~MyArray();
};
template <class T>
MyArray <T>::MyArray (int size){
    this->size=size;
    data=new T(size);
    for(int i=0;i<size;i++){
        cin>>data[i];
    }
}
template <class T>
void MyArray <T>::sort(){
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                T temp;
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
template <class T>
void MyArray <T>::display() {
    for(int i=0;i<size;i++){
        cout<<data[i];
        if(i==size-1) cout<<endl;
        else cout<<" ";
    }
}
template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}

