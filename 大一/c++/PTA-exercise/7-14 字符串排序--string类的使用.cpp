#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void sort(string *a,int n)
{
    int i,j;
    string temp;
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-1-i;++j)
        {
            if(a[j].size()>a[j+1].size())
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
int main()
{
    int n,i,j=0;
    string temp;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        string *p=NULL;
        p=new string[n];
        for(i=0;i<n;++i)
        {
            getline(cin,temp);
            if(temp!="stop")
            {
                p[j]=temp;
                j++;
            }
            else
            {
                break;
            }
        }
        sort(p,j);
        for(i=0;i<j;++i)
        {
            cout<<p[i]<<endl;
        }
        delete[] p;
        j=0;
        temp="";
    }
    return 0;
}
//cin 读不了带有空格的字符串，不会读回车
//cin.get()可以读入带有空格的字符串，但不会读回车
//getline()可以读入带有空格的字符串，最后会吸收回车
//gets()可以读入制表符和空格，读到回车结束，且不会吧回车读入。
//scanf %s可以读入连续的字符串（中间无空格），有空格的话比如读入hello world:scanf("%s %s",str1);
