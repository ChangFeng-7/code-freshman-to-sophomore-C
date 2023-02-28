//假设以S和X分别表示入栈和出栈操作。如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，
//相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。
//输入格式:
//输入第一行给出两个正整数N和M，其中N是待测序列的个数，M（≤50）是堆栈的最大容量。随后N行，
//每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。
//输出格式:
//对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。
//输入样例：
//4 10
//SSSXXSXXSX
//SSSXXSXXS
//SSSSSSSSSSXSSXXXXXXXXXXX
//SSSXXSXXX
//输出样例：
//YES
//NO
//NO
//NO
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string str;
    int n, m;
    cin >> n >> m;
    getchar();
    while (n--){
        int cnt = 0;
        str.clear();
        getline(cin, str);

        int flag = 0;
        for (int i = 0; i < str.length(); i++){
            if (str[i] == 'X')cnt--;
            if (str[i] == 'S')cnt++;

            if (cnt < 0 || cnt>m){
                flag = 1; break;
            }
        }
        if (cnt != 0)flag = 1;
        if (cnt == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}