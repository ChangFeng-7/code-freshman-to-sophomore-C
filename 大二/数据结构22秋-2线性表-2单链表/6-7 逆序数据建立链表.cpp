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

/* 你的代码将被嵌在这里 */
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
        if(num!=-1){
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