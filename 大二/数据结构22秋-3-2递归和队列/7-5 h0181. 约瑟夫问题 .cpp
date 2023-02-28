//约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。
//就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
//输入格式:
//每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：
//0 0
//输出格式:
//对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号
//输入样例:
//6 2
//12 4
//8 3
//0 0
//输出样例:
//5
//1
//7
#include <iostream>
using namespace std;
int digui(int n,int m,int *a);
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int i=0;
    while(i<n){
        a[i++]=1;
    }
    while(n!=0) {
        digui(n,m,a);
        cin>>n>>m;
    }
}
int digui(int n,int m,int *a){
    int i=0,p=0;
    int num=n;
    if(n==1){
        int j=0;
        while(a[j++]==0);
        printf("%d",a[j-1]);
        return 0;
    }
    if(n<m){
        for(i=0;i<m;p++){
            if(p==num) p=0;
            if(a[p]==0) continue;
        }
        if(p==num) p=0;
        i++;
        a[p]=0;
        digui(--n,m,a);
        return 0;
    }
    for(i=0;i<m;p++){
        if(a[p]==0) continue;
        i++;
    }
    a[p]=0;
    digui(--n,m,a);
}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    int n,m;
//    while(~scanf("%d %d",&n,&m))
//    {
//        int a[310];
//        if(m==0&&n==0) break;
//        for(int j = 1;j<=n;j++)
//        {
//            a[j] = 1;
//        }
//        int count = 0;
//        int sum = n;
//        for(int i = 1;;)
//        {
//            if(sum==1) break;
//            if(a[i]!=0)
//            {
//                count++;
//                if(count==m)
//                {
//                    count = 0;
//                    a[i] = 0;
//                    sum--;
//                }
//            }
//            i++;
//            if(i==n+1) i = 1;
//        }
//        for(int j = 1;j<=n;j++)
//        {
//            if(a[j]==1)
//            {
//                printf("%d\n",j);
//                break;
//            }
//        }
//    }
//    return 0;
//}

