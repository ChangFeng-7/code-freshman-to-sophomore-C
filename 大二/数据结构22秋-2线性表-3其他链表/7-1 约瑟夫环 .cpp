//N����Χ��һȦ˳���ţ���1�ſ�ʼ��1��2��3......˳��������p���˳�Ȧ�⣬��������ٴ�1��2��3��ʼ��������p�������˳�Ȧ�⣬�Դ����ơ�
//�밴�˳�˳�����ÿ���˳��˵�ԭ��š�
//�����ʽ:
//����ֻ��һ�У�����һ������N(1<=N<=3000)��һ������p(1<=p<=5000)��
//�����ʽ:
//���˳�˳�����ÿ���˳��˵�ԭ��ţ����ݼ���һ���ո�ָ�������β�޿ո�
//��������:
//���������һ�����롣���磺
//7 3
//�������:
//3 6 2 7 5 1 4
#include <iostream>
using namespace std;
struct stu{
    int num;
    struct stu *next;
    struct stu *prior;
};
int main(){
    int num,m;
    cin>>num>>m;
    int i;
    struct stu *p=(struct stu *)malloc(sizeof(struct stu));
    struct stu *q;
    struct stu *head;
    for(i=1;i<num+1;i++){
        p=(struct stu *)malloc(sizeof(struct stu));
        if(i==1){
            head=p;
            p->num=i;
            q=p;
            continue;
        }
        p->num=i;
        q->next=p;
        p->prior=q;
        q=p;
    }
    q->next=head;
    head->prior=q;
    q=p=head;
    while(p->next!=p){
        for(i=0;i<m-1;i++){
            p=p->next;
        }
        printf("%d ",p->num);
        p->prior->next=p->next;
        p->next->prior=p->prior;
        p=p->next;
    }
    printf("%d",p->num);
    return 0;
}