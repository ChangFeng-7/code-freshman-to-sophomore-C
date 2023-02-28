//给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。
//输入格式:
//输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。
//输出格式:
//在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。
//输入样例:
//3
//Programming in C
//21.5
//Programming in VB
//18.5
//Programming in Delphi
//25.0
//输出样例:
//25.00, Programming in Delphi
//18.50, Programming in VB
#include <stdio.h>
#include <stdlib.h>
struct shu{
    struct shu *next;
    char name[30];
    float num;
};
struct shu *head;
struct shu find(struct shu *head);
struct shu *creat(int n);//返回一个链表头部指针
int main() {
    int n;
    scanf("%d\n", &n);
    struct shu *pt=creat(n);
    find(pt);
    //以下为输出（测试用）
    struct shu *p1=pt;
    while(p1!=NULL){
        printf("%s %f\n",p1->name,p1->num);
        p1=p1->next;
    }
    return 0;
}
struct shu *creat(int n){
    int i=1;
    struct shu *p1,*p2,*pt;
    p1=p2=(struct shu*)malloc(sizeof(struct shu));
    scanf("%[^\n] %f",p1->name,&p1->num);
    scanf("\n");
    head=p1;
    while(i!=n){
        p1=(struct shu*)malloc(sizeof(struct shu));
        scanf("%[^\n] %f",p1->name,&p1->num);
        scanf("\n");
        p2->next=p1;
        p2=p1;
        i++;
    }
    p2->next=NULL;
    return head;
}
struct shu find(struct shu *head){
    int min,max;
    struct shu *pt=head,*pd,*px;
    min=max=0;
    while(pt!=NULL){
        if(pt->num>max){
            pd=pt;
            max=pt->num;
        }
        if(pt->num<min){
            px=pt;
            min=pt->num;
        }
        pt=pt->next;
    }
    printf("%.2f, %s\n",pd->num,pd->name);
    printf("%.2f, %s\n",px->num,px->name);
}