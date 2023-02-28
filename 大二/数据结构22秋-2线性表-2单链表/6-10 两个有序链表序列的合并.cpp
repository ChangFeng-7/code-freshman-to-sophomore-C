#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Merge( List L1, List L2 ){
    List a,c,b,l;
    l=(List)malloc(sizeof(PtrToNode));
    a=L1->Next,b=L2->Next,c=l;
    while(a&&b){
        if(a->Data>b->Data){
            c->Next=b;
            b=b->Next;
        }
        else{
            c->Next=a;
            a=a->Next;
        }
        c=c->Next;
    }
    if(a) c->Next=a;
    if(b) c->Next=b;
    L1->Next=NULL;
    L2->Next=NULL;
    return l;
}
