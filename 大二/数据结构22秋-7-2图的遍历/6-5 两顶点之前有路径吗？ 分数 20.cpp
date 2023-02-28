#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 20   /* 最大顶点数设为20 */
struct Graph{
    int v;  // amount of vertices
    int Adj[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
int visited[MaxVertexNum]; /* 顶点的访问标记 */
struct Graph* CreateGraph(){
    int v;
    scanf("%d",&v);
    struct Graph* g;
    g =(Graph*)malloc(sizeof(struct Graph));
    if(!g) return NULL;
    g->v = v;
    for(int i=0; i<v; i++){
        visited[i] = 0;
        for(int j=0; j<v; j++)
            scanf("%d",&(g->Adj[i][j]));
    }
    return g;
}
int hasPath(struct Graph *g, int v, int w);
int main(){
    struct Graph* g;
    g = CreateGraph();
    int v,w;
    scanf("%d%d", &v, &w);
    printf("%s\n", hasPath(g,v,w) ? "Yes" : "No");
    return 0;
}
/* 你的代码将被嵌在这里 */
int count=0;
void dfs(int n,struct Graph* g)
{
    visited[n]=1;
    count++;
    for(int j=0;j<g->v;j++)
    {
        if(g->Adj[n][j]==1)
        {
            if(!visited[j])
            {
                dfs(j,g);
            }
        }
    }
}
int hasPath(struct Graph *g, int v, int w){
    for(int i=0;i<g->v;++i)
        visited[i]=0;
    dfs(v,g);
    printf("%d\n",count);
    if(visited[w]==0){
        for(int i=0;i<g->v;++i)
            visited[i]=0;
        count=0;
        dfs(w,g);
        printf("%d\n",count);
        return 0;
    }
    else printf("%d\n",count);
    return 1;
}