//����Ҫ��ʵ��һ���������ڵ�������������������ͷ��㣩�в���һ���������������ָ����е������ԡ�
//�����ӿڶ��壺
//List Insert( List L, ElementType X );
//����List�ṹ�������£�
//typedef struct Node *PtrToNode;
//struct Node {
//    ElementType Data; /* �洢������� */
//    PtrToNode   Next; /* ָ����һ������ָ�� */
//};
//typedef PtrToNode List; /* ���嵥�������� */
//L�Ǹ����Ĵ�ͷ���ĵ���������洢�������ǵ�������ģ�����InsertҪ��X����L�������ָ����е������ԣ����ز���������ͷָ�롣
//����������
//5
//1 2 4 5 6
//3
//���������
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
List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */
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
/* ��Ĵ��뽫��Ƕ������ */
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
         pt = L->Next;//ptΪ3��ַ
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
