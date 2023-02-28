#include"stdio.h"
#include"stdlib.h"
#define MAX_VERTEX_NUM 10      /*定义最大顶点数*/
typedef int Vertex;
typedef struct  ArcNode{       /*表结点*/
    int adjvex;               /*邻接点域*/
    struct  ArcNode *nextarc; /*指向下一个表结点*/
}ArcNode;
typedef struct VNode{           /*头结点*/
    Vertex data;                  /*顶点域*/
    ArcNode *firstarc;          /*指向第一个表结点*/
}VNode,AdjList[MAX_VERTEX_NUM]; /*AdjList是数组类型*/
typedef struct {
    AdjList vertices;           /*邻接表中数组定义*/
    int vexnum,arcnum;          /*图中当前顶点数和边数*/
} ALGraph;                 /*图类型*/
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MAX_VERTEX_NUM];/*定义标志向量，为全局变量*/
void CreatALGraph(ALGraph *G);/* 创建图并且将Visited初始化为false；裁判实现，细节不表 */
void DFS(ALGraph *G,int v);
int main()
{
    Vertex v;
    ALGraph G;
    CreatALGraph(&G);
    scanf("%d", &v);
    printf("DFS from %d:",v);
    DFS(&G,v);
    return 0;
}
/* 你的代码将被嵌在这里 */
void DFS(ALGraph *G,int i){
    visited[i]=TRUE;
    printf(" %d",i);
    ArcNode *p;
    p=G->vertices[i].firstarc;
    while(p!=NULL){
        if(visited[p->adjvex]==0){ DFS(G,p->adjvex); }
        p=p->nextarc;
    }
}