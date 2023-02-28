#include <stdio.h>
#include <iostream>
using namespace std;
#define MVNum 100
typedef struct{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
void CreateUDN(AMGraph &G);
int main(){
    AMGraph G;
    int i , j,sum=0;
    CreateUDN(G);
    for(i = 0 ; i < G.vexnum ; ++i){
        sum=0;
        for(j = 0; j < G.vexnum; ++j){
            if(G.arcs[i][j]==1)
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

void CreateUDN(AMGraph &G){
    int i=0,j=0;
    cin>>G.vexnum>>G.arcnum;
    cin>>G.vexs;
    int num;
    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
            G.arcs[i][j]=0;
        }
    }
    for(num=0;num<G.arcnum;num++){
        char a,b;
        int x,y;
        cin>>a>>b;
        for(j=0;j<G.vexnum;j++){
            if(G.vexs[j]==a){
                x=j;
            }
            if(G.vexs[j]==b){
                y=j;
            }
        }
        G.arcs[x][y]=G.arcs[y][x]=1;
    }
}