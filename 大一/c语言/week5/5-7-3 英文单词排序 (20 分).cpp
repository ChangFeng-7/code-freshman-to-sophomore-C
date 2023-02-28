//本题要求编写程序，输入若干英文单词，对这些单词按长度从小到大排序后输出。如果长度相同，按照输入的顺序不变。
//输入格式：
//输入为若干英文单词，每行一个，以#作为输入结束标志。其中英文单词总数不超过20个，英文单词为长度小于10的仅由小写英文字母组成的字符串。
//输出格式：
//输出为排序后的结果，每个单词后面都额外输出一个空格。
//输入样例：
//blue
//red
//yellow
//green
//purple
//#
//输出样例：
//red blue green yellow purple
#include <string.h>
#include <stdio.h>
int main(){
    int i,j,n;
    char a[20][10],b;
    for(i=0;a[i]!="#";i++){
        scanf("%s",&a[i]);
    }
    n=i;
    for(i=n;i!=0;i--){
        for(j=1;j!=i;j++){
            if(strlen(a[i])<strlen(a[j])){
                b=a[i];
                a[i]=a[j];
                a[j]=a[i];
            }
        }
    }
    printf("%s ",a);
    return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char str[20][10],t[20],temp[20];
//    int i=0,j;
////  for(i=0;str[i]!='#';i++){
////        scanf("%s",&str[i]);
////    }注：这样不行，二维数组不能这么比较。
//    while(1)
//    {
//        scanf("%s",&temp);
//        if(temp[0]!='#')
//        {
//            strcpy(str[i],temp);
//            i++;
//        }
//        else
//            break;
//    }
//    int n=i;
//    for(i=0;i<n-1;i++)
//        for(j=0;j<n-i-1;j++)
//        {
//            if(strlen(str[j])>strlen(str[j+1]))
//            {
//                strcpy(t,str[j]);
//                strcpy(str[j],str[j+1]);
//                strcpy(str[j+1],t);
//            }
//        }
//    for(i=0;i<n;i++)
//    {
//        printf("%s ",str[i]);
//    }
//    return 0;
//}