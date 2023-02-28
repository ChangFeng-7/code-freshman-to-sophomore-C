//试实现普里姆最小生成树算法。
//
//函数接口定义：
//void Prim(AMGraph G, char u);
//其中 G 是基于邻接矩阵存储表示的无向图，u表示起点
//输入样例：
//第1行输入结点数vexnum和边数arcnum。第2行输入vexnum个字符表示结点的值，接下来依次输入arcnum行，
// 每行输入3个值，前两个字符表示结点，后一个数表示两个结点之间边的权值。最后一行输入一个字符表示最小生成树的起始结点。
//
//7 9
//0123456
//0 1 28
//0 5 10
//1 2 16
//1 6 14
//2 3 12
//3 6 18
//3 4 22
//4 5 25
//4 6 24
//0
//输出样例：
//按最小生成树的生成顺序输出每条边。
//
//0->5
//5->4
//4->3
//3->2
//2->1
//1->6
#include <iostream>
#define MVNum 10
#define MaxInt 32767
using namespace std;

struct edge{
    char adjvex;
    int lowcost;
}closedge[MVNum];

typedef struct{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
int LocateVex(AMGraph G , char v);//实现细节隐藏
int Min(AMGraph G);//实现细节隐藏
int CreateUDN(AMGraph &G);//实现细节隐藏

void Prim(AMGraph G, char u);

int main(){
    AMGraph G;
    CreateUDN(G);
    char u;
    cin >> u;
    Prim(G , u);
    return 0;
}

/* 请在这里填写答案 */
void Prim(AMGraph G, char u){
    int k= LocateVex(G,u);
    int i=0,j=0;
    for(i=0;i<G.vexnum;i++){//辅助数组初始化
        if(i!=k){
            closedge[i]={u,G.arcs[k][i]};
        }
    }
    closedge[k].lowcost=0;
    int u0,v0;
    for(i=1;i<G.vexnum;i++){
        k=Min(G);
        u0=closedge[k].adjvex;
        v0=G.vexs[k];
        printf("%d->%d\n",u0-48,v0-48);
        closedge[k].lowcost=0;
        for(j=0;j<G.vexnum;j++){
            if(G.arcs[k][j]<closedge[j].lowcost){
                closedge[j]={G.vexs[k],G.arcs[k][j]};
            }
        }
    }
}