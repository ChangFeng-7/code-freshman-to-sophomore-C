//����Ҫ��ʵ��һ�����������ͷ���ĵ�������Ԫ����š�
//�����ӿڶ��壺
//int Locate ( LinkList L, ElemType e);
//L�Ǵ�ͷ���ĵ������ͷָ�룬e��Ҫ���ҵ�Ԫ��ֵ�����e�ڵ������д��ڣ�����Locate��������ţ���Ŵ�1��ʼ�������򣬷���0��
//����������
//2 1 4 5 3 -1
//5
//���������
//4
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Create();/* ϸ���ڴ˲��� */
int Locate ( LinkList L, ElemType e);
int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d",&e);
    printf("%d\n", Locate(L,e));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int Locate ( LinkList L, ElemType e){
    int i=0;
    while(L->next!=NULL){
        if(L->data!=e){
            i++;
            L=L->next;
        }
        else{
            i++;
            return i;
        }
    }
    return 0;
}