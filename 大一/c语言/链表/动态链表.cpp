#include <stdio.h>
#include <stdlib.h>
//ָ������ = (ָ������*��malloc��sizeof��ָ�����ͣ�*����������
struct student{
    int num;
    float score;
    struct student *next;
};
int n;
struct student *creat(void) {
    struct student *p1, *p2, *head;
    n=0;
    p1 = p2 = (struct student *) malloc(sizeof(struct student));
    scanf("%d %f", &p1->num, &p1->score);
    head=NULL;
    while(p1->num!=0){
        n=n+1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct student*)malloc(sizeof(struct student));
        scanf("%d %f",&p1->num,&p1->score);
    }
    p2->next=NULL;
    return(head);
}
int main(){
    struct student *pt;
    pt=creat();
    while(pt!=NULL){
        printf("%d %f",pt->num,pt->score);
        pt=pt->next;
    }
    return 0;
//������free������������������������汾�������ǵ���ġ�
#include <stdio.h>
#include <stdlib.h>
#define LEN (sizeof(struct student))
    struct student{
        int n;
        float score;
        struct student *next;
    };
    struct student *makelist(void){
        int j=1;
        struct student *p1,*p2,*head;
        head=NULL;
        p1=p2=(struct student *)malloc(LEN);
        scanf("%d %f",&p1->n,&p1->score);
        while(p1->n!=0){
            p1=(struct student *)malloc(LEN);
            scanf("%d %f",&p1->n,&p1->score);
            if(j==1) p2->next=NULL;
            p1->next=p2;
            p2=p1;
            j++;
        }
        head=p1->next;
        return (head);
    };
    int main(){
        struct student *pt;
        pt=makelist();
        while(pt!=NULL){
            printf("%d %f\n",pt->n,pt->score);
            pt=pt->next;
        }
        return 0;
    }