#include <iostream>

using namespace std;

bool win(string &g, char u) {
    // TODO: 检查三行、三列、两对角线是否出现棋手u的三连，返回true表示u获胜。
    return false;
}

int eval(string &g, char a, char b, int r) {
    // 参数：局面、当前棋手、对方、剩余空格。
    if (win(g, a)) { return (r + 1); }
    if (win(g, b)) { return -(r + 1); } // 当前局面如果b胜利，对a来说就是负分。
    int best = -9; // 初始化成不可能的分数（获胜时双方至少要下5子，剩4格空，不会-9分）
    for (int i = 0; i < 9; ++i) {
        /* TODO:
        尝试每个空白
          按当前棋手a落子，
          交换角色，以对手角色评估棋局得分（递归调用eval）。
          那么该下法对手得分取负就是我方得分。
          如果得分更高，更新best。
          恢复空白
        */
    }
    // 如果best没被修改，说明无空可下，平局。
    return best == -9 ? 0 : best;
}

int main() {
    for (string g; cin >> g;) {
        // TODO: 统计X、O数量，确定当前棋手a、对手b所执的字符。
        char a = '?'; // TODO: 当前棋手。XO数量相同时轮到X下，否则O下。
        char b = '?'; // TODO: 对方棋手。与a相反。
        int r = 0;    // TODO: 统计空白数量。
        cout << a << ' ' << eval(g, a, b, r) << endl;
    }
}



//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//bool win(string& g, char u){
//    // TODO: 检查三行、三列、两对角线是否出现棋手u的三连，返回true表示u获胜。
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
//    return std::count(g.begin(), g.end(), c);    //统计字符串g中字符c的个数
//}
//
//int eval(string& g, char a, char b, int r){
//    // 参数：局面、当前棋手、对方、剩余空格。
//    if(win(g, a)){ return  (r + 1); }
//    if(win(g, b)){ return -(r + 1); } // 当前局面如果b胜利，对a来说就是负分。
//    int best = -9; // 初始化成不可能的分数（获胜时双方至少要下5子，剩4格空，不会-9分）
//    for(int i = 0; i < 9; ++i){
//        /* TODO:
//        尝试每个空白
//            按当前棋手a落子，
//            交换角色，以对手角色评估棋局得分（递归调用eval）。
//            那么该下法对手得分取负就是我方得分。
//            如果得分更高，更新best。
//            恢复空白
//        */
//        if( g[i] == '.' ){
//            g[i] = a;
//            int t = -eval(g, b, a, r-1);
//            if(t > best) best = t;
//            g[i] = '.';
//        }
//    }
//    // 如果best没被修改，说明无空可下，平局。
//    return best == -9 ? 0 : best;
//}
//
//int main(){
//    for(string g; cin >> g;){
//        // TODO: 统计X、O数量，确定当前棋手a、对手b所执的字符。
//        int x = stat(g, 'X');
//        int o = stat(g, 'O');
//        char a = '?'; // TODO: 当前棋手。XO数量相同时轮到X下，否则O下。
//        char b = '?'; // TODO: 对方棋手。与a相反。
//        if( x == o) {
//            a = 'X';
//            b = 'O';
//        } else {
//            a = 'O';
//            b = 'X';
//        }
//        int r = stat(g, '.');   // TODO: 统计空白数量。
//        cout << a << ' ' << eval(g, a, b, r) << endl;
//    }
//
//}
//
