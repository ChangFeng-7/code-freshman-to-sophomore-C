#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#define nmaxn 20		//数组定义统一大小
#define SIZE 100//最大用户容量
#include<fstream>



#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;
int judge1=0;
#define SIZE 100//最大用户容量


#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;
#define SIZE 100//最大用户容量








int scount = 0;//用作储存当前已注册用户数
int guanqia=0;
using namespace std;

int gsn;		//全局变量，gsn为学生的人数
struct student *head;  //头指针，指向第一名学生的信息



struct student		//定义结构体，包含学生信息
{
	char name[nmaxn];		//姓名
	char num[nmaxn];		//学号
	char sex[nmaxn];		//性别
	int age;           //年龄
	char phone[nmaxn];         //电话号码
	int chinese;		//语文成绩
	int math;		//数学成绩
	int english;		//英语成绩
	int sum;          //总分
	struct student *next; //指向下一个学生信息
};

class User
{
private:
	string phone;//电话
	string password;//密码
public:
	User() {};
	void Registers();//注册
	void Login();//登录
	void save();//保存
	void READ();//读取
}us;User user[SIZE];

//主菜单函数声明
void menu();				//主界面函数
void input_record();  		//输入学生成绩处理   1
void show_record();  		//显示学生成绩处理   2
void search_record();  		//查询学生成绩处理   3
void change_record();  		//更新学生成绩处理   4
void delete_record();  		//删除学生信息   5
void calc_record(); 	 	//计算成绩处理   6
void save_record();  		//保存处理   7



//查询子函数声明
void search_by_num();  		//学号查询
void search_by_name();  	//姓名查询
void search_by_sex();  		//性别查询
void search_by_exit();  	//返回上一级

//排序子函数
void sort_main();//排序主函数
void sort_by_num();//学号排序
void sort_by_chinese();//语文成绩排序
void sort_by_math();//数学成绩排序
void sort_by_english();//英语成绩排序
void sort_by_age();//年龄排序 

//计算子函数声明
void calc_sum();  			//计算总成绩
void calc_ave();  			//计算平均成绩
void calc_eixt();  			//返回上一级


//自定义函数
void print_table();			//表头
void print_table_sum();		//总成绩表格
void print_table_ave();		//平均分表格
void READdata();     			//将文件中的数据读入到结构体数组中


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
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃       1.注    册     2.登    录      ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << "\t\t\t【系统提示】请输入你的选择：";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
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

//保存
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

//登录
void User::Login()
{
	us.READ();//读取已储存用户数据
	string ph;//电话
	string pw;//密码
	int time = 0;//统计比较次数
here:
	cout << "\t\t\t【系统提示】请输入手机号：";
	cin >> ph;
	int chose = -1;
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃       1.显示密码     2.隐藏密码      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << "\t\t\t【系统提示】请输入你的选择：";
	cin >> chose;
	if (chose > 2 || chose < -1)
	{
		cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
		cin >> chose;
	}

	string pword;
	char ch, passwords0[20];
	int x = 0;
	switch (chose)
	{
	case 1:
		cout << "\t\t\t【系统提示】请输入密码：";
		cin >> pword;
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone && pword == user[i].password)
			{
				time++;
				judge1=1;
				cout << "\t\t\t【系统提示】登录成功！" << endl;
				system("pause");
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t【系统提示】手机号或密码错误！" << endl;
			goto here;
		}
		break;
	case 2:
		cout << "\t\t\t【系统提示】请输入密码：";
		while ((ch = _getch()) != '\r' && x <= 20)
		{
			if (ch == '\b')
			{
				if (x > 0)
				{
					x--;
					cout << "\b \b";//密码支持退格的实现
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
		//依次比较已储存信息，比较是否匹配（如不匹配则提示错误）
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone && passwords0 == user[i].password)
			{
				time++;
				cout << "\t\t\t【系统提示】登录成功！" << endl;
				judge1=1;
				system("pause");
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t【系统提示】手机号或密码错误！" << endl;
			goto here;
		}
		break;
	}
}

//注册
void User::Registers()
{
	us.READ();//读取已储存用户数据
	string ph;//电话
	string pw1;//密码1
	string pw2;//密码2
	for (int i = scount; i < SIZE; i++)
	{
	here:
		cout << "\t\t\t【系统提示】请输入手机号：";
		cin >> ph;
		//判断新输入的用户信息是否已存在（如果已存在则重新输入）
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].phone)
			{
				cout << "\t\t\t【系统提示】用户已存在！" << endl;
				goto here;
			}
		}
		user[i].phone = ph;

		int chose = -1;
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃       1.显示密码     2.隐藏密码      ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << "\t\t\t【系统提示】请输入你的选择：";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
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
			cout << "\t\t\t【系统提示】请输入密码：";
			cin >> pword;
			user[i].password = pword;
			cout << "\t\t\t【系统提示】请再次密码：";
			cin >> pword1;
			if (pword1 != user[i].password)
			{
				cout << "\t\t\t【系统提示】密码不一致！" << endl;
				goto here;
			}
			else
			{
				scount++;//已注册用户加1
				cout << "\t\t\t【系统提示】注册成功！" << endl;
				us.save();//保存用户数据
			}
			break;
		case 2:
			cout << "\t\t\t【系统提示】请输入密码：";
			while ((ch = _getch()) != '\r' && x <= 20)
			{
				if (ch == '\b')
				{
					if (x > 0)
					{
						x--;
						cout << "\b \b";//密码支持退格的实现
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

			cout << "\t\t\t【系统提示】请再次密码：";
			while ((ch1 = _getch()) != '\r' && x1 <= 20)
			{
				if (ch1 == '\b')
				{
					if (x1 > 0)
					{
						x1--;
						cout << "\b \b";//密码支持退格的实现
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
			//比较两次输入的密码是否统一（如果不统一则重新输入）
			if (passwords1 != user[i].password)
			{
				cout << "\t\t\t【系统提示】密码不一致！" << endl;
				goto here;
			}
			else
			{
				scount++;//已注册用户加1
				cout << "\t\t\t【系统提示】注册成功！" << endl;
				us.save();//保存用户数据
			}
			break;
		}
		char choice;
		cout << "\t\t\t【系统提示】是否继续注册(Y/N)？ :";
		while (1)
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
				break;
			else
				cout << "\t\t\t【系统提示】输入格式错误，请重新输入： ";
		}
		if (choice == 'n' || choice == 'N')
		{
			
			break;
		}
	}
}

//读取
void User::READ()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);

	scount = 0;

	if (!ifile.is_open())
	{
		//cout << "文件打开失败！" << endl;
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
	system("cls");   //清屏 

	int f=0;
	printf("\n\n\t\t请选择一个操作：\n\n");
	printf("计算并输出总分-----1\n\n");
	Sleep(100);
	printf("计算并输出平均分---2\n\n");
	Sleep(100);
	printf("返回---------------3\n\n");

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
	struct student *p;//查找指针 
	p=head->next;
	
	printf("***************************************************\n");
	printf("*   姓名   * 学号 * 性别 *年龄*    电话    * 总分 *\n");
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
				printf("已到最后一页\n");
			}
			else if(gs<10)
			{
				printf("当前为首页！"); 
			}
			
		}
		printf("***************************************************\n");
		printf("\n\t第 %d 页  共 %d 页\n",yeshu,zys);
		printf("\n\t可使用W（向上）S（向下）翻页，P退出：\n\n");
		if(p->next==NULL)break;
		p=p->next;
		
	}
	
	printf("已列出所有妖精的成绩和她们的总分数\n\n");
	system("pause");
	calc_record();
}

void calc_ave()
{
	system("cls");
	struct student *p;//查找指针 
	p=head->next;
	
	printf("***************************************************\n");
	printf("*   姓名   * 学号 * 性别 *年龄*    电话    * 总分 *\n");
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
				printf("已到最后一页\n");
			}
			else if(gs<10)
			{
				printf("当前为首页！"); 
			}
			
		}
		printf("***************************************************\n");
		printf("\n\t第 %d 页  共 %d 页\n",yeshu,zys);
		printf("\n\t可使用W（向上）S（向下）翻页，P退出：\n\n");
		if(p->next==NULL)break;
		p=p->next;
		
	}
	
	printf("已列出所有妖精的成绩和她们的平均分数\n\n");
	system("pause");
	calc_record();
}




void sort_main()
{
	system("cls");
	
	printf("当前妖精成绩信息如下：\n");
	print_table();
	//printf("*   姓名   * 学号 *性别*年龄*    电话    * 语文 * 数学 * 英语 *\n");
	struct student*p;
	p=head->next;
	
	for(int i=0;i<gsn;i++)
	{
		printf("*%10s*%6s*%4s*%4d*%12s*%6d*%6d*%6d*\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
		printf("***************************************************************\n");
		
		if(p->next==NULL)break;
		p=p->next;
	}
	printf("请选择一个命令：\n\n");
	Sleep(100); 
	printf("按妖精号排序---------1\n\n");
	Sleep(100); 
	printf("按语文成绩排序-------2\n\n");
	Sleep(100); 
	printf("按数学成绩排序-------3\n\n");
	Sleep(100); 
	printf("按英语成绩排序-------4\n\n");
	Sleep(100); 
	printf("按年龄排序-----------5\n\n");
	Sleep(100); 
	printf("返回主菜单-----------6\n\n");
	Sleep(100); 
	printf("：");
	
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
	printf("请选择：\n");
	printf("---\t1.升序\n");
	printf("---\t2.降序\n");
	printf("---\t3.返回\n");
	printf("请输入：\n");
	scanf("%d", &command);
	if(command==1)
	{
		struct student *stu[gsn];
		int i;//用于存贮及排序遍历
		int j;//用于选择排序
		int min;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//将链表数据读入数组
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
		}//选择排序
		struct student *c;//新头
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//尾插的尾
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
		int i;//用于存贮及排序遍历
		int j;//用于选择排序
		int mmax;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//将链表数据读入数组
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
		}//选择排序
		struct student *c;//新头
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//尾插的尾
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
	printf("请选择：\n");
	printf("---\t1.升序\n");
	printf("---\t2.降序\n");
	printf("---\t3.返回\n");
	printf("请输入：\n");
	scanf("%d", &command);
	if(command==1)
	{
		struct student *stu[gsn];
		int i;//用于存贮及排序遍历
		int j;//用于选择排序
		int min;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//将链表数据读入数组
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
		}//选择排序
		struct student *c;//新头
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//尾插的尾
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
		int i;//用于存贮及排序遍历
		int j;//用于选择排序
		int mmax;
		struct student *tmp;
		struct student *p;
		p = head -> next;
		for(i = 0; i < gsn; i++)
		{
			stu[i] = p ;
			if(p -> next == NULL) break;
			p = p -> next;
		}//将链表数据读入数组
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
		}//选择排序
		struct student *c;//新头
		c = (struct student *)malloc(sizeof(struct student));
		struct student *tail;//尾插的尾
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
	printf("请选择：\n");
	printf("---\t1.升序\n");
	printf("---\t2.降序\n");
	printf("---\t3.返回\n");
	printf("请输入：\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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
	printf("请选择：\n");
	printf("---\t1.升序\n");
	printf("---\t2.降序\n");
	printf("---\t3.返回\n");
	printf("请输入：\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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
	printf("请选择：\n");
	printf("---\t1.升序\n");
	printf("---\t2.降序\n");
	printf("---\t3.返回\n");
	printf("请输入：\n");
	scanf("%d", &flag);
	if(flag == 1)
		{
			struct student *stu[gsn];
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int min;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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
			int i;//用于存贮及排序遍历
			int j;//用于选择排序
			int mmax;
			struct student *tmp;
			struct student *p;
			p = head -> next;
			for(i = 0; i < gsn; i++)
				{
					stu[i] = p ;
					if(p -> next == NULL) break;
					p = p -> next;
				}//将链表数据读入数组
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
				}//选择排序
			struct student *c;//新头
			c = (struct student *)malloc(sizeof(struct student));
			struct student *tail;//尾插的尾
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

void print_table()    	//打印学生信息表格的表头函数
{
	printf("***************************************************************\n");
	printf("*   姓名   * 学号 *性别*年龄*    电话    * 语文 * 数学 * 英语 *\n");
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
	//printf("按任意键返回主菜单");
	//int fw;
	//scanf("%d",&fw);
	system("pause");
	menu();

}




void change_record()
{
	char num1[nmaxn];		//用户输入学生学号
	int k;
	system("cls");		//清屏函数
	int f2=0;
	int loop=0;
	printf("请输入要修改成绩的学生学号：");
	scanf("%s", num1);
	struct student *p;
	p=head->next;
	int a,b,c;
	int mm=0;
	for (int i = 0; i < gsn; i++)		//遍历链表，寻找是该学号是否存在
		{
			mm=0;
			if (strcmp(num1,p->num) == 0)
				{
					f2=1;

					printf("该学生现在成绩为：\n");
					print_table();
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);
					printf("请输入更新过的语文成绩：");
					scanf("%d",&a);
					printf("\n请输入更新过的数学成绩：");
					scanf("%d",&b);
					printf("\n请输入更新过的英语成绩：");
					scanf("%d",&c);
					p->chinese=a;
					p->math=b;
					p->english=c;
					printf("\n确认更改吗？ 1.更改  2.取消");
					scanf("%d",&mm);
					if(mm!=1)
						{
							f2=0;
							break;

						}
					save_record();
					system("cls");
					printf("该学生修改后成绩为：\n");
					print_table();
					printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n\n", p -> name, p -> num, p -> sex,p->age, p->phone,p -> chinese, p -> math, p -> english);


					if (p->next==NULL)
						break;

				}
			p=p->next;
			loop++;
		}
	//printf("%d",gsn);
	if (f2==0)		//gsn为全局变量学生的人数
		{
			system("cls");
			printf("不存在这个学号！\n\n");
		}

	printf("1.返回主界面\n2.继续查询\n");
	printf("请输入：");
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
void search_by_num()    //查询学生信息函数的子函数——按学号查询函数
{
	char num1[nmaxn];		//用户输入学生学号
	int k;
	system("cls");		//清屏函数
	int f2=0;
	int loop=0;
	printf("请输入要查找的学号：");
	scanf("%s", num1);
	struct student *p;
	p=head->next;
	print_table();
	for (int i = 0; i < gsn; i++)		//遍历链表，寻找是该学号是否存在
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
	if (f2==0)		//gsn为全局变量学生的人数
		{
			system("cls");
			printf("不存在这个学号！\n\n");
		}

	printf("1.返回主界面\n2.继续查询\n");
	printf("请输入：");
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
	char name1[nmaxn];		//用户输入学生姓名
	int k;
	system("cls");		//清屏函数
	int f2=0;
	int loop=0;
	printf("请输入要查找的姓名：");
	scanf("%s", name1);
	struct student *p;
	p=head->next;
	print_table();
	for (int i = 0; i < gsn; i++)		//遍历链表，寻找是该姓名是否存在
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
			printf("不存在这个姓名！\n\n");
		}

	printf("1.返回主界面\n2.继续查询\n");
	printf("请输入：");
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

void delete_record()    //删除妖精信息函数
{
	system("cls");//首先清屏 

	
	//预先定义各种变量 
	int judge=0;   //是否有该妖精的信息判别条件结果 
	char goer[nmaxn];  //将走之人 
	int accept=0;
	int accepter=0;   
	int flag=0;    //为了方便函数运行的三个变量 
	char *tempname;
	
	
	//确定妖精 
	printf("请输入要删除的妖精号QAQ：\n");
	scanf("%s",goer);
	
	struct student*p,*tmp;
	p=head->next;
	tmp=head;

	//int i,j;
	for(int n=0;n<gsn;n++)//通过妖精数目来遍历链表 
	{
		if(flag>0)//除第一次循环外，两个指针同时向后+1 
		{
			p=p->next;
			tmp=tmp->next;
		}
		flag++;//flag表示当前处理的位置 
		if(!strcmp(p->num,goer))//如果发现该妖精的学号信息 
		{
			//进行一步删除操作 
			printf("请确认要删除的妖精信息\n");
			printf("**********\n");
			printf("|%10s|\n|%10s|\n|%10s|\n|%10d|\n|%10d|\n|%10d|\n|%10d|\n",p->name,p->num,p->sex,p->age,p->chinese,p->math,p->english);
			printf("**********\n");
			printf("\n");
			printf("\t删除---1\n\t\取消---2\n\t:");
			scanf("%d",&accept);
			
			if(accept==1)
			{
				//确认删除的链表操作 
				//tempname=p->name;
				printf("已将 %s 删除\n",p->name);
				{
					tmp->next=p->next;
					p=p->next;
				}
				gsn--;//全局变量，gsn-1
				judge=1;//发现该妖精！ 
				save_record();//将删除后的信息保存到文件中
			}
			else if(accept==2)
			{	
				judge=1;//发现该妖精！但未确认删除 
				printf("已停止操作\n");
			}
		}
	}
	if(judge==0)		//该学号不存在
	{
		printf("查无此妖\n");
		printf("查无此妖\n");
		printf("查无此妖\n\n");
	}
	//system("cls");
	
	printf("\n");
	printf("是否进行进一步删除？");
	printf("\t继续删除---1\n\t\返回菜单---2\n\t：");
	scanf("%d",&accepter);
	//判断命令 
	if(accepter==1)
	{
		system("cls"); 
		delete_record();//嵌套调用函数 
	}
	else if(accepter==2)
	{
		system("cls"); 
		menu();//返回主界面 
	}
	
}

void search_record()  	//查询学生成绩函数    3
{
	system("cls");//首先清除屏幕菜单 


	//打印菜单
	printf("1：姓名定向查询\n");
	printf("2：学号定向查询\n");
	printf("3：性别批量查询\n");
	printf("4：返回主菜单\n");
	printf("请输入一个选项：\n");
	
	int x;//存放选项 
	scanf("%d", &x);
	 
	if(x==1)
		search_by_name();	//按姓名查询函数
	else if(x==2)
		search_by_num();	//按学号查询函数
	else if(x==3)
		search_by_sex();	//按性别查询查询
	else
		menu();
}




void search_by_sex()
{
	system("cls");//清除面板 
	
	struct student*p;
	p=head->next;
	
	char sex[nmaxn];//存放妖精性别 
	int temp0=0;
	int temp1=0;
	//int temp=0;
	
	printf("请输入一个性别（boy/girl）：");
	scanf("%s",sex);
	
	print_table();              //打印表头 
	for(int i=0;i<gsn;i++)		//寻找是否有符合的性别kora 
	{
		if(strcmp(sex,p->sex)==0)
		{
			temp1=1;//找到该妖精！ 
			printf("|%10s|%6s|%5s|%4d|%12s|%5d|%5d|%5d|\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
			if(p->next==NULL)break;
		}
		
		//temp+=1;
		p=p->next;
		
	}
	
	if(temp1==0)
	{
		system("cls");
		printf("不存在这个性别或输入有误！\n\n");
	}
		

	printf("\n");
	printf("是否继续查询？");
	printf("\t继续查询---1\n\t\返回菜单---2\n\t：");
	scanf("%d", &temp0);
	
	if(temp0==1)
	{
		search_by_sex();//递归调用
	}
	else if(temp0==2)
	{
		 menu();
	}
}

void input_record()
{
	//为新妖精创建一个空间 
	struct student *newer;
	newer=(struct student*)malloc(sizeof(struct student));
	
	system("cls");//清除菜单面板 
	//使用尾插法补充链表 
	struct student*tail;
	tail=head;
	for(;tail->next!=NULL;tail=tail->next);//寻找到结尾处 
	

	int isno;


	printf("请输入妖精名字：");
	scanf("%s",newer->name);

	printf("请输入妖精号（五位）：");
	scanf("%s",newer->num);

	printf("请输入妖精性别（boy/girl）：");
	scanf("%s",newer->sex);

	printf("请输入学生年龄：");
	scanf("%d",&newer->age);

	printf("请输入学生电话号码：");
	scanf("%s",newer->phone);

	printf("请输入学生语文成绩：");
	scanf("%d",&newer->chinese);

	printf("请输入学生数学成绩：");
	scanf("%d",&newer->math);

	printf("请输入学生英语成绩：");
	scanf("%d",&newer->english);

	newer->next=NULL;

	printf("\n\n\t\t请确认要保存的妖精信息\n\n\t\t");
	Sleep(1000);
	printf("是否要保存？\n"); 
	printf("\t\t是的----1\n\t\t再想想----2\n"); 
	scanf("%d", &isno);

	
	if (isno==1)		//若输入为y，则保存信息到文件中
		{
			gsn++;      //妖精数目增加一只 
			tail->next=newer;    //插入结尾 
			
			save_record();   //备份存档 
			menu();
		}
	else if(isno==2) 
		{
			printf("\n返回中！\n");
			Sleep(200);
			menu();
		}
}


void save_record()//保存妖精函数！ 
{
	printf("/n正在保存/n"); 
	FILE *save=fopen("goblinimformation.txt","w");//打开妖精txt 
	
	struct student*p;
	p=head->next;//创建节点 
	
	fprintf(save,"%d\n",gsn);
	
	for(int i=0;i<gsn;i++)
	{
		fprintf(save,"%s %s %s %d %s %d %d %d\n",p->name,p->num,p->sex,p->age,p->phone,p->chinese,p->math,p->english);
		//录入成绩 
		//printf("$$$"); 
		//fprintf(save,"%d\n",gsn-1);
		//gsn--;i++;
		p=p->next;
	}

	fclose(save);//guanbi
}


void READdata()
{
	
	FILE*point=fopen("goblinimformation.txt","r");		//定义一个文件指针
	
	
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
	fclose(point);		//关闭文件指针
}

void menu()
{
	int judge=0; //判断模式开启或关闭 
	system("cls");
	for(int i=0;i<10000;i++)
	{
		SetColorAndBackground(i,7);
		printf("少女祈祷中");
		//Sleep(100);
		//system("cls");
		
	}
	system("cls");
	READdata();       	//将妖精信息从txt文件中读到链表中 
	
	SetColorAndBackground(9,7);
	printf("\n\n\n\t\t\t\t\t正在加载图形界面...");
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
	printf("\n\n\n\t\t\t\t\tDone！");
	//Sleep(1000);
	system("cls");
	
	
	int x=0;
	//主菜单
	printf("###########################################\n");
	printf("︴︴  幻想乡寺子屋妖精成绩表（河童版）   ︴︴\n");
	printf("︴︴#####################################︴︴\n");
	printf("︴︴\t\t1.录入妖精成绩\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t2.阅览妖精成绩\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t3.查询妖精成绩\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t4.更新妖精信息\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t"); 
	SetColorAndBackground(0,4);
	printf("！5.删除妖精！"); 
	SetColorAndBackground(9,7);
	printf("\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t6.计算妖精成绩\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t7.排序妖精成绩\t\t ︴︴\n\n");Sleep(100);
	printf("︴︴\t\t8.退出\t\t         ︴︴\n");Sleep(100);
	printf("###########################################\n\n");Sleep(100);
	
	printf("请选择一个操作（一位数字）：\n");
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
				printf("河童保存器正在保存\n\n");
				save_record();
				Sleep(1000);
				printf("保存完毕，按任意键退出。\n");
				break;
			}
			default:
			{
				printf("有笨蛋输入错误，我不说是谁？\n");
				Sleep(1000);
				printf("即将返回...");
				Sleep(500);
				menu();
				break;
			}
		}
	}
	else if(judge==1)//字母模式 
	{
		x=9;
		printf("有笨蛋输入错误，我不说是谁？\n");
				Sleep(1000);
				printf("输入错误，保存失败，请重新进入。\n\n按任意键退出。");
				Sleep(500);
		return;
	}
}

void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


