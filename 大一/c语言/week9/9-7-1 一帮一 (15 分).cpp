//��һ��һѧϰС�顱����Сѧ�г�����ѧϰ��֯��ʽ����ʦ��ѧϰ�ɼ���ǰ��ѧ����ѧϰ�ɼ������ѧ������һ�顣
//����������д���������ʦ�Զ����������乤�������ڵõ�ȫ��ѧ�����������ڵ�ǰ��δ�����ѧ���У��������ǰ��ѧ����������������ѧ����Ϊһ�顣
//�����ʽ��
//�����һ�и�����ż��N����50������ȫ��ѧ�����������˺�N�У��������δӸߵ��͵�˳�����ÿ��ѧ�����Ա�0����Ů����1������������������������8��Ӣ����ĸ�ķǿ��ַ�������
// �����1���ո�ָ������ﱣ֤������Ů������1:1������û�в������Ρ�
//�����ʽ��
//ÿ�����һ������ѧ���������������1���ո�ָ������θߵ�ѧ����ǰ�����ε͵�ѧ���ں�С������˳����ǰ��ѧ�������δӸߵ������С�
//����������
//8
//0 Amy
//1 Tom
//1 Bill
//0 Cindy
//0 Maya
//1 John
//1 Jack
//0 Linda
//���������
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
//֮��İ汾��
//һ��һ
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