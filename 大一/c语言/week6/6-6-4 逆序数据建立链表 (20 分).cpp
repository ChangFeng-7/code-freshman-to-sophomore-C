//����Ҫ��ʵ��һ�����������������ݵ�������һ������
//�����ӿڶ���:
//struct ListNode *createlist();
//����createlist����scanf�������л�ȡһϵ����������������?1ʱ��ʾ������������������ݵ�������һ����������������ͷָ�롣����ڵ�ṹ�������£�
//struct ListNode {
//    int data;
//    struct ListNode *next;
//};
//����������
//1 2 3 4 5 6 7 -1
//���������
//7 6 5 4 3 2 1
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int data;
    struct ListNode *next;
};
struct ListNode *createlist();
int main()
{
    struct ListNode *p, *head = NULL;
    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
struct ListNode *createlist(){
    struct ListNode *p1,*p2,*head;
    p1=p2=(struct ListNode*)malloc(sizeof(struct ListNode));
    scanf("%d",&p1->data);
    while(p1->data!=-1){
        p1=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&p1->data);
        p1->next=p2;
        p2=p1;
    }
    head=p1->next;
    return head;
}