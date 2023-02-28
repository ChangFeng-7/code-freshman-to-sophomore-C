#include <stdio.h>
#define MVNum 100                 //最大顶点数
typedef struct{
    char vexs[MVNum];           //存放顶点的一维数组
    int arcs[MVNum][MVNum];     //邻接矩阵
    int vexnum,arcnum;          //图的当前顶点数和弧数
}MGraph;
void indegree(MGraph G);
void CreatMGraph(MGraph *G);/* 创建图 */
int main()
{
    MGraph G;
    CreatMGraph(&G);
    indegree(G);
    return 0;
}
void CreatMGraph(MGraph *G)
{
    int i,j,k;
    scanf("%d%d",&G->vexnum,&G->arcnum);
    getchar();
    for(i=0;i<G->vexnum;i++)
        scanf("%c",&G->vexs[i]);
    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=0;
    for(k=0;k<G->arcnum;k++)
    {
        scanf("%d%d",&i,&j);
        G->arcs[i][j]=1;
    }
}

/* 请在这里填写答案 */
void indegree(MGraph G){
    int inDegree[4];
    int sum=0;
    for(int j=0;j<4;j++){
        for(int i=0,sum=0;i<4;i++){
            if(G.arcs[i][j]==1){
                sum++;
            }
        }
        inDegree[j]=sum;
    }
    for(int i=0;i<4;i++){
        printf("%c:%d\n",G.vexs[i],inDegree[i]);
    }
}