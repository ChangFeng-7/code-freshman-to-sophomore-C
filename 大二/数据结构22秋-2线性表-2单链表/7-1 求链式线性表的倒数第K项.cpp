//给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
//输入格式:
//输入首先给出一个正整数K，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。
//输出格式:
//输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。
//输入样例:
//4 1 2 3 4 5 6 7 8 9 0 -1
//输出样例:
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