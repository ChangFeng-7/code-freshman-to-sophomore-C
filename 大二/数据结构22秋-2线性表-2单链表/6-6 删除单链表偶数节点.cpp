#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
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
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist(){
    struct ListNode *L;
    struct ListNode *q=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p;
    scanf("%d",&q->data);
    if(q->data==-1){
        L=NULL;
        return L;
    }
    int num;
    L=p=q;
    while(1){
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next=q;
        scanf("%d",&num);
        if(num==-1){
            p->next=q=NULL;
            break;
        }
        q->data=num;
        p=q;
    }
    return L;
}
struct ListNode *deleteeven( struct ListNode *head ){
    struct ListNode *p;
    for(p=head;p->data%2==0;p=p->next) {
        if (p->next == NULL) {
            head = NULL;
            return head;
        }
    }
    head=p;
    p=p->next;
    struct ListNode *q;
    q=head;
    while(p!=NULL){
        if(p->data%2!=0) {
            q->next = p;
            q=p;
            p = p->next;
            continue;
        }
        p=p->next;
    }
    q->next=NULL;
    return head;
}
