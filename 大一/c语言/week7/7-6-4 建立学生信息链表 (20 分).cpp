//����Ҫ��ʵ��һ���������ѧ���ɼ���֯�ɵ�������ļ򵥺�����
//�����ӿڶ��壺
//void input();
//�ú�������scanf�������л�ȡѧ������Ϣ����������֯�ɵ�����������ڵ�ṹ�������£�
//struct stud_node {
//    int              num;      /*ѧ��*/
//    char             name[20]; /*����*/
//    int              score;    /*�ɼ�*/
//    struct stud_node *next;    /*ָ���¸�����ָ��*/
//};
//���������ͷβָ�뱣����ȫ�ֱ���head��tail�С�
//����Ϊ���ɸ�ѧ������Ϣ��ѧ�š��������ɼ�����������ѧ��Ϊ0ʱ������
//����������
//1 zhang 78
//2 wang 80
//3 li 75
//4 zhao 85
//0
//���������
//1 zhang 78
//2 wang 80
//3 li 75
//4 zhao 85
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node *next;
};
struct stud_node *head, *tail;
void input();
int main()
{
    struct stud_node *p;
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void input(){
    struct stud_node *p1,*p2,*pt;
    p1=p2=(struct stud_node*)malloc(sizeof(struct stud_node));
    scanf("%d %s %d",&p1->num,p1->name,&p1->score);
    head=p1;
    if(p1->num==0) head=NULL;
    while(p1->num!=0){
        p1=(struct stud_node*)malloc(sizeof(struct stud_node));
        scanf("%d %s %d",&p1->num,p1->name,&p1->score);
        p2->next=p1;
        if(p1->num==0){
            break;
        }
        p2=p1;
    }
    p2->next=tail=NULL;
}
