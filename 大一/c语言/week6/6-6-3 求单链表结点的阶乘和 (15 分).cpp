//����Ҫ��ʵ��һ��������������L���Ľ׳˺͡�����Ĭ�����н���ֵ�Ǹ�������Ŀ��֤�����int��Χ�ڡ�
//�����ӿڶ��壺
//int FactorialSum( List L );
//���е�����List�Ķ������£�
//typedef struct Node *PtrToNode;
//struct Node {
//    int Data; /* �洢������� */
//    PtrToNode Next; /* ָ����һ������ָ�� */
//};
//typedef PtrToNode List; /* ���嵥�������� */
//����������
//3
//5 3 6
//���������
//846
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
    int Data; /* �洢������� */
    PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */
int FactorialSum( List L );
int main()
{
    int N, i;
    List L, p;
    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int jiecheng(int n){
    int sum=n,i=0;
    for(i=0;sum!=0;i++){
        sum*=--sum;
    }
    return sum;
}
int FactorialSum( List L ){
    int sum=0;
    if(L==NULL) return 0;
    while(L->Next!=NULL){
        sum+=jiecheng(L->Data);
        L=L->Next;
    }
    return sum;
}

//int FactorialSum( List L )
//{
//    int i, s=1, ss=0;
//    while(L!=NULL){
//        for(i=L->Data; i>0; i--){
//            s*=i;
//        }
//        ss+=s;
//        L=L->Next;
//        s=1;
//    }
//    return ss;
