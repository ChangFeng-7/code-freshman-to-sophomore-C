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
    int count;
    for(count=0;head!=NULL;head=head->next){
        if(head->code[1]=='0'&&head->code[2]=='2') count++;
    }
    return count;
}
