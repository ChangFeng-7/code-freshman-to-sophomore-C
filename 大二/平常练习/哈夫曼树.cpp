#include <iostream>
#include <limits>
using namespace std;
typedef struct{
    unsigned int weight;
    unsigned int parent;
    unsigned int lchild,rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;//一个元素是char*的指针数组
void select(HuffmanTree &HT,int n,int &s1,int &s2);
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
    if(n<=1) return;
    int m=2*n-1;
    HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));
    HuffmanTree p;
    int i;
    for(p=HT+1,i=1;i<=n;i++,p++,w++){//初始化前n个叶子结点
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
        p->weight=*w;
    }
    for(;i<=m;i++,p++){
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
        p->weight=0;
    }
    //建造哈夫曼树
    int s1,s2;
    for(i=n+1;i<=m;i++){
        select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    //从叶子到根逆向求哈夫曼编码
    HC=(HuffmanCode)malloc(sizeof(char*)*(n+1));
    char *cd=(char*)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    int c;
    for(i=1;i<=n;i++){
        int start=n-1;//编码结束符位置
        for(int c=i,f=HT[c].parent;f!=0;c=f,f=HT[f].parent){
            if(HT[f].rchild==c) cd[--start]='1';
            if(HT[f].lchild==c) cd[--start]='0';
        }
        HC[i]=(char*)malloc(sizeof(char)*(n-start));
        strcpy(HC[i],&cd[start]);
        printf("%s",HC[i]);
    }
    free(cd);
}
void select(HuffmanTree &HT,int n,int &s1,int &s2){
    int i;
//    s1=s2=INT_MAX;//#include <limits>
    s1=s2=0;
    HT[s1].weight=HT[s2].weight=INT_MAX;
    for(i=1;i<=n;i++){
        if(HT[i].parent==0){
            if(HT[i].weight<HT[s1].weight){
                s2=s1;
                s1=i;
            }else if(HT[i].weight<HT[s2].weight){
                s2=i;
            }
        }
    }
    if(s1>s2){//为了和教材保持一致，保持s1<s2
        s1^=s2^=s1^=s2;//s1<->s2,s1和s2互换
    }
    //这里有个有趣的方法是利用位运算进行交换值的操作。
    //首先有个原理需要知道：
    //若a^b=c,则c^b=a,c^a=b
    //那么就可以通过以下方式进行两个变量的交换
    //a=a^b;
    //b=a^b;
    //a=a^b;
}
