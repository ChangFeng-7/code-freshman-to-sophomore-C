#include <iostream>

using namespace std;

bool win(string &g, char u) {
    // TODO: ������С����С����Խ����Ƿ��������u������������true��ʾu��ʤ��
    return false;
}

int eval(string &g, char a, char b, int r) {
    // ���������桢��ǰ���֡��Է���ʣ��ո�
    if (win(g, a)) { return (r + 1); }
    if (win(g, b)) { return -(r + 1); } // ��ǰ�������bʤ������a��˵���Ǹ��֡�
    int best = -9; // ��ʼ���ɲ����ܵķ�������ʤʱ˫������Ҫ��5�ӣ�ʣ4��գ�����-9�֣�
    for (int i = 0; i < 9; ++i) {
        /* TODO:
        ����ÿ���հ�
          ����ǰ����a���ӣ�
          ������ɫ���Զ��ֽ�ɫ������ֵ÷֣��ݹ����eval����
          ��ô���·����ֵ÷�ȡ�������ҷ��÷֡�
          ����÷ָ��ߣ�����best��
          �ָ��հ�
        */
    }
    // ���bestû���޸ģ�˵���޿տ��£�ƽ�֡�
    return best == -9 ? 0 : best;
}

int main() {
    for (string g; cin >> g;) {
        // TODO: ͳ��X��O������ȷ����ǰ����a������b��ִ���ַ���
        char a = '?'; // TODO: ��ǰ���֡�XO������ͬʱ�ֵ�X�£�����O�¡�
        char b = '?'; // TODO: �Է����֡���a�෴��
        int r = 0;    // TODO: ͳ�ƿհ�������
        cout << a << ' ' << eval(g, a, b, r) << endl;
    }
}



//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//bool win(string& g, char u){
//    // TODO: ������С����С����Խ����Ƿ��������u������������true��ʾu��ʤ��
//    if( (g[0] == u && g[1] == u && g[2] == u) ||
//        (g[3] == u && g[4] == u && g[5] == u) ||
//        (g[6] == u && g[7] == u && g[8] == u) ||
//        (g[0] == u && g[3] == u && g[6] == u) ||
//        (g[1] == u && g[4] == u && g[7] == u) ||
//        (g[2] == u && g[5] == u && g[8] == u) ||
//        (g[0] == u && g[4] == u && g[8] == u) ||
//        (g[2] == u && g[4] == u && g[6] == u) )
//        return true;
//    return false;
//}
//
//int stat(string& g, char c){
//    return std::count(g.begin(), g.end(), c);    //ͳ���ַ���g���ַ�c�ĸ���
//}
//
//int eval(string& g, char a, char b, int r){
//    // ���������桢��ǰ���֡��Է���ʣ��ո�
//    if(win(g, a)){ return  (r + 1); }
//    if(win(g, b)){ return -(r + 1); } // ��ǰ�������bʤ������a��˵���Ǹ��֡�
//    int best = -9; // ��ʼ���ɲ����ܵķ�������ʤʱ˫������Ҫ��5�ӣ�ʣ4��գ�����-9�֣�
//    for(int i = 0; i < 9; ++i){
//        /* TODO:
//        ����ÿ���հ�
//            ����ǰ����a���ӣ�
//            ������ɫ���Զ��ֽ�ɫ������ֵ÷֣��ݹ����eval����
//            ��ô���·����ֵ÷�ȡ�������ҷ��÷֡�
//            ����÷ָ��ߣ�����best��
//            �ָ��հ�
//        */
//        if( g[i] == '.' ){
//            g[i] = a;
//            int t = -eval(g, b, a, r-1);
//            if(t > best) best = t;
//            g[i] = '.';
//        }
//    }
//    // ���bestû���޸ģ�˵���޿տ��£�ƽ�֡�
//    return best == -9 ? 0 : best;
//}
//
//int main(){
//    for(string g; cin >> g;){
//        // TODO: ͳ��X��O������ȷ����ǰ����a������b��ִ���ַ���
//        int x = stat(g, 'X');
//        int o = stat(g, 'O');
//        char a = '?'; // TODO: ��ǰ���֡�XO������ͬʱ�ֵ�X�£�����O�¡�
//        char b = '?'; // TODO: �Է����֡���a�෴��
//        if( x == o) {
//            a = 'X';
//            b = 'O';
//        } else {
//            a = 'O';
//            b = 'X';
//        }
//        int r = stat(g, '.');   // TODO: ͳ�ƿհ�������
//        cout << a << ' ' << eval(g, a, b, r) << endl;
//    }
//
//}
//
