//给定一个中缀表达式，请编写程序计算该表达式的值。表达式包含+、-、*、\、(、)，所有运算均为二元运算，
//操作数均为正整数，但可能不止一位，不超过5位。运算结果为整数，值域为[−2^31,2^31)。
//除法运算结果若为小数则进行截尾取整。若除法运算中除数为0，则输出ILLEGAL。
//输入格式:
//输入为一个字符串，表示中缀表达式。
//输出格式:
//输出为一个整数，为表达式的值；或者为一个字符串ILLEGAL。
//输入样例1:
//5+(10*2)-6
//输出样例1:
//19
//输入样例2:
//8*(999+1)
//输出样例2:
//8000
//输入样例3:
//1+5/(1-1)
//输出样例3:
//ILLEGAL
//算法：
//1.从左到右进行遍历
//2.运算数,直接输出.
//3.左括号,直接压入堆栈,(括号是最高优先级,无需比较)(入栈后优先级降到最低,确保其他符号正常入栈)
//4.右括号,(意味着括号已结束)不断弹出栈顶运算符并输出直到遇到左括号(弹出但不输出)
//5.运算符,将该运算符与栈顶运算符进行比较,
//如果优先级高于栈顶运算符则压入堆栈(该部分运算还不能进行),
//        如果优先级低于等于栈顶运算符则将栈顶运算符弹出并输出,然后比较新的栈顶运算符.
//(低于弹出意味着前面部分可以运算,先输出的一定是高优先级运算符,等于弹出是因为同等优先级,从左到右运算)
//直到优先级大于栈顶运算符或者栈空,再将该运算符入栈.
//6.如果对象处理完毕,则按顺序弹出并输出栈中所有运算符.
#include <stdio.h>
#include <math.h>
int compare(char x,char y);
int figure(int x,char n,int y);
int judge(char x);
int main(){
    char a[300];//主字符串
    char ch[300];//字符栈
    int num[300];//数字栈
    int i=0;
    int m=0,n=0;//字符栈指针、数字栈指针
    for(i=0;i<300;i++){
        a[i]='\0';
        ch[i]='\0';
        num[i]=0;
    }
    gets(a);
    int step=0;
    for(i=0;a[i]!='\0';i++){//处理数字
        if(judge(a[i])){
            step=a[i]-'0';
            while(judge(a[++i])!=0){
                step=step*10+(a[i]-'0');
            }
            num[n++]=step;
        }
        if(judge(a[i])!=1&&a[i]!='\0'){//处理字符
            if(a[i]=='('){
                ch[m++]='(';
                continue;
            }
            if(m==0)//如果符号栈为空，则直接入栈
            {
                ch[m++]=a[i];
                continue;
            }else if(compare(a[i],ch[m-1])){//如果优先级大于栈顶字符优先级，直接入栈。
                ch[m++]=a[i];
                continue;
            }
            else if(a[i]==')'){//如果读x到右括号
                while(ch[m-1]!='('){
                    if(ch[m-1]=='/'&&num[n-1]==0){
                        printf("ILLEGAL\n");
                        return 0;
                    }
                    num[n-2]=figure(num[n-2],ch[m-1],num[n-1]);
                    num[n-1]=0;
                    n--;
                    m--;
                }
                m--;
                continue;
            }else if(!compare(a[i],ch[m-1]))
            {//如果小于栈顶字符优先级，直接进行计算。

                while(!compare(a[i],ch[m-1])) {
                    if(ch[m-1]=='(') break;
                    if(ch[m-1]=='/'&&num[n-1]==0){
                        printf("ILLEGAL\n");
                        return 0;
                    }
                    num[n - 2] = figure(num[n - 2], ch[m - 1], num[n - 1]);//没读到右括号
                    num[n-1]=0;
                    n--;
                    m--;
                    if(m==0){break;}
                }
                ch[m++]=a[i];
            }
        }
    }
    while(n!=1&&m>0)//在遍历了整个字符串之后如果两个栈还没有空  那么继续 (一旦数字栈里只剩一个数字 或者运算符栈没有符号了 那就停止计算)
    {
        if(ch[m-1]=='/'&&num[n-1]==0){
            printf("ILLEGAL\n");
            return 0;
        }
        num[n-2]=figure(num[n-2],ch[m-1],num[n-1]);
        num[n-1]=0;
        n--;
        m--;
    }
    printf("%d",num[0]);//输出结果
}
int compare(char x,char y){
    int m=0,n=0;
    if(x=='+'||x=='-'){
        m=1;
    }
    if(x=='*'||x=='/'){
        m=2;
    }
    if(x=='^'){
        m=3;
    }
    if(x=='('){
        m=0;
    }
    if(y=='+'||y=='-'){
        n=1;
    }
    if(y=='*'||y=='/'){
        n=2;
    }
    if(y=='^'){
        n=3;
    }
    if(y=='('){
        n=0;
    }
    if(x==')') return 0;
    if(m>n){ return 1; }
    else return 0;
}
int figure(int x,char n,int y){
    if(n=='+') return x+y;
    if(n=='-') return x-y;
    if(n=='*') return x*y;
    if(n=='/') return x/y;
    if(n=='^') return pow(x,y);
}
int judge(char x){
    if(x>='0'&&x<='9') return 1;
    return 0;
}