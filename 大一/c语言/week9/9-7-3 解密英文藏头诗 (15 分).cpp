//����Ҫ���дһ������Ӣ�Ĳ�ͷʫ�ĳ��򡣽���ʹ�ö�̬�ڴ���䷽�������ַ��������롣
//�����ʽ:
//����Ϊһ��Ӣ�Ĳ�ͷʫ��ÿ��һ�У�С��20�У�ÿ�в�����80���ַ�����#��Ϊ��ͷʫ�����������־��
//�����ʽ:
//ȡ��ÿ��ĵ�һ���ַ���������һ���γ�һ���ַ����������
//��������:
//I come into a dream
//Leaves fall down but spring
//over a lake birds flying
//village have its nice morning
//everywhere can feel happiness
//Years have never been
//owners don't need anything
//until the sun bring another wind
//#
//�������:
//ILoveYou
#include <stdio.h>
int main(){
    char s[20][80];
    int i=0;
    scanf("%s\n",s[0]);
    for(i=1;s[i][0]!='#';i++){
        scanf("%s\n",s[i]);
    }
    int n=i;
    for(i=0;i<n;i++){
        printf("%c",s[i][0]);
    }
    return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//    char str[90];
//    int i,n=0;
//    gets(str);
//    while(str[0]!='#'){
//        printf("%c",str[0]);
//        gets(str);
//    }
//    return 0;
//}