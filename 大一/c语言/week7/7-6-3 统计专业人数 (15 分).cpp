//本题要求实现一个函数，统计学生学号链表中专业为计算机的学生人数。链表结点定义如下：
//struct ListNode {
//    char code[8];
//    struct ListNode *next;
//};
//这里学生的学号共7位数字，其中第2、3位是专业编号。计算机专业的编号为02。
//函数接口定义：
//int countcs( struct ListNode *head );
//其中head是用户传入的学生学号链表的头指针；函数countcs统计并返回head链表中专业为计算机的学生人数。
//输入样例：
//1021202
//2022310
//8102134
//1030912
//3110203
//4021205
//#
//输出样例：
//3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    char code[8];
    struct ListNode *next;
};
struct ListNode *createlist(); /*裁判实现，细节不表*/
int countcs( struct ListNode *head );
int main()
{
    struct ListNode  *head;
    head = createlist();
    printf("%d\n", countcs(head));
    return 0;
}
/* 你的代码将被嵌在这里 */
int countcs( struct ListNode *head ){
    struct ListNode *pt=head;
    int i=0;
    while(pt->next!=NULL){
        if(pt->code[1]=='0'&&pt->code[2]=='2') i++;
        pt=pt->next;
    }
    return i;
}