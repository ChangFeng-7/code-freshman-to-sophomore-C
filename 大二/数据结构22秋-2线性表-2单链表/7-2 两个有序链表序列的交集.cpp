//��֪�����ǽ�����������S1��S2����ƺ��������S1��S2�Ľ���������S3��
//�����ʽ:
//��������У��ֱ���ÿ�и��������ɸ����������ɵķǽ������У���?1��ʾ���еĽ�β��?1������������У��������ÿո�����
//�����ʽ:
//��һ������������������еĽ������У����ּ��ÿո�ֿ�����β�����ж���ո���������Ϊ�գ����NULL��
//��������:
//1 2 5 -1
//2 4 5 8 10 -1
//�������:
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