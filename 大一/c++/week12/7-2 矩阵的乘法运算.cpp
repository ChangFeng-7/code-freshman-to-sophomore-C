//答案
//#include<iostream>
//#include <iomanip>
//using namespace std;
//class Matrix
//{
//public:
//    Matrix(int, int);
//    ~Matrix();
//    friend istream& operator>>(istream&is, Matrix&a);
//    int getRow(){return row;}
//    int getColum(){return column;}
//    friend Matrix operator*(Matrix&, Matrix&);
//    Matrix(const Matrix&);
//    void display();
//private:
//    int row;
//    int column;
//    int** mat;
//};
//Matrix::Matrix(int r, int c)
//{
//    row = r;
//    column = c;
//    mat = new int*[r+2];
//    for(int i = 0; i < row+2; i++)
//    {
//        mat[i] = new int[c+2];
//    }
//}
//Matrix::~Matrix()
//{
//    for(int i = 0; i <row+2; i++)
//        delete []mat[i];
//    delete []mat;
//}
//istream& operator>>(istream & is, Matrix & a){
//    for(int i=0; i<a.row; i++)
//    {
//        for(int j=0; j<a.column; j++)
//        {
//            is>>a.mat[i][j];
//        }
//    }
//}
//Matrix operator*(Matrix&a, Matrix&b){
//    int i,j,k,x;
//    if(a.row==1&&a.column==1)
//    {
//        Matrix p (b.row,b.column);
//        for(i=0;i<b.row;i++){
//            for(j=0;j<b.column;j++){
//                p.mat[i][j]=a.mat[0][0]*b.mat[i][j];
//            }
//        }
//        return p;
//    }
//    else
//    {
//        Matrix p (a.row,b.column);
//        for(i=0; i<a.row; i++)
//        {
//            for(j=0; j<b.column; j++)
//            {
//                x=0;
//                for(k=0; k<a.column; k++)
//                {
//                    x+=a.mat[i][k]*b.mat[k][j];
//                }
//                p.mat[i][j]=x;
//            }
//        }
//        return p;
//    }
//}
//Matrix::Matrix(const Matrix&p){
//    this->row=p.row;
//    this->column=p.column;
//    this->mat=new int* [p.row+2];
//    int i,j;
//    for(i=0; i<p.row+2; i++)
//    {
//        this->mat[i]=new int [p.column+2];
//        for(j=0; j<p.column; j++)
//        {
//            this->mat[i][j]=p.mat[i][j];
//        }
//    }
//}
//void Matrix::display(){
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<column; j++)
//        {
//            cout<<setw(10)<<mat[i][j];
//        }
//        cout<<endl;
//    }
//}
//int main()
//{
//    int a,b,i,j;
//    cin>>a>>b;
//    Matrix x(a,b);
//    cin>>x;
//    cin>>a>>b;
//    Matrix y(a,b);
//    cin>>y;
//    if(x.getColum()==y.getRow()||x.getColum()==1&&x.getRow()==1||y.getRow()==1&&y.getRow()==1) {
//
//        Matrix z=x*y;
//        z.display();
//    }
//    else{
//        cout<<"Invalid Matrix multiplication!";
//    }
//    return 0;
//}
//矩阵的乘法运算
//自己写的，改错改了好久。。。
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix{
private:
    int row;
    int column;
    int **mat;
public:
    int getRow(){return row;}//4
    int getColum(){return column;}//5
    ~Matrix(){
        int i=0;
        for(i=0;i<row+2;i++)
            delete []mat[i];
        delete []mat;
    }

    Matrix(int r,int c){
        row=r;
        column=c;
        int i;
        mat=new int*[r+2];
        for(i=0;i<r+2;i++){
            mat[i]=new int[c+2];
        }
    }
    friend istream & operator >>(istream &is,Matrix &a){
        int i,j;
        for(i=0;i<a.row;i++){
            for(j=0;j<a.column;j++){
                is>>a.mat[i][j];
            }
        }
    }
    friend Matrix operator *(Matrix &a,Matrix &b){//这一行不要写成：friend Matrix & operator *(Matrix &a,Matrix &b){
        int sum=0;
        int i,j;
        if(a.row==1&&a.column==1)//数乘矩阵
        {
            Matrix p (b.row,b.column);
            for(i=0;i<b.row;i++){
                for(j=0;j<b.column;j++){
                    p.mat[i][j]=a.mat[0][0]*b.mat[i][j];
                }
            }
            return p;
        }
        else {
            Matrix p(a.row,b.column);
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < b.column; j++) {
                    sum = 0;
                    for (int k = 0; k < a.column; k++) {//这一行写成b.column了。。。。
                        sum += a.mat[i][k] * b.mat[k][j];
                    }
                    p.mat[i][j] = sum;
                }
            }
            return p;
        }
    }
    void display(){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<setw(10)<<mat[i][j];
            }
            cout<<endl;
        }
    }
    Matrix(const Matrix&p);
};
Matrix::Matrix(const Matrix&p){
    this->row=p.row;
    this->column=p.column;
    this->mat=new int* [p.row+2];
    int i,j;
    for(i=0; i<p.row+2; i++)
    {
        this->mat[i]=new int [p.column+2];
        for(j=0; j<p.column; j++)
        {
            this->mat[i][j]=p.mat[i][j];
        }
    }
}
int main(){
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    Matrix m1(r1,c1);
    cin>>m1;
    cin>>r2>>c2;
    Matrix m2(r2,c2);
    cin>>m2;
    if(m1.getColum()==m2.getRow()||m1.getColum()==1&&m1.getRow()==1||m2.getRow()==1&&m2.getRow()==1) {
        Matrix z=m1*m2;//其实复制构造函数根本没用到，这里是自带的赋值。。。要用到的话应该写成Matrix z(m1*m2);
        z.display();
    }else{
        cout<<"Invalid Matrix multiplication!"<<endl;
    }
    return 0;
}