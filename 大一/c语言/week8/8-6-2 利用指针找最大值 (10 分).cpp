//����Ҫ��ʵ��һ���򵥺������ҳ��������е����ֵ��
//�����ӿڶ��壺
//void findmax( int *px, int *py, int *pmax );
//����px��py���û����������������ָ�롣����findmaxӦ�ҳ�����ָ����ָ��������е����ֵ�������pmaxָ���λ�á�
//����������
//3 5
//���������
//5
#include <stdio.h>
void findmax( int *px, int *py, int *pmax );
int main()
{
    int max, x, y;
    scanf("%d %d", &x, &y);
    findmax( &x, &y, &max );
    printf("%d\n", max);
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
void findmax( int *px, int *py, int *pmax ){
    int max;
    if(*px>*py) max=*px;
    if(*px<*py) max=*py;
    *pmax=max;
}