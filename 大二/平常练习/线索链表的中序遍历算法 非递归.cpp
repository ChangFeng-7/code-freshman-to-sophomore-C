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
//void InOrderTraver_Thr( BiThrTree T){
//    BiThrTree p=T;
//    p=p->lchild;//p指向根结点
//    while(p!=T){
//        while(p->LTag==Link) p=p->lchild;
//    }
//    printf("%c",p->data);
//    while(p->RTag==Thread&&p->rchild!=T){
//        p=p->rchild;
//        printf("%c",p->data);
//    }
//    p=p->rchild;
//}
void InOrderTraver_Thr( BiThrTree T){
    BiThrTree p=T;
    p=p->lchild;
    while(p!=T){
        while(p->LTag==Link){
            p=p->lchild;
        }
        printf("%c",p->data);
        while(p->RTag==Thread&&p->rchild!=T){
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}