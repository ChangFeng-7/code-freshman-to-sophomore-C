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
//    pa=L1->Next;/*L1��L2�Ǹ����Ĵ�ͷ���ĵ�����*/
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
//���ʽ1�����ʽ2�����ʽ3
//�ȼ�����ʽ1
//1.�����ʽ1��������ѡ�������ʽ2���������ʽ2��ֵ��Ϊ��������ʽ��ֵ
//2.�����ʽ1����������ѡ�������ʽ3���������ʽ3��ֵ��Ϊ��������ʽ��ֵ��