#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
    struct stud_node *p;

    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
void input(){
    struct stud_node *p=(struct stud_node *)malloc(sizeof(struct stud_node));
    struct stud_node *q=NULL;
    int num;
    int score;
    char name;
    scanf("%d",&num);
    if(num==0) return;
    p->num=num;
    head=p;
    q=p;
    scanf("%s %d",&p->name,&p->score);
    while(1){
        scanf("%d",&num);
        if(num!=0){
            p=(struct stud_node *)malloc(sizeof(struct stud_node));
            p->num=num;
            scanf("%s %d",&p->name,&p->score);
            q->next=p;
            q=p;
            continue;
        }
        break;
    }
    tail=q;
    return;
}
