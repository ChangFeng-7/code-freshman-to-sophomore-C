//本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。
//函数接口定义：
//List Insert( List L, ElementType X );
//其中List结构定义如下：
//typedef struct Node *PtrToNode;
//struct Node {
//    ElementType Data; /* 存储结点数据 */
//    PtrToNode   Next; /* 指向下一个结点的指针 */
//};
//typedef PtrToNode List; /* 定义单链表类型 */
//L是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Insert要将X插入L，并保持该序列的有序性，返回插入后的链表头指针。
//输入样例：
//5
//1 2 4 5 6
//3
//输出样例：
//1 2 3 4 5 6
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
     PtrToNode p1,p2,pt;
     p2=L;
     if(L->Data>X{
         p1=(PtrToNode)malloc(sizeof(struct Node));
         p1->Data=X;
         p1->Next=L;
         return p1;
     }
     while(X>=L->Data){
         L=L->Next;
     }
     if(L->Next==NULL){
         p1 = (PtrToNode) malloc(sizeof(struct Node));
         p1->Data=X;
         L->Next=p1;
         p1->Next=NULL;
         return p2;
     }
     else {
         p1 = (PtrToNode) malloc(sizeof(struct Node));
         p1->Data = X;
         pt = L->Next;//pt为3地址
         L->Next = p1;
         p1->Next = pt;
         int i;
         i=X;//X
         p1->Data=L->Data;
         L->Data=i;
         return p2;
     }
}

//List Insert( List L, ElementType X )
//{
//    List l = (List)malloc(sizeof(struct Node));
//    l->Data = X;
//    l->Next = NULL;
//    List S = L;
//    while(S->Next)
//    {
//        if(S->Next->Data>X){
//            break;
//        }
//        else{
//            S = S->Next;
//        }
//    }
//    l->Next = S->Next;
//    S->Next = l;
//    return L;
//}
