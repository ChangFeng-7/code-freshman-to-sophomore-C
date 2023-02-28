#include <iostream>
using namespace std;
// Link==0:指针，Thread==1:线索
typedef enum { Link, Thread } PointerTag;
typedef char TElemType;
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild; // 左右孩子指针
    PointerTag LTag, RTag;   // 左右标志
} BiThrNode, *BiThrTree;
BiThrNode *pre=new BiThrNode;
void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);//左子树线索化
        if(!p->lchild){//中间节点lchird线索化
            p->lchild=pre;
            p->LTag=Thread;
        }
        if(!pre->rchild){//pre节点rchild线索化
            pre->rchild=p;
            pre->RTag=Thread;
        }
        pre=p;//保持pre指向p的前驱
        InThreading(p->rchild);//右子树线索化
    }
}
int InOrderThreading(BiThrTree& Thrt, BiThrTree T){
    Thrt=(BiThrTree)malloc(sizeof(BiThrNode));//生成头节点
    Thrt->LTag=Link;
    Thrt->RTag=Thread;
    Thrt->rchild=Thrt;//头节点右子树先回指自己
    if(!T){//空树，左指针回指
        Thrt->lchild=Thrt;
    }else{//不是空树，则执行线索化
        Thrt->lchild=T;
        pre=Thrt;
        InThreading(T);//调用递归中序线索化
        pre->RTag=Thread;//最后一个节点线索化，此时pre指向刚才InThreading线索化的那个节点
        pre->rchild=Thrt;
        Thrt->rchild=pre;//头节点rchild指向pre
    }
}
