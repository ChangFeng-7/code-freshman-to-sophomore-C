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
//cin �����˴��пո���ַ�����������س�
//cin.get()���Զ�����пո���ַ�������������س�
//getline()���Զ�����пո���ַ������������ջس�
//gets()���Զ����Ʊ���Ϳո񣬶����س��������Ҳ���ɻس����롣
//scanf %s���Զ����������ַ������м��޿ո񣩣��пո�Ļ��������hello world:scanf("%s %s",str1);
