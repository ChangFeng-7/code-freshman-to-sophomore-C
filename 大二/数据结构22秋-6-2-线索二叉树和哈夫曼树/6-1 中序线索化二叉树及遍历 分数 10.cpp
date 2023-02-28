#include<iostream>
using namespace std;

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag;
}BiThrNode,*BiThrTree;


BiThrNode *pre=new BiThrNode;

void CreateBiTree(BiThrTree &T)
{
    char ch;
    cin >> ch;
    if(ch=='#')  T=NULL;
    else
    {
        T=new BiThrNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void InThreading(BiThrTree p);
void InOrderTraverse_Thr(BiThrTree T);

int main()
{
    pre->RTag=1;
    pre->rchild=NULL;
    BiThrTree tree;
    CreateBiTree(tree);
    InThreading(tree);
    InOrderTraverse_Thr(tree);
    return 0;
}
/* 请在这里填写答案 */
void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);
        if(!p->lchild){
            p->LTag=1;
            p->lchild=pre;
        }
        if(!pre->rchild){
            pre->rchild=p;
            pre->RTag=1;
        }
        pre=p;
        InThreading(p->rchild);
    }
}
int i=0;
void InOrderTraverse_Thr(BiThrTree T) {// 中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
    if (T) {
        BiThrTree p = T;
        p = p->lchild;
        while (p!=NULL) {//最后遍历的节点rchild指向的NULL
            while (p->LTag==0)
                p = p->lchild;
            printf("%c", p->data);
            while (p->RTag == 1 && (p->rchild != T||i++==0)) {//这个i防止第一次遍历根结点时进不去循环（不是一开始在根结点）
                p = p->rchild;
                printf("%c", p->data);
            }
            p = p->rchild;
        }
    }
}


//#include<iostream>
//using namespace std;
//
//typedef struct BiThrNode
//{
//    char data;
//    struct BiThrNode *lchild,*rchild;
//    int LTag,RTag;
//}BiThrNode,*BiThrTree;
//
//
//BiThrNode *pre=new BiThrNode;
//
//void CreateBiTree(BiThrTree &T)
//{
//    char ch;
//    cin >> ch;
//    if(ch=='#')  T=NULL;
//    else
//    {
//        T=new BiThrNode;
//        T->data=ch;
//        CreateBiTree(T->lchild);
//        CreateBiTree(T->rchild);
//    }
//}
//
//void InThreading(BiThrTree p);
//void InOrderTraverse_Thr(BiThrTree T);
//
//int main()
//{
//    pre->RTag=1;
//    pre->rchild=NULL;
//    BiThrTree tree;
//    CreateBiTree(tree);
//    InThreading(tree);
//    InOrderTraverse_Thr(tree);
//    return 0;
//}
///* 请在这里填写答案 */
//void InThreading(BiThrTree p){
//    if(p){
//        InThreading(p->lchild);
//        if(!p->lchild){
//            p->LTag=1;
//            p->lchild=pre;
//        }
//        if(!pre->rchild){
//            pre->rchild=p;
//            pre->RTag=1;
//        }
//        pre=p;
//        InThreading(p->rchild);
//    }
//}
//void InOrderTraverse_Thr(BiThrTree T) {// 中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
//    if (T) {
//        BiThrTree p = T;
//        p = p->lchild;
//        while (p!=NULL) {//最后遍历的节点rchild指向的NULL
//            while (p->LTag==0&&p->data!='A')//由于头节点LTag=0，这样从B->A重新来循环的时候，此处又进循环，这样就无限循环。
//                p = p->lchild;
//            printf("%c", p->data);
//            while (p->RTag == 1 && p->rchild != T) {
//                p = p->rchild;
//                printf("%c", p->data);
//            }
//            p = p->rchild;
//        }
//    }
//}