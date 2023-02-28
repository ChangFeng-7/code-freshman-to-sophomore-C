#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*����ʵ�֣�ϸ�ڲ���*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */


struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *L;
    struct ListNode *q;
    int num;
    if(head==NULL){
        L=NULL;
        return L;
    }
    p->data=head->data;
    p->next=q;
    q=p;
    head=head->next;
    while(1){
        if(head){
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->data=head->data;
            p->next=q;
            q=p;
            head=head->next;
            continue;
        }
        break;
    }
    L=p;
    return L;
}