#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist(){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *L;
    struct ListNode *q;
    L=p;
    int num;
    while(1){
        scanf("%d",&num);
        if(num==-1){
            q->next=NULL;
            break;
        }
        p->data=num;
        q=p;
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->next=p;
    }
    return L;
}
struct ListNode *deletem( struct ListNode *L, int m ){
    struct ListNode *p;
    struct ListNode *q;
    struct ListNode *c=(struct ListNode*)malloc(sizeof(struct ListNode));;
    c->next=L;
    p=q=L=c;
    p=p->next;
    int i=1;
    while(p!=NULL){
        if(p->data==m){
            q->next=p->next;
            p=p->next;
            continue;
        }
        if(i==1){
            i=0;
            L=c=p;
        }
        q=p;
        p=p->next;
    }
    if(L->data==0) L=NULL;
    return L;
}
