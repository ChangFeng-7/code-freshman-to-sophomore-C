//����nֵ��n���������������������������
//�����ʽ:
//����n��n��������
//�����ʽ:
//���n���������Կո�ָ������һ�����ĺ���û�пո񣩡�
//��������:
//���������һ�����롣���磺
//2
//10 5
//�������:
//�����������Ӧ����������磺
//10 5
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct text)
struct text{
    int n;
    struct text *next;
};
int i;
struct text *print(void){
    int j;
    struct text *p1,*p2,*head;
    head=NULL;
    p1=p2=(struct text *)malloc(LEN);
    for(j=1;j<=i;j++){
        if(j==1){
            scanf("%d",&p1->n);
            head=p1;
        }
        else{
            p1=(struct text*)malloc(LEN);
            scanf("%d",&p1->n);
            p2->next=p1;
            p2=p1;
        }
    }
    p2->next=NULL;
    return (head);
}
int main(){
    scanf("%d",&i);
    if(i==0) return 0;
    int j=1;
    struct text *pt;
    pt=print();
    while(pt!=NULL) {
        if(j!=i){
            printf("%d ", pt->n);
            pt=pt->next;
            j++;
        }
        else{
            printf("%d",pt->n);
            pt=pt->next;
        }
    }
    return 0;
}