#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;
void InitList(SqList &L);/*函数的实现此处不再显示*/
int SqInsert(SqList &L,ElemType e);
int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d",&e);
    int result=SqInsert(L,e);
    if(result==0){
        printf("Insertion Error.The storage space is full!");
    }else if(result==1){
        printf("Insertion Success.The elements of the SequenceList L are:");
        for(int j=0;j<L.length;j++){
            printf(" %d",L.elem[j]);
        }
    }
    return 0;
}

/* 请在这里填写答案 */
int SqInsert(SqList &L,ElemType e){
    if(L.length+1>MAXSIZE){ return 0; }
    L.length++;
    L.elem[L.length-1]=e;
    int a;
    for(int i=L.length-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(L.elem[j]>L.elem[j+1]){
                a=L.elem[j+1];
                L.elem[j+1]=L.elem[j];
                L.elem[j]=a;
            }
        }
    }
    return 1;
}