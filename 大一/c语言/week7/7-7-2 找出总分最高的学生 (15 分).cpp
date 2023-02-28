//给定N个学生的基本信息，包括学号（由5个数字组成的字符串）、姓名（长度小于10的不包含空白字符的非空字符串）和3门课程的成绩（[0,100]区间内的整数），要求输出总分最高学生的姓名、学号和总分。
//输入格式：
//输入在一行中给出正整数N（≤10）。随后N行，每行给出一位学生的信息，格式为“学号 姓名 成绩1 成绩2 成绩3”，中间以空格分隔。
//
//输出格式：
//在一行中输出总分最高学生的姓名、学号和总分，间隔一个空格。题目保证这样的学生是唯一的。
//
//输入样例：
//5
//00001 huanglan 78 83 75
//00002 wanghai 76 80 77
//00003 shenqiang 87 83 76
//10001 zhangfeng 92 88 78
//21987 zhangmeng 80 82 75
//输出样例：
//zhangfeng 10001 258
#include <stdio.h>
#include <stdlib.h>
struct stu{
    char num[6];
    char name[11];
    int score1;
    int score2;
    int score3;
    struct stu *next;
};
int main(){
    struct stu *head,*p1,*p2,*pt;
    int n,i=1;
    scanf("%d",&n);
    head=p1=p2=(struct stu*)malloc(sizeof(struct stu));
    scanf("%s %s %d %d %d",p1->num,p1->name,&p1->score1,&p1->score2,&p1->score3);
    while(i<n){
        p1=(struct stu*)malloc(sizeof(struct stu));
        scanf("%s %s %d %d %d",p1->num,p1->name,&p1->score1,&p1->score2,&p1->score3);
        p2->next=p1;
        p2=p1;
        i++;
    }
    p2->next=NULL;
    int max=0;
    pt=head;
    while(head!=NULL){
        if((head->score1+head->score2+head->score3)>max)
            pt=head;
        max=(head->score1+head->score2+head->score3);
        head=head->next;
    }
    printf("%s %s %d",pt->name,pt->num,pt->score1+pt->score2+pt->score3);
    return 0;
}