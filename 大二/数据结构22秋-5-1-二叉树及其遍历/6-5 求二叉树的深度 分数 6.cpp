#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
BiTree Create();/* 细节在此不表 */
int Depth(BiTree T);
int main()
{
    BiTree T = Create();

    printf("%d\n", Depth(T));
    return 0;
}
/* 你的代码将被嵌在这里 */
int Depth(BiTree T){
    int depth,dleft=0,dright=0;
    if(T==NULL){
        depth=0;
    }else {
        dleft= Depth(T->lchild);
        dright= Depth(T->rchild);
        depth=(dleft>=dright)?(dleft+1):(dright+1);
    }
    return depth;
}



