//双端队列（deque，即double-ended queue的缩写）是一种具有队列和栈性质的数据结构，即可以（也只能）在线性表的两端进行插入和删除。
//若以顺序存储方式实现双端队列，请编写例程实现下列操作：
//Push(X,D)：将元素X插入到双端队列D的头；
//Pop(D)：删除双端队列D的头元素，并返回；
//Inject(X,D)：将元素X插入到双端队列D的尾部；
//Eject(D)：删除双端队列D的尾部元素，并返回。
//注意：Push和Inject应该在正常执行完操作后返回true，或者在出现非正常情况时返回false。
//当Front和Rear相等时队列为空，Pop和Eject必须返回由裁判程序定义的ERROR。
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, inject, eject, end } Operation;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque;

Deque CreateDeque( int MaxSize )
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push( ElementType X, Deque D );
ElementType Pop( Deque D );
bool Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintDeque( Deque D ); /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Deque D;
    int N, done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done) {
        switch(GetOp()) {
            case push:
                scanf("%d", &X);
                if (!Push(X, D)) printf("Deque is Full!\n");
                break;
            case pop:
                X = Pop(D);
                if ( X==ERROR ) printf("Deque is Empty!\n");
                else printf("%d is out\n", X);
                break;
            case inject:
                scanf("%d", &X);
                if (!Inject(X, D)) printf("Deque is Full!\n");
                break;
            case eject:
                X = Eject(D);
                if ( X==ERROR ) printf("Deque is Empty!\n");
                else printf("%d is out\n", X);
                break;
            case end:
                PrintDeque(D);
                done = 1;
                break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
bool Push( ElementType X, Deque D ){
    if((D->Front-1+D->MaxSize)%D->MaxSize==D->Rear){
        return false;
    }
    D->Data[(D->Front-1+D->MaxSize)%D->MaxSize]=X;
    D->Front=(D->Front-1+D->MaxSize)%D->MaxSize;
    return true;
}
ElementType Pop( Deque D ){
    if(D->Rear==D->Front){return ERROR;}
    ElementType a = D->Data[D->Front];
    D->Front = (D->Front+1)%D->MaxSize;
    return a;
}
bool Inject( ElementType X, Deque D ){
    if((D->Rear+1)%D->MaxSize==D->Front){return false;}
    D->Data[D->Rear]=X;
    D->Rear=(D->Rear+1)%D->MaxSize;
    return true;
}
ElementType Eject( Deque D ){
    if(D->Front==D->Rear) return ERROR;
    int x=D->Data[(D->Rear-1+D->MaxSize)%D->MaxSize];
    D->Rear=(D->Rear-1+D->MaxSize)%D->MaxSize;
    return x;
}