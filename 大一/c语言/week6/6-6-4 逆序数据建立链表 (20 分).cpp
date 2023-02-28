//本题要求实现一个函数，按输入数据的逆序建立一个链表。
//函数接口定义:
//struct ListNode *createlist();
//函数createlist利用scanf从输入中获取一系列正整数，当读到?1时表示输入结束。按输入数据的逆序建立一个链表，并返回链表头指针。链表节点结构定义如下：
//struct ListNode {
//    int data;
//    struct ListNode *next;
//};
//输入样例：
//1 2 3 4 5 6 7 -1
//输出样例：
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
/* 你的代码将被嵌在这里 */
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