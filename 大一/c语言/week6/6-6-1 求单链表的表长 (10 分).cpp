#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Create();/* 细节在此不表 */
int Length ( LinkList L );
int main()
{
    LinkList L = Create();
    printf("%d\n", Length(L));
    return 0;
}
//输入样例：
//2 1 4 5 3 -1
//输出样例：
//5
//L是带头结点的单链表的头指针，函数Length返回单链表的长度。
/* 你的代码将被嵌在这里 */
int Length ( LinkList L ){
    int i=0;
    if(L==NULL)
        return 0;
    while(L->next!=NULL){
       i++;
       L=L->next;
   }
    return i;
}