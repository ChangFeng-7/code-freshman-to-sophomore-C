#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#define nmaxn 20		//���鶨��ͳһ��С
#define SIZE 100//����û�����
#include<fstream>



#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;
int judge1=0;
#define SIZE 100//����û�����


#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;
#define SIZE 100//����û�����








int scount = 0;//�������浱ǰ��ע���û���
int guanqia=0;
using namespace std;

int gsn;		//ȫ�ֱ�����gsnΪѧ��������
struct student *head;  //ͷָ�룬ָ���һ��ѧ������Ϣ



struct student		//����ṹ�壬����ѧ����Ϣ
{
	char name[nmaxn];		//����
	char num[nmaxn];		//ѧ��
	char sex[nmaxn];		//�Ա�
	int age;           //����
	char phone[nmaxn];         //�绰����
	int chinese;		//���ĳɼ�
	int math;		//��ѧ�ɼ�
	int english;		//Ӣ��ɼ�
	int sum;          //�ܷ�
	struct student *next; //ָ����һ��ѧ����Ϣ
};

class User
{
private:
	string phone;//�绰
	string password;//����
public:
	User() {};
	void Registers();//ע��
	void Login();//��¼
	void save();//����
	void READ();//��ȡ
}us;User user[SIZE];

//���˵���������
void menu();				//�����溯��
void input_record();  		//����ѧ���ɼ�����   1
void show_record();  		//��ʾѧ���ɼ�����   2
void search_record();  		//��ѯѧ���ɼ�����   3
void change_record();  		//����ѧ���ɼ�����   4
void delete_record();  		//ɾ��ѧ����Ϣ   5
void calc_record(); 	 	//����ɼ�����   6
void save_record();  		//���洦��   7



//��ѯ�Ӻ�������
void search_by_num();  		//ѧ�Ų�ѯ
void search_by_name();  	//������ѯ
void search_by_sex();  		//�Ա��ѯ
void search_by_exit();  	//������һ��

//�����Ӻ���
void sort_main();//����������
void sort_by_num();//ѧ������
void sort_by_chinese();//���ĳɼ�����
void sort_by_math();//��ѧ�ɼ�����
void sort_by_english();//Ӣ��ɼ�����
void sort_by_age();//�������� 

//�����Ӻ�������
void calc_sum();  			//�����ܳɼ�
void calc_ave();  			//����ƽ���ɼ�
void calc_eixt();  			//������һ��


//�Զ��庯��
void print_table();			//��ͷ
void print_table_sum();		//�ܳɼ����
void print_table_ave();		//ƽ���ֱ��
void READdata();     			//���ļ��е����ݶ��뵽�ṹ��������


int start();

//int User::Login();
//void User::Registers();
//void User::READdata();
//void User::save();
void SetColorAndBackground(int ForgC, int BackC); 


int main()
{
	int i=0;
	while((i=start())==0);
	head=(struct student *)malloc(sizeof(struct student));
	menu();
	return 0;
}



int start()
{
	User user;
	int chose = -1;
	while(judge1==0)
	{
		
		system("cls");
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��       1.ע    ��     2.��    ¼      ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
			cin >> chose;
		}
		switch (chose)
		{
		case 1:user.Registers(); break;
		case 2:user.Login(); break;
		}
	}
	
	return 1;
}

//����
void User::save()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	for (int i = 0; i < scount; i++)
	{
		ofile << user[i].phone << endl;
		ofile << user[i].password << endl;
	}
	ofile.close();
}

//��¼
void User::Login()
{
	us.READ();//��ȡ�Ѵ����û�����
	string ph;//�绰
	string pw;//����
	int time = 0;//ͳ�ƱȽϴ���
here:
	cout << "\t\t\t��ϵͳ��ʾ���������ֻ��ţ�";
	cin >> ph;
	int chose = -1;
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��       1.��ʾ����     2.��������      ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
	cin >> chose;
	if (chose > 2 || chose < -1)
	{
		cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
		cin >> chose;
	}

	string pword;
	char ch, passwords0[20];
	int x = 0;
	switch (chose)
	{
	case 1:
		cout << "\t\t\t��ϵͳ��ʾ�����������룺";
		cin >> pword;
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone && pword == user[i].password)
			{
				time++;
				judge1=1;
				cout << "\t\t\t��ϵͳ��ʾ����¼�ɹ���" << endl;
				system("pause");
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t��ϵͳ��ʾ���ֻ��Ż��������" << endl;
			goto here;
		}
		break;
	case 2:
		cout << "\t\t\t��ϵͳ��ʾ�����������룺";
		while ((ch = _getch()) != '\r' && x <= 20)
		{
			if (ch == '\b')
			{
				if (x > 0)
				{
					x--;
					cout << "\b \b";//����֧���˸��ʵ��
				}
				else
					putchar(7);
			}
			else
			{
				passwords0[x++] = ch;
				printf("*");
			}
		}
		passwords0[x] = '\0';
		cout << endl;
		//���αȽ��Ѵ�����Ϣ���Ƚ��Ƿ�ƥ�䣨�粻ƥ������ʾ����
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone && passwords0 == user[i].password)
			{
				time++;
				cout << "\t\t\t��ϵͳ��ʾ����¼�ɹ���" << endl;
				judge1=1;
				system("pause");
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t��ϵͳ��ʾ���ֻ��Ż��������" << endl;
			goto here;
		}
		break;
	}
}

//ע��
void User::Registers()
{
	us.READ();//��ȡ�Ѵ����û�����
	string ph;//�绰
	string pw1;//����1
	string pw2;//����2
	for (int i = scount; i < SIZE; i++)
	{
	here:
		cout << "\t\t\t��ϵͳ��ʾ���������ֻ��ţ�";
		cin >> ph;
		//�ж���������û���Ϣ�Ƿ��Ѵ��ڣ�����Ѵ������������룩
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone)
			{
				cout << "\t\t\t��ϵͳ��ʾ���û��Ѵ��ڣ�" << endl;
				goto here;
			}
		}
		user[i].phone = ph;

		int chose = -1;
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��       1.��ʾ����     2.��������      ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
			cin >> chose;
		}

		string pword;
		char ch, passwords0[20];
		int x = 0;
		string pword1;
		char ch1, passwords1[20];
		int x1 = 0;
		switch (chose)
		{
		case 1:
			cout << "\t\t\t��ϵͳ��ʾ�����������룺";
			cin >> pword;
			user[i].password = pword;
			cout << "\t\t\t��ϵͳ��ʾ�����ٴ����룺";
			cin >> pword1;
			if (pword1 != user[i].password)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����벻һ�£�" << endl;
				goto here;
			}
			else
			{
				scount++;//��ע���û���1
				cout << "\t\t\t��ϵͳ��ʾ��ע��ɹ���" << endl;
				us.save();//�����û�����
			}
			break;
		case 2:
			cout << "\t\t\t��ϵͳ��ʾ�����������룺";
			while ((ch = _getch()) != '\r' && x <= 20)
			{
				if (ch == '\b')
				{
					if (x > 0)
					{
						x--;
						cout << "\b \b";//����֧���˸��ʵ��
					}
					else
						putchar(7);
				}
				else
				{
					passwords0[x++] = ch;
					printf("*");
				}
			}
			passwords0[x] = '\0';
			cout << endl;
			user[i].password = passwords0;

			cout << "\t\t\t��ϵͳ��ʾ�����ٴ����룺";
			while ((ch1 = _getch()) != '\r' && x1 <= 20)
			{
				if (ch1 == '\b')
				{
					if (x1 > 0)
					{
						x1--;
						cout << "\b \b";//����֧���˸��ʵ��
					}
					else
						putchar(7);
				}
				else
				{
					passwords1[x1++] = ch1;
					printf("*");
				}
			}
			passwords1[x1] = '\0';
			cout << endl;
			//�Ƚ���������������Ƿ�ͳһ�������ͳһ���������룩
			if (passwords1 != user[i].password)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����벻һ�£�" << endl;
				goto here;
			}
			else
			{
				scount++;//��ע���û���1
				cout << "\t\t\t��ϵͳ��ʾ��ע��ɹ���" << endl;
				us.save();//�����û�����
			}
			break;
		}
		char choice;
		cout << "\t\t\t��ϵͳ��ʾ���Ƿ����ע��(Y/N)�� :";
		while (1)
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
				break;
			else
				cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺 ";
		}
		if (choice == 'n' || choice == 'N')
		{
			
			break;
		}
	}
}

//��ȡ
void User::READ()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);

	scount = 0;

	if (!ifile.is_open())
	{
		//cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> user[i].phone;
		ifile >> user[i].password;
		scount++;
	}
	scount--;
	ifile.close();
}



void calc_record()
{
	system("cls");   //���� 

	int f=0;
	printf("\n\n\t\t��ѡ��һ��������\n\n");
	printf("���㲢����ܷ�-----1\n\n");
	Sleep(100);
	printf("���㲢���ƽ����---2\n\n");
	Sleep(100);
	printf("����---------------3\n\n");

	cin>>f;
	/*
	switch(f)
	{
		case 1:calc_sum();break;
		case 2:calc_ave();break;
		case 3:menu();break;
	}*/
	if (f==1)
		calc_sum();
	else if(f==2)
		calc_ave();
	else
		menu();
	
}

void calc_sum()
{
	system("cls");
	struct student *p;//����ָ�� 
	p=head->next;
	
	printf("***************************************************\n");
	printf("*   ����   * ѧ�� * �Ա� *����*    �绰    * �ܷ� *\n");
	printf("***************************************************\n");
	
	int gs=1;
	int yeshu=1;
	int zys=gsn/10+1;
	for(int i=0;i<gsn;i++)
	{
		
		p->sum=p->chinese+p->english+p->math;
		printf("*%10s*%6s*%6s*%4d*%12s*%6d*\n",p->name,p->num,p->sex,p->age,p->phone,p->sum);
		printf("***************************************************\n");
		gs++;
		
		if(gs%10==0)
		{
			
			char command;
			getch();
			if(command=='w'||command=='W'&&gsn-gs>=10)
			{
				system("cls");
				yeshu++;
			}
			else if(command=='s'||command=='S'&&gs>10)
			{
				system("cls");
				yeshu--;
			}
			else if(command=='p'||command=='P')
			{
				system("cls");
				menu();
			}
			else if(gsn-gs<10)
			{
				printf("�ѵ����һҳ\n");
			}
			else if(gs<10)
			{
				printf("��ǰΪ��ҳ��"); 
			}
			
		}
		printf("***************************************************\n");
		printf("\n\t�� %d ҳ  �� %d ҳ\n",yeshu,zys);
		printf("\n\t��ʹ��W�����ϣ�S�����£���ҳ��P�˳���\n\n");
		if(p->next==NULL)break;
		p=p->next;
		
	}
	
	printf("���г����������ĳɼ������ǵ��ܷ���\n\n");
	system("pause");
	calc_record();
}

void calc_ave()
{
	system("cls");
	struct student *p;//����ָ�� 
	p=head->next;
	
	printf("***************************************************\n");
	printf("*   ����   * ѧ�� * �Ա� *����*    �绰    * �ܷ� *\n");
	printf("***************************************************\n");
	
	int gs=1;
	int yeshu=1;
	int zys=gsn/10+1;
	for(int i=0;i<gsn;i++)
	{
		
		p->sum=p->chinese+p->english+p->math;
		printf("*%10s*%6s*%6s*%4d*%12s*%6.2f*\n",p->name,p->num,p->sex,p->age,p->phone,p->sum/3.0);
		printf("***************************************************\n");
		gs++;
		
		if(gs%10==0)
		{
			
			char command;
			getch();
			if(command=='w'||command=='W'&&gsn-gs>=10)
			{
				system("cls");
				yeshu++;
			}
			else if(command=='s'||command=='S'&&gs>10)
			{
				system("cls");
				yeshu--;
			}
			else if(command=='p'||command=='P')
			{
				system("cls");
				menu();
			}
			else if(gsn-gs<10)
			{
				printf("�ѵ����һҳ\n");
			}
			else if(gs<10)
			{
				printf("��ǰΪ��ҳ��"); 
			}
			
		}
		printf("***************************************************\n");
		printf("\n\t�� %d ҳ  �� %d ҳ\n",yeshu,zys);
		printf("\n\t��ʹ��W�����ϣ�S�����£���ҳ��P�˳���\n\n");
		if(p->next==NULL)break;
		p=p->next;
		
	}
	
	printf("���г����������ĳɼ������ǵ�ƽ������\n\n");
	system("pause");
	calc_record();
}




void sort_main()
{
	system("cls");
	
	printf("��ǰ�����ɼ���Ϣ���£�\n");
	print_table();
	//printf("*   ����   * ѧ�� *�Ա�*����*    �绰    * ���� * ��ѧ * Ӣ�� *\n");
	struct student*p;
	p=head->next;
	
	for(int i=0;i<gsn;i++)
	{
		printf("*%10s*%6s*%4s*%4d*%12s*%6d*%6d*%6d*\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
		printf("***************************************************************\n");
		
		if(p->next==NULL)break;
		p=p->next;
	}
	printf("��ѡ��һ�����\n\n");
	Sleep(100); 
	printf("������������---------1\n\n");
	Sleep(100); 
	printf("�����ĳɼ�����-------2\n\n");
	Sleep(100); 
	printf("����ѧ�ɼ�����-------3\n\n");
	Sleep(100); 
	printf("��Ӣ��ɼ�����-------4\n\n");
	Sleep(100); 
	printf("����������-----------5\n\n");
	Sleep(100); 
	printf("�������˵�-----------6\n\n");
	Sleep(100); 
	printf("��");
	
	int command=0;
	scanf("%d", &command);
	
	switch(command)
	{
		case 1:sort_by_num();break;
		case 2:sort_by_chinese();break;
		case 3:sort_by_math();break;
		case 4:sort_by_english();break;
		case 5:sort_by_age();break; 
		default:menu();
	}
	
	system("cls");
}

void sort_by_age()
{
	int command=0;
	printf("��ѡ��\n");
	printf("---\t1.����\n");
	printf("---\t2.����\n");
	printf("---\t3.����\n");
	printf("�����룺\n");
	scanf("%d", &command);
	if(command==1)
	{
		struct student *stu[gsn];
		int i;//���ڴ������������
		int j;//����ѡ������
		int min;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//���������ݶ�������
		for(i = 0; i < gsn; i++)
		{
			min = i;
			for(j = i; j < gsn; j++)
			{
				if(stu[j] -> age < stu[min] -> age)min = j;
			}
			tmp = stu[i];
			stu[i] = stu[min];
			stu[min] = tmp;
		}//ѡ������
		struct student *c;//��ͷ
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//β���β
		c -> next = stu[0];
		tail = stu[0];
		
		for(i = 1; i < gsn; i++)
		{
			tail -> next = stu[i];
			tail = stu[i];
		}
		tail -> next = NULL;
		head = c;
		save_record();
		show_record();
	}
	else if(command==2)
	{
		struct student *stu[gsn];
		int i;//���ڴ������������
		int j;//����ѡ������
		int mmax;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//���������ݶ�������
		for(i = 0; i < gsn; i++)
		{
			mmax = i;
			for(j = i; j < gsn; j++)
			{
				if(stu[j] -> age > stu[mmax] -> age)mmax = j;
			}
			tmp = stu[i];
			stu[i] = stu[mmax];
			stu[mmax] = tmp;
		}//ѡ������
		struct student *c;//��ͷ
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//β���β
		c -> next = stu[0];
		tail = stu[0];

		for(i = 1; i < gsn; i++)
		{
			tail -> next = stu[i];
			tail = stu[i];
		}
		tail -> next = NULL;
		head = c;
		save_record();
		show_record();
	}
	else
		sort_main();
}

void sort_by_chinese()
{
	int command=0;
	printf("��ѡ��\n");
	printf("---\t1.����\n");
	printf("---\t2.����\n");
	printf("---\t3.����\n");
	printf("�����룺\n");
	scanf("%d", &command);
	if(command==1)
	{
		struct student *stu[gsn];
		int i;//���ڴ������������
		int j;//����ѡ������
		int min;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//���������ݶ�������
		for(i = 0; i < gsn; i++)
		{
			min = i;
			for(j = i; j < gsn; j++)
			{
				if(stu[j] -> chinese < stu[min] -> chinese)min = j;
			}
			tmp = stu[i];
			stu[i] = stu[min];
			stu[min] = tmp;
		}//ѡ������
		struct student *c;//��ͷ
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//β���β
		c -> next = stu[0];
		tail = stu[0];
		
		for(i = 1; i < gsn; i++)
		{
			tail -> next = stu[i];
			tail = stu[i];
		}
		tail -> next = NULL;
		head = c;
		save_record();
		show_record();
	}
	else if(command==2)
	{
		struct student *stu[gsn];
		int i;//���ڴ������������
		int j;//����ѡ������
		int mmax;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//���������ݶ�������
		for(i = 0; i < gsn; i++)
		{
			mmax = i;
			for(j = i; j < gsn; j++)
			{
				if(stu[j] -> chinese > stu[mmax] -> chinese)mmax = j;
			}
			tmp = stu[i];
			stu[i] = stu[mmax];
			stu[mmax] = tmp;
		}//ѡ������
		struct student *c;//��ͷ
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//β���β
		c -> next = stu[0];
		tail = stu[0];

		for(i = 1; i < gsn; i++)
		{
			tail -> next = stu[i];
			tail = stu[i];
		}
		tail -> next = NULL;
		head = c;
		save_record();
		show_record();
	}
	else
		sort_main();
}

void sort_by_math()
{
	int flag;
	printf("��ѡ��\n");
	printf("---\t1.����\n");
	printf("---\t2.����\n");
	printf("---\t3.����\n");
	printf("�����룺\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					min = i;
					for(j = i; j < gsn; j++)
						{
							if(stu[j] -> math < stu[min] -> math)min = j;
						}
					tmp = stu[i];
					stu[i] = stu[min];
					stu[min] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else if(flag == 2)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					mmax = i;
					for(j = i; j < gsn; j++)
						{
							if(stu[j] -> math > stu[mmax] -> math)mmax = j;
						}
					tmp = stu[i];
					stu[i] = stu[mmax];
					stu[mmax] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else
		sort_main();
}

void sort_by_english()
{
	int flag;
	printf("��ѡ��\n");
	printf("---\t1.����\n");
	printf("---\t2.����\n");
	printf("---\t3.����\n");
	printf("�����룺\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					min = i;
					for(j = i; j < gsn; j++)
						{
							if(stu[j] -> english < stu[min] -> english )min = j;
						}
					tmp = stu[i];
					stu[i] = stu[min];
					stu[min] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else if(flag == 2)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					mmax = i;
					for(j = i; j < gsn; j++)
						{
							if(stu[j] -> chinese > stu[mmax] -> chinese)mmax = j;
						}
					tmp = stu[i];
					stu[i] = stu[mmax];
					stu[mmax] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else
		sort_main();
}

void sort_by_num()
{
	int flag;
	printf("��ѡ��\n");
	printf("---\t1.����\n");
	printf("---\t2.����\n");
	printf("---\t3.����\n");
	printf("�����룺\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					min = i;
					for(j = i; j < gsn; j++)
						{
							if(strcmp(stu[min] -> num, stu[j] -> num) > 0)min = j;
						}
					tmp = stu[i];
					stu[i] = stu[min];
					stu[min] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else if(flag == 2)
		{
			struct student *stu[gsn];
			int i;//���ڴ������������
			int j;//����ѡ������
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//���������ݶ�������
			for(i = 0; i < gsn; i++)
				{
					mmax = i;
					for(j = i; j < gsn; j++)
						{
							if(strcmp(stu[mmax] -> num, stu[j] -> num) < 0)mmax = j;
						}
					tmp = stu[i];
					stu[i] = stu[mmax];
					stu[mmax] = tmp;
				}//ѡ������
			struct student *c;//��ͷ
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//β���β
			c -> next = stu[0];
			tail = stu[0];

			for(i = 1; i < gsn; i++)
				{
					tail -> next = stu[i];
					tail = stu[i];
				}
			tail -> next = NULL;
			head = c;
			save_record();
			show_record();
		}
	else
		sort_main();
}

void print_table()    	//��ӡѧ����Ϣ���ı�ͷ����
{
	printf("***************************************************************\n");
	printf("*   ����   * ѧ�� *�Ա�*����*    �绰    * ���� * ��ѧ * Ӣ�� *\n");
	printf("***************************************************************\n");
}
void show_record()
{
	system("cls");
	struct student *p;
	p=head->next;
	print_table() ;
	for (int i=0; i<gsn; i++)
		{

			printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);
			if(p->next==NULL)
				break;
			p=p->next;
		}
	//printf("��������������˵�");
	//int fw;
	//scanf("%d",&fw);
	system("pause");
	menu();

}




void change_record()
{
	char num1[nmaxn];		//�û�����ѧ��ѧ��
	int k;
	system("cls");		//��������
	int f2=0;
	int loop=0;
	printf("������Ҫ�޸ĳɼ���ѧ��ѧ�ţ�");
	scanf("%s", num1);
	struct student *p;
	p=head->next;
	int a,b,c;
	int mm=0;
	for (int i = 0; i < gsn; i++)		//��������Ѱ���Ǹ�ѧ���Ƿ����
		{
			mm=0;
			if (strcmp(num1,p->num) == 0)
				{
					f2=1;

					printf("��ѧ�����ڳɼ�Ϊ��\n");
					print_table();
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);
					printf("��������¹������ĳɼ���");
					scanf("%d",&a);
					printf("\n��������¹�����ѧ�ɼ���");
					scanf("%d",&b);
					printf("\n��������¹���Ӣ��ɼ���");
					scanf("%d",&c);
					p->chinese=a;
					p->math=b;
					p->english=c;
					printf("\nȷ�ϸ����� 1.����  2.ȡ��");
					scanf("%d",&mm);
					if(mm!=1)
						{
							f2=0;
							break;

						}
					save_record();
					system("cls");
					printf("��ѧ���޸ĺ�ɼ�Ϊ��\n");
					print_table();
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);


					if (p->next==NULL)
						break;

				}
			p=p->next;
			loop++;
		}
	//printf("%d",gsn);
	if (f2==0)		//gsnΪȫ�ֱ���ѧ��������
		{
			system("cls");
			printf("���������ѧ�ţ�\n\n");
		}

	printf("1.����������\n2.������ѯ\n");
	printf("�����룺");
	scanf("%d", &k);

	if (k == 1)
		{
			menu();
		}

	else
		{
			change_record();
		}
}
void search_by_num()    //��ѯѧ����Ϣ�������Ӻ���������ѧ�Ų�ѯ����
{
	char num1[nmaxn];		//�û�����ѧ��ѧ��
	int k;
	system("cls");		//��������
	int f2=0;
	int loop=0;
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", num1);
	struct student *p;
	p=head->next;
	print_table();
	for (int i = 0; i < gsn; i++)		//��������Ѱ���Ǹ�ѧ���Ƿ����
		{
			if (strcmp(num1,p->num) == 0)
				{
					f2=1;
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);
					if (p->next==NULL)
						break;

				}
			p=p->next;
			loop++;
		}
	//printf("%d",gsn);
	if (f2==0)		//gsnΪȫ�ֱ���ѧ��������
		{
			system("cls");
			printf("���������ѧ�ţ�\n\n");
		}

	printf("1.����������\n2.������ѯ\n");
	printf("�����룺");
	scanf("%d", &k);

	if (k == 1)
		{
			menu();
		}

	else
		{
			search_by_num();
		}
}
void search_by_name()
{
	char name1[nmaxn];		//�û�����ѧ������
	int k;
	system("cls");		//��������
	int f2=0;
	int loop=0;
	printf("������Ҫ���ҵ�������");
	scanf("%s", name1);
	struct student *p;
	p=head->next;
	print_table();
	for (int i = 0; i < gsn; i++)		//��������Ѱ���Ǹ������Ƿ����
		{
			if (strcmp(name1,p->name) == 0)
				{
					f2=1;
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);
					if (p->next==NULL)
						break;

				}
			p=p->next;
			loop++;
		}
	//printf("%d",gsn);
	if (f2==0)
		{
			system("cls");
			printf("���������������\n\n");
		}

	printf("1.����������\n2.������ѯ\n");
	printf("�����룺");
	scanf("%d", &k);

	if (k == 1)
		{
			menu();
		}

	else
		{
			search_by_name();
		}
}

void delete_record()    //ɾ��������Ϣ����
{
	system("cls");//�������� 

	
	//Ԥ�ȶ�����ֱ��� 
	int judge=0;   //�Ƿ��и���������Ϣ�б�������� 
	char goer[nmaxn];  //����֮�� 
	int accept=0;
	int accepter=0;   
	int flag=0;    //Ϊ�˷��㺯�����е��������� 
	char *tempname;
	
	
	//ȷ������ 
	printf("������Ҫɾ����������QAQ��\n");
	scanf("%s",goer);
	
	struct student*p,*tmp;
	p=head->next;
	tmp=head;

	//int i,j;
	for(int n=0;n<gsn;n++)//ͨ��������Ŀ���������� 
	{
		if(flag>0)//����һ��ѭ���⣬����ָ��ͬʱ���+1 
		{
			p=p->next;
			tmp=tmp->next;
		}
		flag++;//flag��ʾ��ǰ�����λ�� 
		if(!strcmp(p->num,goer))//������ָ�������ѧ����Ϣ 
		{
			//����һ��ɾ������ 
			printf("��ȷ��Ҫɾ����������Ϣ\n");
			printf("**********\n");
			printf("|%10s|\n|%10s|\n|%10s|\n|%10d|\n|%10d|\n|%10d|\n|%10d|\n",p->name,p->num,p->sex,p->age,p->chinese,p->math,p->english);
			printf("**********\n");
			printf("\n");
			printf("\tɾ��---1\n\t\ȡ��---2\n\t:");
			scanf("%d",&accept);
			
			if(accept==1)
			{
				//ȷ��ɾ����������� 
				//tempname=p->name;
				printf("�ѽ� %s ɾ��\n",p->name);
				{
					tmp->next=p->next;
					p=p->next;
				}
				gsn--;//ȫ�ֱ�����gsn-1
				judge=1;//���ָ������� 
				save_record();//��ɾ�������Ϣ���浽�ļ���
			}
			else if(accept==2)
			{	
				judge=1;//���ָ���������δȷ��ɾ�� 
				printf("��ֹͣ����\n");
			}
		}
	}
	if(judge==0)		//��ѧ�Ų�����
	{
		printf("���޴���\n");
		printf("���޴���\n");
		printf("���޴���\n\n");
	}
	//system("cls");
	
	printf("\n");
	printf("�Ƿ���н�һ��ɾ����");
	printf("\t����ɾ��---1\n\t\���ز˵�---2\n\t��");
	scanf("%d",&accepter);
	//�ж����� 
	if(accepter==1)
	{
		system("cls"); 
		delete_record();//Ƕ�׵��ú��� 
	}
	else if(accepter==2)
	{
		system("cls"); 
		menu();//���������� 
	}
	
}

void search_record()  	//��ѯѧ���ɼ�����    3
{
	system("cls");//���������Ļ�˵� 


	//��ӡ�˵�
	printf("1�����������ѯ\n");
	printf("2��ѧ�Ŷ����ѯ\n");
	printf("3���Ա�������ѯ\n");
	printf("4���������˵�\n");
	printf("������һ��ѡ�\n");
	
	int x;//���ѡ�� 
	scanf("%d", &x);
	 
	if(x==1)
		search_by_name();	//��������ѯ����
	else if(x==2)
		search_by_num();	//��ѧ�Ų�ѯ����
	else if(x==3)
		search_by_sex();	//���Ա��ѯ��ѯ
	else
		menu();
}




void search_by_sex()
{
	system("cls");//������ 
	
	struct student*p;
	p=head->next;
	
	char sex[nmaxn];//��������Ա� 
	int temp0=0;
	int temp1=0;
	//int temp=0;
	
	printf("������һ���Ա�boy/girl����");
	scanf("%s",sex);
	
	print_table();              //��ӡ��ͷ 
	for(int i=0;i<gsn;i++)		//Ѱ���Ƿ��з��ϵ��Ա�kora 
	{
		if(strcmp(sex,p->sex)==0)
		{
			temp1=1;//�ҵ��������� 
			printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
			if(p->next==NULL)break;
		}
		
		//temp+=1;
		p=p->next;
		
	}
	
	if(temp1==0)
	{
		system("cls");
		printf("����������Ա����������\n\n");
	}
		

	printf("\n");
	printf("�Ƿ������ѯ��");
	printf("\t������ѯ---1\n\t\���ز˵�---2\n\t��");
	scanf("%d", &temp0);
	
	if(temp0==1)
	{
		search_by_sex();//�ݹ����
	}
	else if(temp0==2)
	{
		 menu();
	}
}

void input_record()
{
	//Ϊ����������һ���ռ� 
	struct student *newer;
	newer=(struct student*)malloc(sizeof(struct student));
	
	system("cls");//����˵���� 
	//ʹ��β�巨�������� 
	struct student*tail;
	tail=head;
	for(;tail->next!=NULL;tail=tail->next);//Ѱ�ҵ���β�� 
	

	int isno;


	printf("�������������֣�");
	scanf("%s",newer->name);

	printf("�����������ţ���λ����");
	scanf("%s",newer->num);

	printf("�����������Ա�boy/girl����");
	scanf("%s",newer->sex);

	printf("������ѧ�����䣺");
	scanf("%d",&newer->age);

	printf("������ѧ���绰���룺");
	scanf("%s",newer->phone);

	printf("������ѧ�����ĳɼ���");
	scanf("%d",&newer->chinese);

	printf("������ѧ����ѧ�ɼ���");
	scanf("%d",&newer->math);

	printf("������ѧ��Ӣ��ɼ���");
	scanf("%d",&newer->english);

	newer->next=NULL;

	printf("\n\n\t\t��ȷ��Ҫ�����������Ϣ\n\n\t\t");
	Sleep(1000);
	printf("�Ƿ�Ҫ���棿\n"); 
	printf("\t\t�ǵ�----1\n\t\t������----2\n"); 
	scanf("%d", &isno);

	
	if (isno==1)		//������Ϊy���򱣴���Ϣ���ļ���
		{
			gsn++;      //������Ŀ����һֻ 
			tail->next=newer;    //�����β 
			
			save_record();   //���ݴ浵 
			menu();
		}
	else if(isno==2) 
		{
			printf("\n�����У�\n");
			Sleep(200);
			menu();
		}
}


void save_record()//�������������� 
{
	printf("/n���ڱ���/n"); 
	FILE *save=fopen("goblinimformation.txt","w");//������txt 
	
	struct student*p;
	p=head->next;//�����ڵ� 
	
	fprintf(save,"%d\n",gsn);
	
	for(int i=0;i<gsn;i++)
	{
		fprintf(save,"%s %s %s %d %s %d %d %d\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
		//¼��ɼ� 
		//printf("$$$"); 
		//fprintf(save,"%d\n",gsn-1);
		//gsn--;i++;
		p=p->next;
	}

	fclose(save);//guanbi
}


void READdata()
{
	
	FILE*point=fopen("goblinimformation.txt","r");		//����һ���ļ�ָ��
	
	
	struct student *p;
	struct student *tail;
	p=(struct student *)malloc(sizeof(struct student));
	tail=head;
	//int i=0;
	
	fscanf(point,"%d\n",&gsn);
	if(gsn==0)
		{
			
			p->next=NULL;
			head->next=NULL;
			fclose(point);
			return;
		}
	else for(int i=0;(!feof(point))&&i<gsn;i++)
			{
				fscanf(point,"%s %s %s %d %s %d %d %d\n",p->name,p->num,p->sex,&p->age,p->phone,&p->chinese,&p->math,&p->english);
				
				
				tail->next=p;
				tail=p;
				p->next=NULL;
				p=(struct student*)malloc(sizeof(struct student));
			}
	fclose(point);		//�ر��ļ�ָ��
}

void menu()
{
	int judge=0; //�ж�ģʽ������ر� 
	system("cls");
	for(int i=0;i<10000;i++)
	{
		SetColorAndBackground(i,7);
		printf("��Ů����");
		//Sleep(100);
		//system("cls");
		
	}
	system("cls");
	READdata();       	//��������Ϣ��txt�ļ��ж��������� 
	
	SetColorAndBackground(9,7);
	printf("\n\n\n\t\t\t\t\t���ڼ���ͼ�ν���...");
	int i;
    printf(">>");
    for(i=1;i<=100;i++)
    {
            if(i<11)
              printf(">");
              printf("\b\b\b%d%%",i);
              fflush(stdout);
              usleep(10000);
    }
    printf("\n");
    system("cls");
	printf("\n\n\n\t\t\t\t\tDone��");
	//Sleep(1000);
	system("cls");
	
	
	int x=0;
	//���˵�
	printf("###########################################\n");
	printf("����  �����������������ɼ�����ͯ�棩   ����\n");
	printf("����#####################################����\n");
	printf("����\t\t1.¼�������ɼ�\t\t ����\n\n");Sleep(100);
	printf("����\t\t2.���������ɼ�\t\t ����\n\n");Sleep(100);
	printf("����\t\t3.��ѯ�����ɼ�\t\t ����\n\n");Sleep(100);
	printf("����\t\t4.����������Ϣ\t\t ����\n\n");Sleep(100);
	printf("����\t\t"); 
	SetColorAndBackground(0,4);
	printf("��5.ɾ��������"); 
	SetColorAndBackground(9,7);
	printf("\t\t ����\n\n");Sleep(100);
	printf("����\t\t6.���������ɼ�\t\t ����\n\n");Sleep(100);
	printf("����\t\t7.���������ɼ�\t\t ����\n\n");Sleep(100);
	printf("����\t\t8.�˳�\t\t         ����\n");Sleep(100);
	printf("###########################################\n\n");Sleep(100);
	
	printf("��ѡ��һ��������һλ���֣���\n");
	cin>>x;
	//printf("444444");
	if(!(x>=1&&x<=8))
	{
		judge=1; 
	}
	if(judge==0)
	{
		switch(x)
		{
			case 1:input_record();break;
			case 2:show_record();break;
			case 3:search_record();break;
			case 4:change_record();break;
			case 5:delete_record();break;
			case 6:calc_record();break;
			case 7:sort_main();break;
			case 8:
			{
				printf("��ͯ���������ڱ���\n\n");
				save_record();
				Sleep(1000);
				printf("������ϣ���������˳���\n");
				break;
			}
			default:
			{
				printf("�б�����������Ҳ�˵��˭��\n");
				Sleep(1000);
				printf("��������...");
				Sleep(500);
				menu();
				break;
			}
		}
	}
	else if(judge==1)//��ĸģʽ 
	{
		x=9;
		printf("�б�����������Ҳ�˵��˭��\n");
				Sleep(1000);
				printf("������󣬱���ʧ�ܣ������½��롣\n\n��������˳���");
				Sleep(500);
		return;
	}
}

void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


