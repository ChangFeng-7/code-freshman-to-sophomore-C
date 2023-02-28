#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;
void InitList(SqList &L);/*ϸ���ڴ˲���*/
int ListDelete(SqList &L,int i);
int main()
{
    SqList L;
    InitList(L);
    int i;
    scanf("%d",&i);
    int result=ListDelete(L,i);
    if(result==0){
        printf("Delete Error.The value of i is illegal!");
    }else if(result==1){
        printf("Delete Success.The elements of the SequenceList L are:");
        for(int j=0;j<L.length;j++){
            printf(" %d",L.elem[j]);
        }
    }
    return 0;
}
/* ����������д�� */
int ListDelete(SqList &L,int i){
    if(L.length-1<0||i>L.length||i<1){ return 0; }
    L.length--;
    for(;i<=L.length;i++){
        L.elem[i-1]=L.elem[i];
    }
    return 1;
}