//����һϵ���������������һ�������ܸ�Ч���㷨�����ҵ�����K��λ���ϵ����֡�
//�����ʽ:
//�������ȸ���һ��������K����������ɷǸ������������һ����������ʾ��β���ø��������������ڣ���Ҫ������
//�����ʽ:
//���������K��λ���ϵ����ݡ�������λ�ò����ڣ����������ϢNULL��
//��������:
//4 1 2 3 4 5 6 7 8 9 0 -1
//�������:
//7
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
    int num;
    scanf("%d",&num);
    head = createlist();
    for(int i=1;i<num;i++){
        if(head->next==NULL){
            printf("NULL");
            return 0;
        }
        head=head->next;
    }
    printf("%d",head->data);
    return 0;
}
struct ListNode *createlist(){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *L;
    struct ListNode *q;
    int num;
    scanf("%d",&num);
    if(num==-1){
        L=NULL;
        return L;
    }
    p->data=num;
    p->next=q;
    q=p;
    while(1){
        scanf("%d",&num);
        if(num>=0){
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->data=num;
            p->next=q;
            q=p;
            continue;
        }
        break;
    }
    L=p;
    return L;
}