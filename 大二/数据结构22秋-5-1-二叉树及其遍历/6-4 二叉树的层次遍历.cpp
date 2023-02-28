
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree Create();/* 细节在此不表 */

void Levelorder(BiTree T);

int main()
{
    BiTree T = Create();
    printf("Levelorder:"); Levelorder(T); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void Levelorder(BiTree T){
    BiTree q[100];
    int in=0,out=0;
    if(T) {
        q[in++] = T;
        while (in > out) {
            if (q[out]) {
                printf(" %c", q[out]->data);
                q[in++] = q[out]->lchild;
                q[in++] = q[out]->rchild;
            }
            out++;
        }
    }
}
//void Levelorder(BiTree T){
//    BiTree nodes[100];//定义数组
//    int out=0, in=0;
//    nodes[in++] = T;//把根节点存入数组
//    while(in > out){//如果所有结点遍历完了则跳出循环
//        if(nodes[out]){//如果当前结点不为空
//            printf(" %c", nodes[out]->data);//则输出该结点的数据
//            nodes[in++] = nodes[out]->lchild;//将左子树根节点存入数组
//            nodes[in++] = nodes[out]->rchild;//将右子树根节点存入数组
//        }
//        out++;
//    }
//}