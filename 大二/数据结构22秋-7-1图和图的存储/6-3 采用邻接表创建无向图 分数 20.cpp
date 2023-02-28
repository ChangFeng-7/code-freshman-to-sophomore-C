#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MVNum 100
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int info;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];

typedef struct{
    VNode vertices[MVNum];
    int vexnum, arcnum;
}ALGraph;

void CreateUDG(ALGraph &G);

int main(){
    ALGraph G;
    int i , j,sum=0;
    CreateUDG(G);
    ArcNode * p;
    for(i = 0 ; i < G.vexnum ; ++i){
        sum=0;
        p=G.vertices[i].firstarc;
        for(; p!=NULL; p=p->nextarc){
            sum+=1;
        }
        if(i==0)
            printf("%d",sum);
        else
            printf(" %d",sum);
    }
    return 0;
}

/* 请在这里填写答案 */
void CreateUDG(ALGraph &G){
    cin>>G.vexnum>>G.arcnum;
    int i,j;
    for(i=0;i<G.vexnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    for(i=0;i<G.arcnum;i++){
        char c1,c2;
        int x,y;
        cin>>c1>>c2;
        for(int j=0; j<G.vexnum; j++){
            if(G.vertices[j].data==c1)
                x = j;
            if(G.vertices[j].data==c2)
                y = j;
        }
        //头插法
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = y;
        p->nextarc = G.vertices[x].firstarc;
        G.vertices[x].firstarc = p;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = x;
        p->nextarc = G.vertices[y].firstarc;
        G.vertices[y].firstarc = p;
    }
}