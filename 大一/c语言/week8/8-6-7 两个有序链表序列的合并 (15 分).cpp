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
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
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
/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    int i=0;
    List a;
    PtrToNode head,p1,p2;
    while(L1->Next!=NULL||L2->Next!=NULL){
        if(L1->Data>L2->Data&&i==0){
            p1=p2=(PtrToNode)malloc(sizeof(struct Node));
            head=L2;
            =head;
            a->Data=L2->Data;
            L2=L2->Next;
            i++;
        }
        if(L1->Data<L2->Data&&i==0) {
            a=p1=p2=(PtrToNode)malloc(sizeof(struct Node));
            head=L1;
            a=head;
            a->Data=L1->Data;
            L1=L1->Next;
            i++;
        }
        a=p1=p2=(PtrToNode)malloc(sizeof(struct Node));
        if(L1->Data>L2->Data){

        }
        if(L1->Data<L2->Data){

        }
    }
}
//List Merge( List L1, List L2 )
//{
//    List pa,pb,pc,L;
//    L = (List)malloc(sizeof(struct Node));
//    pa=L1->Next;/*L1和L2是给定的带头结点的单链表*/
//    pb=L2->Next;
//    pc = L;
//    while(pa && pb)
//    {
//        if(pa->Data <= pb->Data)
//        {
//            pc->Next = pa;
//            pc = pa;
//            pa = pa->Next;
//        }
//        else
//        {
//            pc->Next = pb;
//            pc = pb;
//            pb = pb->Next;
//        }
//    }
//    pc->Next = pa ? pa : pb;
//    L1->Next = NULL;
//    L2->Next = NULL;
//    return L;
//}
//表达式1？表达式2：表达式3
//先计算表达式1
//1.若表达式1成立，则选择计算表达式2，并将表达式2的值作为整个大表达式的值
//2.若表达式1不成立，则选择计算表达式3，并将表达式3的值作为整个大表达式的值。