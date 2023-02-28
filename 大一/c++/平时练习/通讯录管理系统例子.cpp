#include <iostream>
using namespace std;
const int MAX=1000;
//�����ϵ�˵Ľṹ��
struct Person
{
    //����
    string m_Name;
    //�Ա�
    int m_Sex;
    //����
    int m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
};
//�漰ͨѶ¼�Ľṹ��
struct Addressbooks
{
    //ͨѶ¼�б������ϵ�˵�����
    struct Person personArray[MAX];
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};
//1.�����ϵ��
void addPerson(Addressbooks *abs)
{
    //�ж�ͨѶ¼�Ƿ�������������ˣ��������
    if (abs->m_Size==MAX)
    {
        cout<<"ͨѶ¼�������޷���ӣ�"<<endl;
        return;
    }
    else
    {
        //1.��Ӿ�����ϵ��
        string name;
        cout<<"������������"<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;
        //�Ա�
        cout<<"�������Ա��ǣ�"<<endl;
        cout<<"1---��"<<endl;
        cout<<"2---Ů"<<endl;
        int sex=0;
        while (true)
        {
            //����������1����2�����˳�ѭ������Ϊ���������ȷֵ
            //����������������������
            cin>>sex;
            if (sex==1||sex==2)
            {
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"������������������";
        }
        //����
        cout<<"���������䣺"<<endl;
        int age=0;
        while (true)
        {
            //��������������0��100֮��Ϳ����˳�ѭ������Ϊ���������ȷֵ
            //����������������������
            cin>>age;
            if (age>0&&age<100)
            {
                abs->personArray[abs->m_Size].m_Age=age;
                break;
            }
            cout<<"������������������";
        }
        cout<<"��������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;
        //��ͥסַ
        cout<<"�������ͥסַ��"<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;
        //����һ��ͨѶ¼�е�����
        abs->m_Size++;
        cout<<"��ӳɹ�"<<endl;
        system("pause");//�밴���������
        system("cls");//��������
    }
}
//2.��ʾ���е���ϵ��
void showPerson(Addressbooks *abs)
{
    //�ж�ͨѶ¼�������Ƿ�Ϊ�㣬���Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ0����ʾ��¼����ϵ����Ϣ
    if (abs->m_Size==0)
    {
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }
    else
    {
        for (int i=0;i<abs->m_Size;i++)
        {
            cout<<"����: "<<abs->personArray[i].m_Name<<"\t";
            cout<<"�Ա�"<<(abs->personArray[i].m_Sex==1?"��":"Ů")<<"\t";
            cout<<"���䣺"<<abs->personArray[i].m_Age<<"\t";
            cout<<"�绰��"<<abs->personArray[i].m_Phone<<"\t";
            cout<<"סַ��"<<abs->personArray[i].m_Addr<<"\t";
        }
    }
    system("pause");//�밴���������
    system("cls");//��������
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(Addressbooks *abs,string name)
{
    for (int i=0;i<abs->m_Size;i++)
    {
        if (abs->personArray[i].m_Name==name)
        {
            return i;//����ҵ��ˣ��ͷ���������������е��±���
        }
    }
    return -1;//�������������û���ҵ����ͷ���-1
}
//3.ɾ��ָ������ϵ��
void deletePerson(Addressbooks *abs)
{
    cout<<"��������Ҫɾ������ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs, name);//ret==-1 δ�鵽 ret!=-1 �鵽��
    if (ret!=-1)
    {
        //�鵽���ˣ�Ҫ����ɾ������
        for (int i=ret;i<abs->m_Size;i++)
        {
            //����ǰ�Ʋ���
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;//����һ��ͨѶ¼�е���Ա��
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
//4.����ָ������ϵ����Ϣ
void findPerson(Addressbooks *abs)
{
    cout<<"��������Ҫ���ҵ���ϵ��"<<endl;
    string name;
    cin>>name;
    //�ж�ָ������ϵ���Ƿ����ͨѶ¼��
    int ret=isExist(abs, name);
    if (ret!=-1)//�ҵ���ϵ��
    {
        cout<<"������"<<abs->personArray[ret].m_Name<<"\t";
        cout<<"�Ա�"<<abs->personArray[ret].m_Sex<<"\t";
        cout<<"���䣺"<<abs->personArray[ret].m_Age<<"\t";
        cout<<"�绰��"<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"סַ��"<<abs->personArray[ret].m_Addr<<endl;
    }
    else //δ�ҵ���ϵ��
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}
//5.�޸�ָ������ϵ����Ϣ
void modifyPerson(Addressbooks *abs)
{
    cout<<"������һ����Ҫ�޸ĵ���ϵ��"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if (ret!=-1)//�ҵ�ָ����ϵ��
    {
        //����
        string name;
        cout<<"������һ��������"<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        //�Ա�
        cout<<"�������Ա�"<<endl;
        cout<<"1---��"<<endl;
        cout<<"2---Ů"<<endl;
        int sex=0;
        while (true)
        {
            cin>>sex;
            if (sex==1||sex==2)
            {
                //������ȷ���˳�ѭ������
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cout<<"������������������"<<endl;
        }
        //����
        cout<<"���������䣺"<<endl;
        int age=0;
        cin>>age;
        while (true)
        {
            //��������������0��100֮��Ϳ����˳�ѭ������Ϊ���������ȷֵ
            //����������������������
            cin>>age;
            if (age>0&&age<100)
            {
                abs->personArray[ret].m_Age=age;
                break;
            }
            cout<<"������������������";
        }
        //�绰
        cout<<"��������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;
        //סַ
        cout<<"�������ͥסַ��"<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;
        cout<<"�޸ĳɹ���"<<endl;
    }
    else //δ�ҵ���ϵ��
    {
        cout<<"���޴���"<<endl;
    }
    //�������������
    system("pause");
    system("cls");
}
//6.�����ϵ��
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;
    cout<<"ͨѶ¼�����"<<endl;
    //�������������
    system("pause");
    system("cls");
}
void showMenu()
{
    cout<<"**********************"<<endl;
    cout<<"***** 1.�����ϵ�� *****"<<endl;
    cout<<"***** 2.��ʾ��ϵ�� *****"<<endl;
    cout<<"***** 3.ɾ����ϵ�� *****"<<endl;
    cout<<"***** 4.������ϵ�� *****"<<endl;
    cout<<"***** 5.�޸���ϵ�� *****"<<endl;
    cout<<"***** 6.�����ϵ�� *****"<<endl;
    cout<<"***** 0.�˳�ͨѶ¼ *****"<<endl;
    cout<<"**********************"<<endl;
}
int main()
{
    //����һ��ͨѶ¼�Ľṹ�����
    Addressbooks abs;
    //��ʼ��ͨѶ¼�е�ǰ����Ա����
    abs.m_Size=0;
    int select=0;  //����һ���û�����ı���
    while (true)
    {
        showMenu();
        cin>>select;
        switch (select)
        {
            case 1:
                addPerson(&abs);// 1.�����ϵ��  2.���õ�ַ���ݿ�������ʵ��
                break;
            case 2:
                showPerson(&abs);//2.��ʾ��ϵ��
                break;
            case 3:
                deletePerson(&abs);//ɾ����ϵ��
                break;
            case 4:
                findPerson(&abs);//4.������ϵ��
                break;
            case 5:
                modifyPerson(&abs);//5.�޸���ϵ��
                break;
            case 6:
                cleanPerson(&abs);//6.�����ϵ��
                break;
            case 0://0.�˳�ͨѶ¼
                cout<<"��ӭ�´�ʹ��ͨѶ¼."<<endl;
                return 0;
            default:
                break;
        }
    }
}