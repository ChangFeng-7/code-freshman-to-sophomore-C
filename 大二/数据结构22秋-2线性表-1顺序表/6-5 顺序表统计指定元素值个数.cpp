#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
}SqList;
void InitList(SqList &L);/*细节在此不表*/
int GetCount(SqList L, ElemType e);

int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    printf("The number of %d is %d.\n",e, GetCount(L, e));
    return 0;
}

/* 请在这里填写答案 */
int GetCount(SqList L, ElemType e){
    int num=0;
    for(int i=0;i<L.length;i++){
        if(L.elem[i]==e) num++;
    }
    return num;
}
