//人的DNA和病毒DNA均表示成由一些字母组成的字符串序列。然后检测某种病毒DNA序列是否在患者的DNA序列中出现过，
//如果出现过，则此人感染了该病毒，否则没有感染。例如，假设病毒的DNA序列为baa，患者1的DNA序列为aaabbba，
//则感染，患者2的DNA序列为babbba，则未感染。（注意，人的DNA序列是线性的，而病毒的DNA序列是环状的)
//输入格式:
//输入第一行中给出1个整数i(1≤i≤11)，表示待检测的病毒DNA和患者DNA的对数。
//输入i行串序列，每行由两个字符串组成（字符串中不含不可见字符），两字符串之间用一个空格分隔，
//分别代表病毒的DNA序列和患者的DNA序列，病毒的DNA序列和患者的DNA序列长度不超过500。
//输出格式:
//依次逐行输出每对检测样本的结果，感染输出：YES，未感染输出：NO。
//输入样例1:
//1
//baa bbaabbba
//输出样例1:
//YES
//输入样例2:
//2
//cced cdccdcce
//bcd aabccdxdxbxa
//输出样例2:
//YES
//NO
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string virus,human,c;
        cin>>virus>>human;
        int sum=virus.size();
        int temp=0;
        for(int i=0;i<sum;i++)
        {
            for(int j=i,k=0;k<sum;k++,j++)
            {
                c=c+virus[(j+sum)%sum];//c记录的是每一种不同组合的病毒序列
            }
            int temp1=human.find(c,0);
            /*find()函数：从位置0开始找含c的序列，找不到就返回-1
            找得到就返回第一次出现的位置*/
            if(temp1!=-1)
            {
                temp++;
                break;
            }
            c.clear();// 每次只比较一种组合
        }

        if(temp!=0) cout<<"YES";
        else cout<<"NO";

        if(n) cout<<endl;
    }
    return 0;
}
