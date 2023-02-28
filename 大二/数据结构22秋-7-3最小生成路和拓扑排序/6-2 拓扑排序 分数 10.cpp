#include <iostream>
#include <stack>
using namespace std;

#define MVNum 100
typedef char VerTexType;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VerTexType data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];

typedef struct{
    AdjList vertices; //邻接表
    AdjList converse_vertices;//逆邻接表
    int vexnum, arcnum;
}ALGraph;

int CreateUDG(ALGraph &G);//创建图，实现细节隐藏
void FindInDegree(ALGraph G,int indegree[]);
int TopologicalSort(ALGraph G , int topo[]);

int main(){
    ALGraph G;
    CreateUDG(G);
    int *topo = new int [G.vexnum];
    if(TopologicalSort(G , topo)){
        for(int j = 0 ; j < G.vexnum; j++){
            if(j != G.vexnum - 1)
                cout << G.vertices[topo[j]].data << ",";
            else
                cout << G.vertices[topo[j]].data ;
        }
    }
    else
        cout << "Ring in net";
    return 0;
}
/* 请在这里填写答案 */
//试实现拓扑排序算法。函数void FindInDegree(ALGraph G,int indegree[])实现图中各个顶点入度的统计；
//函数int TopologicalSort(ALGraph G , int topo[])获取拓扑序列。
//其中 G 是基于邻接表及逆邻接表存储表示的有向图，indegree存放个顶点的入度，topo存放拓扑序列。
void FindInDegree(ALGraph G,int indegree[]){
    for(int i=0;i<G.vexnum;i++){
        indegree[i]=0;
    }
    for(int i=0;i<G.vexnum;i++){
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p!=NULL){
            indegree[p->adjvex]++;
            p=p->nextarc;
        }
    }
}
int TopologicalSort(ALGraph G , int topo[]){
    int *indegree=new int[G.vexnum];
    FindInDegree(G,indegree);
    stack<int> s1;
    int i=0;
    for(i=0;i<G.vexnum;i++){
        if(!indegree[i]) s1.push(i);
    }
    int count=0;
    ArcNode *p;
    while(!s1.empty()){
        i=s1.top();
        s1.pop();
        topo[count]=i;
        for(p=G.vertices[i].firstarc;p!=NULL;p=p->nextarc){
            indegree[p->adjvex]--;
            if(!indegree[p->adjvex]) s1.push(p->adjvex);
        }
    }
    if(count<G.vexnum) return 0;
    else return 1;
}