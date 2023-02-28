//三元组顺序表表示的稀疏矩阵转置。
//输入格式:
//输入第1行为矩阵行数m、列数n及非零元素个数t。
//按行优先顺序依次输入t行，每行3个数，分别表示非零元素的行标、列标和值。
//输出格式:
//输出转置后的三元组顺序表结果，每行输出非零元素的行标、列标和值，行标、列标和值之间用空格分隔，共t行。
//输入样例1:
//3 4 3
//0 1 -5
//1 0 1
//2 2 2
//输出样例1:
//0 1 1
//1 0 -5
//2 2 2
#include<iostream>
using namespace std;
const int MAXSIZE=1000;
typedef struct
{
    int i,j;
    int e;
}triple;
typedef struct
{
    triple data[MAXSIZE+1];
    int mu,nu,tu;
}tsmatrix;
int inimatrix(tsmatrix &m)
{
    int m1,n,t;
    cin>>m1>>n>>t;
    if(m1>0&&n>0)
    {
        if(t<=MAXSIZE)
        {
            for(int k=1;k<=t;k++)
            {
                cin>>m.data[k].i>>m.data[k].j>>m.data[k].e;
                if(m.data[k].i>m1||m.data[k].j>n)return 0;
            }
        }
        else return 0;
    }
    else
    {
        m.mu=0;
        m.tu=0;
        m.nu=0;
    }
    m.mu=m1;
    m.nu=n;
    m.tu=t;
}

tsmatrix transpose(tsmatrix t)
{
    tsmatrix s;
    s.mu=t.nu;
    s.nu=t.mu;
    s.tu=t.tu;
    if(t.tu)
    {
        int col,num[t.tu],cpot[t.tu];
        for(col=0;col<t.nu;col++)
        {
            num[col]=0;
        }
        for(int i=1; i<=t.tu; i++)
        {
            num[t.data[i].j]++;
        }
        cpot[0]=1;
        for(col=1;col<=t.nu;col++)
        {
            cpot[col]=num[col-1]+cpot[col-1];
        }
        for(int p=1;p<=t.tu;p++)
        {
            col=t.data[p].j;
            int q=cpot[col];
            s.data[q].e=t.data[p].e;
            s.data[q].i=t.data[p].j;
            s.data[q].j=t.data[p].i;
            cpot[col]++;
        }
    }
    return s;
}
void display(tsmatrix t)
{
    for(int k=1;k<=t.tu;k++)
    {
        cout<<t.data[k].i<<" "<<t.data[k].j<<" "<<t.data[k].e<<endl;
    }
}
int main()
{
    tsmatrix t,s;
    inimatrix(t);
    s=transpose(t);
    display(s);
    return 0;
}

