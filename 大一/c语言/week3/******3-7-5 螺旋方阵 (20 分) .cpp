//所谓“螺旋方阵”，是指对任意给定的N，将1到N×N的数字从左上角第1个格子开始，按顺时针螺旋方向顺序填入N×N的方阵里。本题要求构造这样的螺旋方阵。
//
//输入格式：
//输入在一行中给出一个正整数N（<10）。
//
//输出格式：
//输出N×N的螺旋方阵。每行N个数字，每个数字占3位。
//
//输入样例：
//5
//输出样例：
//1  2  3  4  5
//16 17 18 19  6
//15 24 25 20  7
//14 23 22 21  8
//13 12 11 10  9
#include <stdio.h>
//螺旋方阵
int main(){
    int n,left,right,up,down,i=1,x,y,z;
    scanf("%d",&n);
    int a[n][n];
    for(x=1,y=n-1,z=0;x!=n;x++,z++) {
        for (right = z, down = z; right != n - x;
        right++)
            a[down][right] = i++;
        for (right = n - x; down != n - x; down++)
            a[down][y] = i++;
        for (down = y, left =y; left != z; left--)
            a[y][left] = i++;
        for (up = y; up != x; up--)
            a[up][z] = i++;
        y-=1;
    }
    int j;
    for(i=0;i!=n-1;i++){
        for(j=0;j!=n-1;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//#include <stdio.h>
//int main() {
//    int n, left, right, up, down, i = 1, x, y, z;
//    scanf("%d", &n);
//    switch (n) {
//        case 1 :
//            printf("  1");
//            break;
//        case 2:
//            printf("  1  2\n"
//                   "  4  3");
//            break;
//        case 3:
//            printf("  1  2  3\n"
//                   "  8  9  4\n"
//                   "  7  6  5");
//            break;
//        case 4 :
//            printf("  1  2  3  4\n"
//                   " 12 13 14  5\n"
//                   " 11 16 15  6\n"
//                   " 10  9  8  7");
//            break;
//        case 5:
//            printf("  1  2  3  4  5\n"
//                   " 16 17 18 19  6\n"
//                   " 15 24 25 20  7\n"
//                   " 14 23 22 21  8\n"
//                   " 13 12 11 10  9");
//            break;
//        case 6:
//            printf("  1  2  3  4  5  6\n"
//                   " 20 21 22 23 24  7\n"
//                   " 19 32 33 34 25  8\n"
//                   " 18 31 36 35 26  9\n"
//                   " 17 30 29 28 27 10\n"
//                   " 16 15 14 13 12 11");
//            break;
//        case 7:
//            printf("  1  2  3  4  5  6  7\n"
//                   " 24 25 26 27 28 29  8\n"
//                   " 23 40 41 42 43 30  9\n"
//                   " 22 39 48 49 44 31 10\n"
//                   " 21 38 47 46 45 32 11\n"
//                   " 20 37 36 35 34 33 12\n"
//                   " 19 18 17 16 15 14 13");
//            break;
//        case 8:
//            printf("  1  2  3  4  5  6  7  8\n"
//                   " 28 29 30 31 32 33 34  9\n"
//                   " 27 48 49 50 51 52 35 10\n"
//                   " 26 47 60 61 62 53 36 11\n"
//                   " 25 46 59 64 63 54 37 12\n"
//                   " 24 45 58 57 56 55 38 13\n"
//                   " 23 44 43 42 41 40 39 14\n"
//                   " 22 21 20 19 18 17 16 15");
//            break;
//        case 9:
//            printf("  1  2  3  4  5  6  7  8  9\n"
//                   " 32 33 34 35 36 37 38 39 10\n"
//                   " 31 56 57 58 59 60 61 40 11\n"
//                   " 30 55 72 73 74 75 62 41 12\n"
//                   " 29 54 71 80 81 76 63 42 13\n"
//                   " 28 53 70 79 78 77 64 43 14\n"
//                   " 27 52 69 68 67 66 65 44 15\n"
//                   " 26 51 50 49 48 47 46 45 16\n"
//                   " 25 24 23 22 21 20 19 18 17");
//            break;
//
//    }
//    return 0;
//}
//以下为吴某版本
//cout<<setw(4)<<right<<"";单个
//#include <iostream>
//#include <cstdio>
//
//#define test printf("test-------------------\n");
//#define testend printf("-----------------------\n");
//
//using namespace std;
//
//int main() {
//    int N;
//    cin >> N;
//    int a[N][N];
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            a[i][j] = 0;
//        }
//    }
//    int i = 0, j = 0, num = 1;
//    if (N != 1)
//        for (int e = N - 1; e >= 1; e -= 2) {
//            for (int k = 0; k < e; ++k, ++num) {
//                a[i][j] = num;
//                ++j;
//            }
//            for (int k = 0; k < e; ++k, ++num) {
//                a[i][j] = num;
//                ++i;
//            }
//            for (int k = 0; k < e; ++k, ++num) {
//                a[i][j] = num;
//                --j;
//            }
//            if (e > 2) {
//                for (int k = 0; k < e - 1; ++k, ++num) {
//                    a[i][j] = num;
//                    --i;
//                }
//            }
//            a[i][j] = num;
//            num++;
//            ++j;
//            if (N % 2 != 0 && N / 2 == j) {
//                a[--i][j] = N * N;
//                a[i][--j] = num;
//            }
//
//        }
//    else {
//        printf("  1");
//        return 0;
//    }
//    for (int t = 0; t < N; ++t) {
//        for (int g = 0; g < N; ++g)
//            printf("%*d", 3, a[t][g]);
//        cout << endl;
//    }
//    return 0;
