//本题要求计算单链表倒数n个结点的乘积。例如，给出单链表1 2 3 4 5，则倒数2个结点的乘积为20。
//输入格式:
//输入有2行，第一个行为2个非负整数m和n。其中m为链表结点个数，n为链表倒数结点的数量。题目保证计算结果在int范围内。
//第二行为链表的m个数，以空格分隔.
//输出格式:
//在一行中输出倒数n个结点的乘积。
//输入样例:
//5 2
//1 2 3 4 5
//输出样例:
//20
//样例解释：
//20 = 4 * 5
#include <iostream>
using namespace std;
typedef struct ListNode{
    int m;
    struct ListNode *Next;
}*point,List;
int main(){
    int n,num,i=0;
    cin>>n>>num;
    int sum=1;
    point p;
    p=(point)malloc(sizeof(ListNode));
    cin>>p->m;
    point q,head;
    q=p;
    for(i=1;i<n;i++){
        p=(point)malloc(sizeof(ListNode));
        cin>>p->m;
        p->Next=q;
        q=p;
    }
    head=p;
    if(num==0) { cout << "0";  return 0;}
    for(i=0;i<num;i++){
        sum*=p->m;
        p=p->Next;
    }
    cout<<sum;
}
