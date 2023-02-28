#include <iostream>
using namespace std;
int OK=1,ERROR=0;
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;
bool visit(TElemType T){
    cout<<T<<endl;
    return OK;
}
//左序
void PreOrder(BiTree T){
    if(T){
        visit(T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        visit(T->data);
        InOrder(T->rchild);
    }
}
//后序
void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T->data);
    }
}