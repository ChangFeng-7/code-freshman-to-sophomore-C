//����n��������ƺͶ��ۣ�����Ҫ���д���򣬲��Ҳ�������ж�����ߺ���͵�������ƺͶ��ۡ�
//�����ʽ:
//�����һ�и���������n��<10����������n�������Ϣ��ÿ������һ���и��������������Ȳ�����30���ַ��������һ���и�����ʵ���۸���Ŀ��֤û��ͬ���۸���顣
//�����ʽ:
//��һ���а��ա��۸�, �������ĸ�ʽ�Ⱥ�����۸���ߺ���͵��顣�۸���2λС����
//��������:
//3
//Programming in C
//21.5
//Programming in VB
//18.5
//Programming in Delphi
//25.0
//�������:
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
struct shu *creat(int n);//����һ������ͷ��ָ��
int main() {
    int n;
    scanf("%d\n", &n);
    struct shu *pt=creat(n);
    find(pt);
    //����Ϊ����������ã�
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