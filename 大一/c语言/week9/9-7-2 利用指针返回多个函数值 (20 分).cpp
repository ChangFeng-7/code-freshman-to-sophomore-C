//����n������������max_min()��������n�����е����ֵ����Сֵ��
//�����ʽ:
//���������У�
//��һ����nֵ��
//�ڶ�����n������
//�����ʽ:
//������ֵ����Сֵ��
//��������:
//���������һ�����롣���磺
//5
//8 9 12 0 3
//�������:
//�����������Ӧ����������磺
//max = 12
//min = 0
#include <stdio.h>
int main(){
    int n,i=0;
    scanf("%d",&n);
    int a[n];
    while(i<n) scanf("%d",&a[i++]);
    int max_min(int *a,int n);
    max_min(a,n);
    return 0;
}
int max_min(int *a,int n){
    int i,j,max;
    for(i=n;i!=0;i--) {
        for (j = 1; j != i; j++) {
            if (a[j-1] > a[j]) {
                max=a[j-1];
                a[j - 1] = a[j];
                a[j] = max;
            }
        }
    }
    printf("max = %d\nmin = %d",a[n-1],a[0]);
    return 0;
}