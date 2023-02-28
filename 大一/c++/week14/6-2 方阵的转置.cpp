#include <iostream>
using namespace std;
class Matrix{
public:
    int a[3][3];
    int b[3][3]={0};
    void input();
    void show();
    void transform();
    Matrix(){a[3][3]={0};}
};

void Matrix::show() {
    int i,j;
    cout<<"datas:"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
}
void Matrix::input() {
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
}
void Matrix::transform() {
    int c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=b[j][i];
        }
    }
}
int main(){
    Matrix m;
    m.input();
    m.show();
    m.transform();
    m.show();
}