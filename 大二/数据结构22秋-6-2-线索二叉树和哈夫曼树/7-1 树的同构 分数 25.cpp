//给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，
//因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
//现给定两棵树，请你判断它们是否是同构的。
//输入格式:
//输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；
//随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，
//则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
//输出格式:
//如果两棵树是同构的，输出“Yes”，否则输出“No”。
#include <iostream>
using namespace std;
typedef struct{
    char data;
    char lchild;
    char rchild;
}Tree,*TreePoint,**point;
int judge(point T1,point T2,int n1,int n2);
point CreateTree(int n);
int main(){
    int n1;
    cin>>n1;
    point T1=CreateTree(n1);
    int n2;
    cin>>n2;
    point T2=CreateTree(n2);
    judge(T1,T2,n1,n2);
    return 0;
}
point CreateTree(int n){
    point T=(point)malloc(sizeof(TreePoint)*n);
    for(int i=0;i<n;i++){
        T[i]=(TreePoint)malloc(sizeof(Tree));
        cin>>T[i]->data;
        cin>>T[i]->lchild;
        cin>>T[i]->rchild;
    }
    return T;
}
int compare(point T1,point T2,int t1,int t2){
    if(T1[t1]->data==T2[t2]->data) return 1;
    else return 0;
}
int judge(point T1,point T2,int n1,int n2){
    if(n1!=n2){cout<<"No"; return 0;}
    if(n1==1&&n2==1){
        if(T1[0]->data==T2[0]->data) { cout << "Yes";return 0; }
        else { cout << "No"; return 0;}
    }
    int flag=1;
    for(int i=0;i<n1&&flag==1;i++){
        int j=0;
        for(j=0;j<n2;j++){
            if(T2[j]->data==T1[i]->data){
                break;
            }
        }
        char a,b,x,y;
        a=T1[i]->lchild;
        b=T1[i]->rchild;
        x=T2[j]->lchild;
        y=T2[j]->rchild;
        if(a=='-'&&b=='-'&&x=='-'&&y=='-') continue;
        if(a=='-'&&x=='-'&&b!='-'&&y!='-') {
            flag = compare(T1, T2, b - '0', y - '0');
            continue;
        }
        if(b=='-'&&y=='-'&&a!='-'&&x!='-') {
            flag = compare(T1, T2, a - '0', x - '0');
            continue;
        }
        if(b=='-'&&x=='-'&&a!='-'&&y!='-'){
            flag=compare(T1,T2,a-'0',y-'0');
            continue;
        }
        if(a=='-'&&y=='-'&&b!='-'&&x!='-'){
            flag=compare(T1,T2,a-'0',y-'0');
            continue;
        }
        if(a!='-'&&b!='-'&&x!='-'&&y!='-') {
            if(!(compare(T1, T2, b - '0', y - '0')||compare(T1,T2,a-'0',y-'0'))){flag=0; continue;};
            if(!(compare(T1,T2,a-'0',x-'0')|| compare(T1,T2,b-'0',x-'0'))){flag=0;continue;}
            continue;
        }
        flag=0;
    }
    if(flag==1){cout<<"Yes"; return 0;}
    if(flag==0){ cout<<"No"; return 0;}
}














