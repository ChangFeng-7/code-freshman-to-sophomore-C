#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LinkQueue;
bool  GetHead (LinkQueue  Q,  ElemType  &e)
{    if (Q.front==Q.rear)
    {  cout<<"NULL"<<endl;  return  false; }
    e=Q.front->next->data ;
    return  true;
}

void  EnQueue(LinkQueue  &Q, ElemType  e)
{   QNode *p;
    p=new  QNode;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

bool  DeQueue(LinkQueue &Q,  ElemType &e)
{    QNode *p;
    if (Q.front==Q.rear)
    {  cout<<"NULL"<<endl;  return  false; }
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)  Q.rear=Q.front;
    delete p;
    return  true;
}

int main()
{
    LinkQueue Q;
    ElemType x,e;
    InitQNode(Q);
    cin>>x;
    while(x!=-1)
    {
        EnQueue(Q,x);
        cin>>x;
    }
    cout<<"Head:";
    if(GetHead(Q,e))
        cout<<e<<endl;
    cout<<"Pop:";
    while(DeQueue(Q,e))
        cout<<e<<' ';
    return 0;
}



