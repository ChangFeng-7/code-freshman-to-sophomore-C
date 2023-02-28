#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

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
    q=p;
    L=q;
    while(1){
        scanf("%d",&num);
        if(num!=-1){
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->data=num;
            q->next=p;
            q=p;
            continue;
        }
        break;
    }
    return L;
}
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *p=NULL;
    struct ListNode *q=NULL;
    struct ListNode *head=NULL;
    int num[100]={0},i=1;
    if(list1==NULL&&list2==NULL) return p;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    p=list1;
    while(i<=2){
        i++;
        while(p){
            num[p->data]++;
            p=p->next;
        }
        p=list2;
    }
    int j=0;
    p=NULL;
    int m=0;
    for(i=0;i<100;i++){
        if(num[i]!=0){
            while(m<num[i]) {
                if (0 == j--) {
                    p = (struct ListNode *) malloc(sizeof(struct ListNode));
                    p->data = i;
                    head = p;
                    q = p;
                    m++;
                    continue;
                }
                p = (struct ListNode *) malloc(sizeof(struct ListNode));
                p->data = i;
                q->next = p;
                q = p;
                m++;
            }
            m=0;
        }
    }
    q=p=NULL;
    return head;
}
