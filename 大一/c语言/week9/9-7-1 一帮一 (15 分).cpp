//“一帮一学习小组”是中小学中常见的学习组织方式，老师把学习成绩靠前的学生跟学习成绩靠后的学生排在一组。
//本题就请你编写程序帮助老师自动完成这个分配工作，即在得到全班学生的排名后，在当前尚未分组的学生中，将名次最靠前的学生与名次最靠后的异性学生分为一组。
//输入格式：
//输入第一行给出正偶数N（≤50），即全班学生的人数。此后N行，按照名次从高到低的顺序给出每个学生的性别（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），
// 其间以1个空格分隔。这里保证本班男女比例是1:1，并且没有并列名次。
//输出格式：
//每行输出一组两个学生的姓名，其间以1个空格分隔。名次高的学生在前，名次低的学生在后。小组的输出顺序按照前面学生的名次从高到低排列。
//输入样例：
//8
//0 Amy
//1 Tom
//1 Bill
//0 Cindy
//0 Maya
//1 John
//1 Jack
//0 Linda
//输出样例：
//Amy Jack
//Tom Linda
//Bill Maya
//Cindy John
#include <stdio.h>
#include <stdbool.h>

struct student {
    bool i = 1;
    char name[9];
};

int main() {
    int n, j = 0;
    scanf("%d", &n);
    struct student num[n];
    while (j < n) {
        scanf("%d %s", &num[j].i, num[j].name);
        j++;
    }
    j = 0;
    int nan = n - 1, nv = n - 1;
    while (j <= (n / 2 - 1)) {
        printf("%s ", num[j].name);
        if (num[j].i == 0) {
            while (nan > 0) {
                if (num[nan].i == 1) {
                    printf("%s\n", num[nan].name);
                    nan--;
                    break;
                }
                nan--;
            }
        }
        if (num[j].i == 1) {
            while (nv > 0) {
                if (num[nv].i == 0) {
                    printf("%s\n", num[nv].name);
                    nv--;
                    break;
                }
                nv--;
            }
        }
        j++;
    }
    return 0;
}
//之后的版本：
//一帮一
//#include <stdio.h>
//
//struct stu {
//    int num;
//    char name[9];
//};
//
//int main() {
//    int n, i = 0;
//    scanf("%d", &n);
//    struct stu a[n];
//    while (i < n) {
//        scanf("%d %s", &a[i].num, a[i].name);
//        i++;
//    }
//    i = 0;
//    int x = n - 1, y = n - 1;
//    while (i <= (n / 2 - 1)) {
//        if (a[i].num == 1) {
//            while (a[x].num != 0) {
//                x--;
//            }
//            printf("%s %s\n", a[i].name, a[x].name);
//            x--;
//            i++;
//        } else if (a[i].num == 0) {
//            while (a[y].num != 1) {
//                y--;
//            }
//            printf("%s %s\n", a[i].name, a[y].name);
//            y--;
//            i++;
//        }
//    }
//    return 0;
//}