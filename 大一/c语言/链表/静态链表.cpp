#include <stdio.h>
struct student{
    int num;
    float score;
    struct student *next;
};
int main(){
    struct student a,b,c,*head,*p;
    scanf("%d %f",&a.num,&a.score);
    scanf("%d %f",&b.num,&b.score);
    scanf("%d %f",&c.num,&c.score);
    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    p=head;
    while(p!=NULL) {
        printf("%d %f\n", p->num, p->score);
        p = p->next;
    }
    return 0;
}