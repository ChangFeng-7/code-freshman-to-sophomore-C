//����Ҫ��ʵ��һ��������ͳ��ѧ��ѧ��������רҵΪ�������ѧ�������������㶨�����£�
//struct ListNode {
//    char code[8];
//    struct ListNode *next;
//};
//����ѧ����ѧ�Ź�7λ���֣����е�2��3λ��רҵ��š������רҵ�ı��Ϊ02��
//�����ӿڶ��壺
//int countcs( struct ListNode *head );
//����head���û������ѧ��ѧ�������ͷָ�룻����countcsͳ�Ʋ�����head������רҵΪ�������ѧ��������
//����������
//1021202
//2022310
//8102134
//1030912
//3110203
//4021205
//#
//���������
//3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    char code[8];
    struct ListNode *next;
};
struct ListNode *createlist(); /*����ʵ�֣�ϸ�ڲ���*/
int countcs( struct ListNode *head );
int main()
{
    struct ListNode  *head;
    head = createlist();
    printf("%d\n", countcs(head));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int countcs( struct ListNode *head ){
    struct ListNode *pt=head;
    int i=0;
    while(pt->next!=NULL){
        if(pt->code[1]=='0'&&pt->code[2]=='2') i++;
        pt=pt->next;
    }
    return i;
}