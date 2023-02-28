//若一个线性表L采用顺序存储结构存储，其中所有的元素为整数。
//设计一个算法，删除元素值在[x,y]之间的所有元素，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。
//输入格式:
//三行数据，第一行是顺序表的元素个数，第二行是顺序表的元素，第三行是x和y。
//输出格式:
//删除元素值在[x,y]之间的所有元素后的顺序表。
//输入样例:
//10
//5 1 9 10 67 12 8 33 6 2
//3 10
//输出样例:
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
//可以新建一个数组
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