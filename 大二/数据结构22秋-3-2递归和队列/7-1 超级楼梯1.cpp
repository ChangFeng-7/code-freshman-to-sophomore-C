//有一超级楼梯，共无限级。刚开始时你在地面，你可以一步跨上第一级，也可以一步跨上第二级。
//假设你每次只能向上跨一级或二级，那么你要走上第N级，共有多少种走法？
//Input:
//每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
//Output:
//对于每个测试实例，请输出不同走法的数量
//Sample Input
//2
//5
//8
//Sample Output
//2
//8
//34
#include <iostream>
using namespace std;
int how(int x);
int main(){
    int N;
    int num;
    cin>>N;
    while(N>=1&&N<=40){
        num=how(N);
        cout<<num<<endl;
        cin>>N;
    }
    return 0;
}
int how(int x){
    int num=0;
    if(x>=0) {
        num=how(x-1)+how(x-2);
    }else{
        return num;
    }
}