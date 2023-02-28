//已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。
//输入格式:
//输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用?1表示序列的结尾（?1不属于这个序列）。数字用空格间隔。
//输出格式:
//在一行中输出两个输入序列的交集序列，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出NULL。
//输入样例:
//1 2 5 -1
//2 4 5 8 10 -1
//输出样例:
//2 5
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
int main(){
    struct ListNode *p;
    struct ListNode *q;
    struct ListNode *h;
    p=readlist();
    q=readlist();
    if(p==NULL||q==NULL){ printf("NULL"); return 0;}
    int num[2029999]={0};
    h=p;
    int j=1;
    int cot=0,cnt=0;
    while(j>=0) {
        while (h) {
            num[h->data]++;
            if(num[h->data]==2) { cot++; }
            h = h->next;
        }
        h=q;
        j--;
    }
    if(cot==0){ printf("NULL"); return 0;}
    for(j=0;j<2029999;j++){
        if(num[j]>1){
            if(cnt==(cot-1)){
                printf("%d",j);
                break;
            }
            printf("%d ",j);
            cnt++;
        }
    }
    return 0;
}
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