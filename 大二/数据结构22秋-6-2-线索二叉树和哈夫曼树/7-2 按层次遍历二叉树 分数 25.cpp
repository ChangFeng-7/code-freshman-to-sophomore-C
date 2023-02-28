//以字符串的形式定义一棵二叉树的先序序列，若字符是‘#’, 表示该二叉树是空树，否则该字符是相应结点的数据元素。
//读入相应先序序列，建立二叉树，然后按层次遍历该二叉树并输出结点数据。
//输入格式:
//字符串形式的先序序列（即结点的数据类型为单个字符）
//输出格式:
//按层次遍历二叉树的结果
//输入样例:
//在这里给出一组输入。例如：
//ABDG##HI####CE#J##F##
//输出样例:
//在这里给出相应的输出。例如：
//ABCDEFGHJI
#include<iostream>
using namespace std;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag;
}BiThrNode,*BiThrTree;
BiThrTree creatTree(BiThrTree &T){
    char a;
    cin>>a;
    if(a=='#'){
        T=NULL;
    }else{
        T=(BiThrTree)malloc(sizeof(BiThrNode));
        T->data=a;
        creatTree(T->lchild);
        creatTree(T->rchild);
    }
}
void printfTraverse(BiThrTree T){
    int in=0,out=0;
    BiThrTree a[100];
    if(!T) return;
    a[in++]=T;
    while(in>out){
        if(a[out]){
            printf("%c",a[out]->data);
            a[in++]=a[out]->lchild;
            a[in++]=a[out]->rchild;
        }
        out++;
    }
}
int main(){
    BiThrTree T;
    creatTree(T);
    printfTraverse(T);
    return 0;
}