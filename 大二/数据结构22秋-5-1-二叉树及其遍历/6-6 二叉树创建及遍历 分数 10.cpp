#include<iostream>
using namespace std;
typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);//根据输入的字符串，创建二叉树。
void PreOrder(BiTree T);//先序遍历二叉树
void InOrder(BiTree T);//中序遍历二叉树
void PostOrder(BiTree T);//后序遍历二叉树
void LevelOrder(BiTree T);//层次遍历二叉树

int main(){
    BiTree T;
    CreateBiTree(T);
    cout<<"PreOrder:";
    PreOrder(T);
    cout<<endl<<"InOrder:";
    InOrder(T);
    cout<<endl<<"PostOrder:";
    PostOrder(T);
    cout<<endl<<"LevelOrder:";
    LevelOrder(T);
    return 0;
}
/* 请在这里填写答案 */
#include<queue>
void CreateBiTree(BiTree &T)//根据输入的字符串，创建二叉树。
{
    char ch;
    cin>>ch;
    if(ch=='#') T = NULL;
    else{
        T =(BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PreOrder(BiTree T)//先序遍历二叉树
{
    if(T==NULL) return;
    cout<<T->data;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}
void InOrder(BiTree T)//中序遍历二叉树
{
    if(T==NULL) return;
    InOrder(T->lchild);
    cout<<T->data;
    InOrder(T->rchild);
}
void PostOrder(BiTree T)//后序遍历二叉树
{
    if(T==NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    cout<<T->data;
}
void LevelOrder(BiTree T)//层次遍历二叉树
{
    queue<BiTree> q;
    if(T) q.push(T);
    while(!q.empty()){
        BiTree front = q.front();
        cout<<front->data;
        q.pop();
        if(front->lchild){
            q.push(front->lchild);
        }
        if(front->rchild){
            q.push(front->rchild);
        }
    }
}

//自己写的
//void CreateBiTree(BiTree &T){//根据输入的字符串，创建二叉树。
//    char ch;
//    cin>>ch;
//    if(ch=='#') T=NULL;
//    else{
//        T = (BiTree) malloc(sizeof(BiTNode));
//        T->data = ch;
//        CreateBiTree(T->lchild);
//        CreateBiTree(T->rchild);
//    }
//}
//void PreOrder(BiTree T){//先序遍历二叉树
//    if(T){
//        cout<<T->data;
//        PreOrder(T->lchild);
//        PreOrder(T->rchild);
//    }
//}
//void InOrder(BiTree T){//中序遍历二叉树
//    if(T){
//        InOrder(T->lchild);
//        cout<<T->data;
//        InOrder(T->rchild);
//    }
//}
//void PostOrder(BiTree T){//后序遍历二叉树
//    if(T){
//        PostOrder(T->lchild);
//        PostOrder(T->rchild);
//        cout<<T->data;
//    }
//}
//void LevelOrder(BiTree T){//层次遍历二叉树
//    BiTree q[100];
//    int out=0,in=0;
//    if(T) q[in++]=T;
//    while(in>out){
//        if(q[out]){
//            cout<<q[out]->data;
//            q[in++]=q[out]->lchild;
//            q[in++]=q[out]->rchild;
//        }
//        out++;
//    }
//}
