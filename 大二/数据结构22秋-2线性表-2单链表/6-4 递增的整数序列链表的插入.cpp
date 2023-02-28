#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert( List L, ElementType X ){
    PtrToNode p=(PtrToNode)malloc(sizeof(struct Node));
    p->Data=X;
    if(L==NULL){
        L->Data=X;
        return L;
    }
    PtrToNode q;
    q=L;
    for(;q->Next!=NULL&&q->Next->Data<p->Data;q=q->Next);
    p->Next=q->Next;
    q->Next=p;
    return L;
}
