#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Create();/* ϸ���ڴ˲��� */
int Length ( LinkList L );
int main()
{
    LinkList L = Create();
    printf("%d\n", Length(L));
    return 0;
}
//����������
//2 1 4 5 3 -1
//���������
//5
//L�Ǵ�ͷ���ĵ������ͷָ�룬����Length���ص�����ĳ��ȡ�
/* ��Ĵ��뽫��Ƕ������ */
int Length ( LinkList L ){
    int i=0;
    if(L==NULL)
        return 0;
    while(L->next!=NULL){
       i++;
       L=L->next;
   }
    return i;
}