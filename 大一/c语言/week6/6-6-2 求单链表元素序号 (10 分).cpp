//本题要求实现一个函数，求带头结点的单链表中元素序号。
//函数接口定义：
//int Locate ( LinkList L, ElemType e);
//L是带头结点的单链表的头指针，e是要查找的元素值。如果e在单链表中存在，函数Locate返回其序号（序号从1开始）；否则，返回0。
//输入样例：
//2 1 4 5 3 -1
//5
//输出样例：
//4
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Create();/* 细节在此不表 */
int Locate ( LinkList L, ElemType e);
int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d",&e);
    printf("%d\n", Locate(L,e));
    return 0;
}
/* 你的代码将被嵌在这里 */
int Locate ( LinkList L, ElemType e){
    int i=0;
    while(L->next!=NULL){
        if(L->data!=e){
            i++;
            L=L->next;
        }
        else{
            i++;
            return i;
        }
    }
    return 0;
}