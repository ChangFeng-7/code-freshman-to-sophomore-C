//N个人围成一圈顺序编号，从1号开始按1、2、3......顺序报数，报p者退出圈外，其余的人再从1、2、3开始报数，报p的人再退出圈外，以此类推。
//请按退出顺序输出每个退出人的原序号。
//输入格式:
//输入只有一行，包括一个整数N(1<=N<=3000)及一个整数p(1<=p<=5000)。
//输出格式:
//按退出顺序输出每个退出人的原序号，数据间以一个空格分隔，但行尾无空格。
//输入样例:
//在这里给出一组输入。例如：
//7 3
//输出样例:
//3 6 2 7 5 1 4
#include <iostream>
using namespace std;
struct stu{
    int num;
    struct stu *next;
    struct stu *prior;
};
int main(){
    int num,m;
    cin>>num>>m;
    int i;
    struct stu *p=(struct stu *)malloc(sizeof(struct stu));
    struct stu *q;
    struct stu *head;
    for(i=1;i<num+1;i++){
        p=(struct stu *)malloc(sizeof(struct stu));
        if(i==1){
            head=p;
            p->num=i;
            q=p;
            continue;
        }
        p->num=i;
        q->next=p;
        p->prior=q;
        q=p;
    }
    q->next=head;
    head->prior=q;
    q=p=head;
    while(p->next!=p){
        for(i=0;i<m-1;i++){
            p=p->next;
        }
        printf("%d ",p->num);
        p->prior->next=p->next;
        p->next->prior=p->prior;
        p=p->next;
    }
    printf("%d",p->num);
    return 0;
}