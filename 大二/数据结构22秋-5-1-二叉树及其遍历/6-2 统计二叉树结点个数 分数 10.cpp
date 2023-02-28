#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree Create();/* 细节在此不表 */

int NodeCount ( BiTree T);

int main()
{
    BiTree T = Create();

    printf("%d\n", NodeCount(T));
    return 0;
}
/* 你的代码将被嵌在这里 */
int NodeCount ( BiTree T){
    int cnt = 0;
    if(T!=NULL){
        cnt++;//如果不为空则先自加1
        cnt += NodeCount(T->lchild);//加上左子树的结点个数
        cnt += NodeCount(T->rchild);//加上右子树的结点个数
    }
    return cnt;//返回总的结点个数
}