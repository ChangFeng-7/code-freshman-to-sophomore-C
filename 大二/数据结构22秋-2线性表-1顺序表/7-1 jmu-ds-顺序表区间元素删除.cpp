//��һ�����Ա�L����˳��洢�ṹ�洢���������е�Ԫ��Ϊ������
//���һ���㷨��ɾ��Ԫ��ֵ��[x,y]֮�������Ԫ�أ�Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
//�����ʽ:
//�������ݣ���һ����˳����Ԫ�ظ������ڶ�����˳����Ԫ�أ���������x��y��
//�����ʽ:
//ɾ��Ԫ��ֵ��[x,y]֮�������Ԫ�غ��˳���
//��������:
//10
//5 1 9 10 67 12 8 33 6 2
//3 10
//�������:
//1 67 12 33 2
#include <iostream>
using namespace std;
#define MAX 100
struct sqList{
    int *elem=(int*)malloc(sizeof(MAX));
    int length;
}L;
int sqList(struct sqList &L,int n);
int DeletesqList(struct sqList &L,int x,int y);
int main(){
    int num;
    cin>>num;
    sqList(L,num);
    L.length=num;
    int x,y,i;
    cin>>x>>y;
    int B=DeletesqList(L,x,y);
    if(B==1){
        for(i=0;i<L.length;i++){}
        cout<<L.elem[i]<<" ";
        return 0;
    }else{
        cout<<"ERROR";
        return 0;
    }
}
int sqList(struct sqList &L,int n){
    int i;
    for(i=0;i<n;i++)
    cin>>L.elem[i];
}
int DeletesqList(struct sqList &L,int x,int y){
    if(x<0||y>L.length) return 0;
    int num=y-x+1,i;
    L.length-=num;
    for(i=x-1;i<L.length;i++){
        L.elem[x++-1]=L.elem[y++];
    }
    return 1;
}
//�����½�һ������
//#include<iostream>
//using namespace std;
//int main(){
//    int num,a[10000],i;
//    cin>>num;
//    for(i=0;i<num;i++){
//        cin>>a[i];
//    }
//    int x,y;
//    cin>>x>>y;
//    for(i=0;i<num;i++){
//        if(a[i]>y||a[i]<x){
//            cout<<a[i];
//            if(i<num-1) cout<<" ";
//        }
//    }
//    return 0;
//}