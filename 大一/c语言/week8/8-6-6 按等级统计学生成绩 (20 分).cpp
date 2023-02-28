#include <stdio.h>
#define MAXN 10
struct student{
    int num;
    char name[20];
    int score;
    char grade;
};
int set_grade( struct student *p, int n );
int main()
{   struct student stu[MAXN], *ptr;
    int n, i, count;
    ptr = stu;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
    }
    count = set_grade(ptr, n);
    printf("The count for failed (<60): %d\n", count);
    printf("The grades:\n");
    for(i = 0; i < n; i++)
        printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
    return 0;
}
/* 你的代码将被嵌在这里 */
int set_grade( struct student *p, int n ){
    int set_grade( struct student *p, int n )
    {
        int count=0,i;
        for(i=0;i<n;i++)
        {
            if((*p).score<60)
            {
                (*p).grade='D';
                count++;
            }
            else if((*p).score>=60&&(*p).score<=69)
                (*p).grade='C';
            else if((*p).score>=70&&(*p).score<=84)
                (*p).grade='B';
            else
                (*p).grade='A';
            p++;
        }
        return count;
    }
}