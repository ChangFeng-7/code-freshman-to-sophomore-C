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
void BFS(MGraph G,Vertex v);
int main()
{
    Vertex v;
    MGraph G;
    CreatMGraph(&G);
    scanf("%d", &v);
    printf("BFS from %d:",v);
    BFS(G,v);
    return 0;
}
/* 你的代码将被嵌在这里 */
//不知道哪里错了
void BFS(MGraph G,Vertex i){
    int stack[100];
    int in=0,out=0;
    visited[i]=TRUE;
    printf(" %d",i);
    stack[in++]=i;
    for(int j=0;j<100;j++){
        stack[j]=0;
    }
    while(in>out){
        i=stack[++out];
        for(int j=0;j<G.vexnum;j++){
            if(G.arcs[i][j]!=0&&visited[j]==FALSE){
                stack[in++]=j;
                visited[j]=TRUE;
                printf(" %d",i);
            }
        }
    }
}
//int q[100], front, rear;//front, rear双指针模拟队列
//void BFS(MGraph G,Vertex v) {//创作不易，点个赞吧，新春快乐~
//    q[rear++] = v;
//    visited[v] = 1;
//    while(rear > front) {
//        int x = q[front];//取出队首元素
//        printf(" %d", q[front++]);
//        for(int i=0; i<G.vexnum; i++) {
//            if(G.arcs[x][i]==1 && visited[i]==0) {
//                q[rear++] = i;
//                visited[i] = 1;
//            }
//        }
//    }
//    return ;
//}
