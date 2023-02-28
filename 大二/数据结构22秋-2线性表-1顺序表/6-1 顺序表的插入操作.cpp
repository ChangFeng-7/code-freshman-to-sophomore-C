#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;
void InitList(SqList &L);/*ϸ���ڴ˲���*/
int ListInsert(SqList &L,int i,ElemType e);
int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    int i;
    scanf("%d%d",&i,&e);
    int result=ListInsert(L,i,e);
    if(result==0){
        printf("Insertion Error.The value of i is unlawful or the storage space is full!");
    }else if(result==1){
        printf("Insertion Success.The elements of the SequenceList L are:");
        for(int j=0;j<L.length;j++){
            printf(" %d",L.elem[j]);
        }
    }
    return 0;
}
/* ����������д�� */
//��˳���ĵ�i��λ�ò���һ���µ�����Ԫ��e
int ListInsert(SqList &L,int i,ElemType e)
{
    if((i<1)||(i>L.length+1))  return 0;
    if(L.length==MAXSIZE)  return 0;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;
}

