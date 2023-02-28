//算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间。
//请设计程序将中缀表达式转换为后缀表达式。
//输入格式:
//输入在一行中给出不含空格的中缀表达式，可包含+、-、*、\以及左右括号()，表达式不超过20个字符。
//输出格式:
//在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。
//输入样例:
//2+3*(7-4)+8/4
//输出样例:
//2 3 7 4 - * + 8 4 / +
#include <stdio.h>
void change(char *a);
int compare(char a,char b);
int judge(char a);
int main(){
    char a[20];
    int i;
    for(i=0;i<20;i++){
        a[i]='\0';
    }
    gets(a);
    change(a);
    return 0;
}
int compare(char a,char b){
    int x,y;
    if(a=='+'||a=='-') x=0;
    if(a=='*'||a=='/') x=1;
    if(a=='(') x=0;
    if(a=='^') x=3;
    if(a=='@') x=0;
    if(b=='+'||a=='-') y=0;
    if(b=='*'||a=='/') y=1;
    if(b=='(') y=0;
    if(b=='^') y=3;
    if(x>y) return 0;
    return 1;
}
int judge(char a){
    if((a>='0'&&a<='9')||a=='.') return 1;
    return 0;
}
void change(char *a){
    char ch[20]={'@'};  int m=1;//用于储存暂时不能放入后缀字符串中的运算符。
    char back[40]; int n=0;//后缀字符串。
    int i=0;
    for(i=0;i<40;i++){
        back[i]='\0';
    }
    i=0;
    int step=0;
    while(a[i]!='\0'){
        if(n==0&&(a[0]=='-'||a[0]=='+')){
            back[n++]=a[i++];
            continue;
        }
        if(judge(a[i])){ //如果是数字，直接输入。
            if((a[i+1]>='0'&&a[i+1]<='9')||a[i+1]=='.'){//如果超过一位整数或者是小数
                while(judge(a[i])) {
                    back[n++]=a[i++];
                }
                back[n++]=' ';
                continue;
            }
            back[n++] = a[i];
            back[n++]=' ';
            i++;
            continue;
        }
        else{/*是运算符的情况*/
            if(a[i]=='('){//左括号直接进字符栈，进栈后其优先级为0，确保其他运算符进栈
                if(!judge(a[i+1])){//对于这种：-3.14+2.33*(-4.231)-1.2-24/(+6.01/2)
                    i++;
                    back[n++]=a[i++];
                    if((a[i+1]>='0'&&a[i+1]<='9')||a[i+1]=='.'){//如果超过一位整数或者是小数
                        while(judge(a[i])) {
                            back[n++]=a[i++];
                        }
                        back[n++]=' ';
                    }
                    if(a[i]==')'){//(-1.9)到这结束
                        i++;//略过')'
                        continue;
                    }
                    ch[m++]='(';
                }
                ch[m++]=a[i];
                i++;
                continue;
            }
            if(a[i]==')'){//如果右括号，则输入左括号之后的所有运算符进入back。
                while(ch[m-1]!='('){
                    back[n++]=ch[--m];
                    back[n++]=' ';
                }
                m--;
                i++;
                continue;
            }
            if(compare(ch[m-1],a[i])){//如果字符栈栈顶运算符优先级小于输入的运算符，则说明输入的运算符还有操作数没读取，则入栈。
                ch[m++]=a[i];
                i++;
                continue;
            }else if(!compare(ch[m-1],a[i])){//若小于栈顶字符优先级，则说明栈顶字符a的操作数已全部进入back，则a出栈
                while((!compare(ch[m-1],a[i]))||ch[m-1]==a[i]){//直到待定字符的优先级比栈顶的大，则输入待定字符。
                    back[n++]=ch[m-1];
                    back[n++]=' ';
                    m--;
                }
                ch[m++]=a[i];
                i++;
                continue;
            }
        }
    }
    if(m!=1){
        while(m!=1){
            back[n++]=ch[--m];
            back[n++]=' ';
        }
    }
    i=0;
    if(n==1) printf("%c",back[0]);
    i=0;
    while(back[i]!='\0'){
        printf("%c",back[i++]);
        if(back[i+1]=='\0'){
            break;
        }
    }
    return;
}