//����Ҫ�󽫼��������ѧ����Ϣ�����ɵ�����������ѧ����Ϣ�����в���ѧ����Ϣ��
//ѧ����Ϣ�����㶨�����£�
//typedef struct List{
//    ����int sno;
//    ����char sname[10];
//    ����List *next;
//};��
//��Ҫ�����ĺ���������
//����ѧ����Ϣ��������CreateList
//        ����ѧ����Ϣ��������Find
//        �����ӿڶ��壺
//List * CreateList();  //������������ѧ��ѧ�ź�������ѧ���������Կո��������������ѧ��Ϊ-1ʱ���������������ѧ����Ϣ������������ѧ�������ͷָ�롣
//List * Find(List *head, int no)  //��ѧ����Ϣ����ͷָ��Ϊhead���в�ѯѧ��Ϊno��ѧ�������ظ�ѧ������ָ�롣
//��������1��
//20180002 ����
//20180006 ����
//20180008 ����
//20170010 ����
//-1 xx
//20180002
//�������1��
//�����������Ӧ����������磺
//����
//��������2��
//20180002 ����
//20180006 ����
//20180008 ����
//20170010 ����
//-1 xx
//20170015
//�������2��
//Not Found!
#include <stdio.h>
#include <stdlib.h>
typedef struct List{
       int sno;
    char sname[10];
    List *next;
};
List * CreateList();  //������������ѧ��ѧ�ź�������ѧ���������Կո��������������ѧ��Ϊ-1ʱ���������������ѧ����Ϣ������������ѧ�������ͷָ�롣
List * Find(List *head, int no);  //��ѧ����Ϣ����ͷָ��Ϊhead���в�ѯѧ��Ϊno��ѧ�������ظ�ѧ������ָ�롣
int main(void){
    List *list=NULL,*p;
    int no;
    list=CreateList();
    while(~scanf("%d", &no))
    {
        p=Find(list,no);
        if( p ) printf("%s\n", p->sname);
        else printf("Not Found!\n");
    }
    return 0;
}
/* ����������д�� *///��δ����-1 XXҲ�������������ˣ������һ�¡�
List * CreateList(){
    List *p1,*p2,*pt,*head=NULL;
    head=p1=p2=(List*)malloc(sizeof(List));
    scanf("%d %s", &p1->sno, p1->sname);
    while(p1->sno!=-1){
        p2=(List*)malloc(sizeof(List));
        scanf("%d %s",&p2->sno,p2->sname);
        p1->next=p2;
        p1=p2;
    }
    p1->next=NULL;
    return head;
}
List * Find(List *head, int no){
    List *pt;
    pt=head;
    while(pt->sno!=no&&pt->sno!=-1){
        pt=pt->next;
    }
    if(pt->sno==-1) return 0;
    else return pt;
}