//本题要求将键盘输入的学生信息创建成单向链表，并在学生信息链表中查找学生信息。
//学生信息链表结点定义如下：
//typedef struct List{
//    　　int sno;
//    　　char sname[10];
//    　　List *next;
//};　
//需要创建的函数包括：
//创建学生信息链表函数：CreateList
//        查找学生信息链表函数：Find
//        函数接口定义：
//List * CreateList();  //键盘输入若干学生学号和姓名，学号与姓名以空格符间隔，当输入的学号为-1时，输入结束，创建学生信息链表函数，返回学生链表的头指针。
//List * Find(List *head, int no)  //在学生信息链表（头指针为head）中查询学号为no的学生，返回该学生结点的指针。
//输入样例1：
//20180002 王红
//20180006 张勇
//20180008 吴涛
//20170010 林玉
//-1 xx
//20180002
//输出样例1：
//在这里给出相应的输出。例如：
//王红
//输入样例2：
//20180002 王红
//20180006 张勇
//20180008 吴涛
//20170010 林玉
//-1 xx
//20170015
//输出样例2：
//Not Found!
#include <stdio.h>
#include <stdlib.h>
typedef struct List{
       int sno;
    char sname[10];
    List *next;
};
List * CreateList();  //键盘输入若干学生学号和姓名，学号与姓名以空格符间隔，当输入的学号为-1时，输入结束，创建学生信息链表函数，返回学生链表的头指针。
List * Find(List *head, int no);  //在学生信息链表（头指针为head）中查询学号为no的学生，返回该学生结点的指针。
int main(void){
    List *list=NULL,*p;
    int no;
    list=CreateList();
    while(~scanf("%d", &no))
    {
        p=Find(list,no);
        if( p ) printf("%s\n", p->sname);
        else printf("Not Found!\n");
    }
    return 0;
}
/* 请在这里填写答案 *///这段代码把-1 XX也包括在链表内了，建议改一下。
List * CreateList(){
    List *p1,*p2,*pt,*head=NULL;
    head=p1=p2=(List*)malloc(sizeof(List));
    scanf("%d %s", &p1->sno, p1->sname);
    while(p1->sno!=-1){
        p2=(List*)malloc(sizeof(List));
        scanf("%d %s",&p2->sno,p2->sname);
        p1->next=p2;
        p1=p2;
    }
    p1->next=NULL;
    return head;
}
List * Find(List *head, int no){
    List *pt;
    pt=head;
    while(pt->sno!=no&&pt->sno!=-1){
        pt=pt->next;
    }
    if(pt->sno==-1) return 0;
    else return pt;
}