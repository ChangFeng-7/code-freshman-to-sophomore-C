//输入一些单词及其出现的频度，构造一棵哈夫曼树，输出哈夫曼编码的平均码长。
//输入格式:
//输入N，表示有N个单词，以下N行，每一行表示一个单词及其频度。
//输出格式:
//平均码长用浮点数类型表示，保留小数点后5位。
//输入样例:
//在这里给出一组输入。例如：
//11
//The 1192
//of 677
//a 541
//to 518
//and 462
//that 242
//he 195
//is 190
//for 157
//His 138
//are 124
//输出样例:
//在这里给出相应的输出。例如：
//3.10437

//没写出来，妈的
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
typedef struct{
    int rchild,lchild;
    int weight;
    int parent;
}HTNode,*HuffmanTree;
typedef struct Node{
    string s;
    int weight;
}*dot,**point;
int avghuffmanCode(point Nodes,int n);
void select(HuffmanTree &Tree,int n,int &s1,int &s2);
int main(){
    int n;
    cin>>n;
    point Nodes=(point)malloc(sizeof(dot)*n);
    for(int i=0;i<n;i++){
        Nodes[i]=(dot)malloc(sizeof(Node));
        cin>>Nodes[i]->s;
        cin>>Nodes[i]->weight;
    }
    avghuffmanCode(Nodes,n);
    return 0;
}
int avghuffmanCode(point Nodes,int n){
    HuffmanTree Tree=(HuffmanTree)malloc(sizeof(HTNode)*2*n);
    int i;
    float HuffmanLongth[n];
    //初始化叶子结点
    for(i=1;i<n+1;i++){
        Tree[i].weight=Nodes[i-1]->weight;
        Tree[i].rchild=0;
        Tree[i].lchild=0;
        Tree[i].parent=0;
    }
    //初始化其他节点
    for(;i<2*n;i++){
        Tree[i].weight=0;
        Tree[i].rchild=0;
        Tree[i].lchild=0;
        Tree[i].parent=0;
    }
    //构造哈夫曼树
    for(i=n+1;i<=2*n;i++){
        int s1,s2;
        select(Tree,i,s1,s2);
        Tree[s1].parent=i;
        Tree[s2].parent=i;
        Tree[i].rchild=s1;
        Tree[i].lchild=s2;
        Tree[i].weight=Tree[s1].weight+Tree[s2].weight;
    }
    //从叶子到根逆向求哈夫曼编码
    for(i=1;i<=n;i++){
        int p,f;
        float num=0;
        for(f=i,p=Tree[f].parent,num=0;p!=0;f=p,p=Tree[f].parent){
            if(Tree[p].parent==0) break;
            num++;
        }
        HuffmanLongth[i-1]=num;
    }
    float sum=0;
    for(i=0;i<n;i++){
        sum+=HuffmanLongth[i];
    }
    printf("%.5f",sum/i);
    return 0;
}
void select(HuffmanTree &Tree,int n,int &s1,int &s2){
    s1=s2=0;
    int i;
    Tree[s1].weight=Tree[s2].weight=INT_MAX;
    for(i=0;i<n;i++){
        if(Tree[i].parent==0){
            if(Tree[i].weight<Tree[s1].weight){
                s2=s1;
                s1=i;
            }else if(Tree[i].weight<Tree[s2].weight){
                s2=i;
            }
        }
    }
    if(s1>s2){//为了和教材保持一致，保持s1<s2
        s1^=s2^=s1^=s2;
    }
}