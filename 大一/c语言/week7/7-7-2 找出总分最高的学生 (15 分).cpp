//����N��ѧ���Ļ�����Ϣ������ѧ�ţ���5��������ɵ��ַ�����������������С��10�Ĳ������հ��ַ��ķǿ��ַ�������3�ſγ̵ĳɼ���[0,100]�����ڵ���������Ҫ������ܷ����ѧ����������ѧ�ź��ܷ֡�
//�����ʽ��
//������һ���и���������N����10�������N�У�ÿ�и���һλѧ������Ϣ����ʽΪ��ѧ�� ���� �ɼ�1 �ɼ�2 �ɼ�3�����м��Կո�ָ���
//
//�����ʽ��
//��һ��������ܷ����ѧ����������ѧ�ź��ܷ֣����һ���ո���Ŀ��֤������ѧ����Ψһ�ġ�
//
//����������
//5
//00001 huanglan 78 83 75
//00002 wanghai 76 80 77
//00003 shenqiang 87 83 76
//10001 zhangfeng 92 88 78
//21987 zhangmeng 80 82 75
//���������
//zhangfeng 10001 258
#include <stdio.h>
#include <stdlib.h>
struct stu{
    char num[6];
    char name[11];
    int score1;
    int score2;
    int score3;
    struct stu *next;
};
int main(){
    struct stu *head,*p1,*p2,*pt;
    int n,i=1;
    scanf("%d",&n);
    head=p1=p2=(struct stu*)malloc(sizeof(struct stu));
    scanf("%s %s %d %d %d",p1->num,p1->name,&p1->score1,&p1->score2,&p1->score3);
    while(i<n){
        p1=(struct stu*)malloc(sizeof(struct stu));
        scanf("%s %s %d %d %d",p1->num,p1->name,&p1->score1,&p1->score2,&p1->score3);
        p2->next=p1;
        p2=p1;
        i++;
    }
    p2->next=NULL;
    int max=0;
    pt=head;
    while(head!=NULL){
        if((head->score1+head->score2+head->score3)>max)
            pt=head;
        max=(head->score1+head->score2+head->score3);
        head=head->next;
    }
    printf("%s %s %d",pt->name,pt->num,pt->score1+pt->score2+pt->score3);
    return 0;
}