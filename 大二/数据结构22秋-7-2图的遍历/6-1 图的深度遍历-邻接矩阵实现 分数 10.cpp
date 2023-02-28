#include"stdio.h"
#include"stdlib.h"
typedef enum{FALSE,TRUE} Boolean;
#define MaxVertexNum 10     /*定义最大顶点数*/
typedef int Vertex;/* 用顶点下标表示顶点,为整型 */
typedef struct{
    int arcs[MaxVertexNum][MaxVertexNum]; /*邻接矩阵*/
    int vexnum,arcnum; /*图中的顶点数vexnum和边数arcnum*/
}MGraph; /*用邻接矩阵表示的图的类型*/
Boolean visited[MaxVertexNum]; /* 顶点的访问标记 */
void CreatMGraph(MGraph *G);/* 创建图并且将Visited初始化为false；裁判实现，细节不表 */
void DFS(MGraph G,Vertex v);
int main()
{
    Vertex v;
    MGraph G;
    CreatMGraph(&G);
    scanf("%d", &v);
    printf("DFS from %d:",v);
    DFS(G,v);
    return 0;
}
/* 你的代码将被嵌在这里 */

void DFS(MGraph G,Vertex v){
    int i,j;
    visited[v]=TRUE;
    printf(" %d",v);
    for(j=0;j<G.vexnum;j++){
        if(visited[j]==0&&G.arcs[v][j]) DFS(G,j);
    }
}