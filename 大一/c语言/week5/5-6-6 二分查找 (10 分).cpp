//本题要求实现一个函数，该函数采用二分查找法从一个已经升序排序的数组中，查找某个数k。
// 如果找到k, 输出k所在的数组下标（0~n-1）及比较次数。若k不存在，输出-1和比较次数。
//函数接口定义：
//int Search(int *p, int n, int k,int *Count);
//void Sort(int *,int n);
//其中 p为数组首地址，n为数组长度，k为待查找的数, *Count为比较次数。
//函数返回值：如果k在数组中返回其下标值，没找到返回-1。
//输入样例1：
//在这里给出一组输入。例如：
//5
//13 25 36 57 79
//25
//输出样例1：
//在这里给出相应的输出。例如：
//1
//3
//输入样例2：
//在这里给出一组输入。例如：
//5
//13 25 36 57 79
//10
//输出样例2：
//在这里给出相应的输出。例如：
//-1
//2
#include<stdio.h>
#define N 20
int Search(int *pa, int n, int k,int *p);
int main()
{
    int a[N],n,cmp,*p=&cmp;
    int pos,num=0;
    int i,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    pos=Search(a,n,k,p);
    printf("%d\n%d\n",pos,cmp);
    return 0;
}
/* 请在这里填写答案 */

int Search(int *p, int n, int k,int *Count)
{

    int low,high,mid;
    *Count=0;
    low=0;
    high=n-1;
    while(low<=high)
    {
        (*Count)++;
        mid=(low+high)/2;
        if(k<p[mid])
        {
            high=mid-1;
        }
        else if(k>p[mid])
        {
            low=mid+1;
        }
        else if(k==p[mid])
            return mid;
    }
    if(low>high)
        return -1;
}