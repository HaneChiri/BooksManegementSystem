#include "pch.h"
#include "AccountList.h"
#include "Account.h"
#include <iostream>

#include "bookList.h"

using namespace std;
/*
函数名：AccountList
函数功能：构造函数
参数：无
返回值：无
*/
AccountList::AccountList():registerNum(0),dataFileName("data.txt")
{
	head = new Account;
	strcpy(head->UID, "NULL");
	head->next = NULL;
	currentAccount = head;
}
AccountList::AccountList(const Account data[],const int n):registerNum(n)//尾插法构造函数
{//此函数不更新了，请不要使用
	head = new Account("root", true, "", "root", "");//头节点
	head->next = NULL;
	Account*p1 ,*p2;//p2指向尾节点，p1指向p2前一个节点
	p1 = p2 = head;
	for (int i = 0; i < n; i++)
	{
		p2 = new Account(data[i].name, data[i].sex, data[i].phoneNumber, data[i].UID, data[i].password);
		p1->next = p2;
		p1 = p1->next;
	}
	p2->next = NULL;
}
AccountList::AccountList(const char * fileName):registerNum(0),dataFileName(fileName)
{
	head = new Account();
	strcpy(head->UID, "NULL");
	head->next = NULL;
	loadData();
	currentAccount = head;
}
/*
函数名：displayList
函数功能：显示整个账号列表
参数：无
返回值：无
*/
void AccountList::displayList()const
{
	Account* p = head->next;
	printf("目前注册人数：%d\n", registerNum);
	printf("当前登陆账号：%s\n", currentAccount->UID);
	printf("UID\t账号权限\t姓名\t\t性别\t联系方式\n");
	while (p != NULL)
	{
		displayNode(p);
		p = p->next;
	}
}
/*
函数名：displayNode
函数功能：显示单条账号信息
参数：指向要显示的账号的指针
返回值：无
*/
void AccountList::displayNode(const Account * p)const
{
	printf("%s\t%s\t%s\t%s\t%s\n",
		p->UID, p->accountType ? "管理员" : "普通用户",
		p->name, p->sex ? "男" : "女", p->phoneNumber);
}
/*
函数名：addNode
函数功能：增加一个账户到链表中
参数：指向要增加的账号的指针
返回值：是否成功
*/
int AccountList::addNode(const Account * p)
{
	Account*q = new Account(*p);//初始化新节点
	Account*s = head;//指向链表尾节点
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = q;
	q->next = NULL;
	registerNum++;
	return 0;
}
/*
函数名：deleteNode
函数功能：删除一个账号
参数：指向要删除的账号的指针
返回值：是否成功
*/
int AccountList::deleteNode(Account * p)
{
	Account* pre = head;
	while (pre->next != p && pre->next!=NULL)
	{
		pre = pre->next;
	}
	if (pre->next == NULL)//删除的节点不在链表中
	{
		return -1;
	}
	else
	{
		pre->next = p->next;
		delete p;
		registerNum--;
		return 0;
	}
	return -1;
}
/*
函数名：deleteList
函数功能：删除整个账号表
参数：无
返回值：是否成功
*/
int AccountList::deleteList()
{
	Account*p = head->next;
	while (p != NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}
	registerNum = 0;
	head->next=NULL;
	return 0;
}

/*
重载函数名：findNode
函数功能：通过某个属性查找第一个匹配的节点
参数：字段名，要查找的值
返回值：指向找到的节点的指针,找不到则返回NULL
*/
Account* AccountList::findNode(AccountCol key,const char*value)
{
	Account* p = head->next;
	switch (key)
	{
	case T_NAME:
		while (p != NULL)
		{
			if (strcmp(p->name, value) == 0)
			{
				return p;
			}
			p = p->next;
		}
		break;
	case T_UID:
		while (p != NULL)
		{
			if (strcmp(p->UID, value) == 0)
			{
				return p;
			}
			p = p->next;
		}
		break;
	}
	
	return NULL;
}
/*
函数名：saveData
函数功能：保存数据到文件中
参数：保存到的文件名
返回值：存入的记录条数
*/
int AccountList::saveData()
{
	FILE* fp = fopen(dataFileName,"w");
	if (fp == NULL)
	{
		return -1;
	}
	//保存数据
	Account* data = head->next;
	while (data->next != NULL)
	{
		//姓名:性别:权限:联系方式:UID:密码
		fprintf(fp, "%s %d %d %s %s %s\n",
			data->name,(data->sex?1:0),data->accountType,data->phoneNumber,data->UID,data->password
			);
		data = data->next;
	}
	fprintf(fp, "%s %d %d %s %s %s",
		data->name, (data->sex ? 1 : 0), data->accountType, data->phoneNumber, data->UID, data->password
	);//防止多录入一个\n
	fclose(fp);
	return registerNum;
}
/*
函数名：loadData
函数功能：从文件中读取数据覆盖当前整个对象
参数：读取的文件名
返回值：读取的记录条数
*/
int AccountList::loadData()
{
	FILE* fp = fopen(dataFileName, "r");
	if (fp == NULL)
	{
		return -1;
	}
	deleteList();
	Account *data=new Account();//加上括号初始化此对象
	int dataNum = 0;
	while (!feof(fp))//未到文件尾则一直读取
	{
		//姓名:性别:权限:联系方式:UID:密码
		fscanf(fp, "%s %d %d %s %s %s",
			data->name, &data->sex, &data->accountType, data->phoneNumber, data->UID, data->password
		);
		addNode(data);
		dataNum++;
	}
	delete data;
	fclose(fp);

	return dataNum;
}

int AccountList::signUp()
{
	Account *newAccount = new Account;
	//==============================//
	printf("输入姓名：\n");
	scanf("%s", newAccount->name);
	printf("输入性别：\n");
	scanf(" %d", &newAccount->sex);
	printf("输入联系方式：\n");
	scanf(" %s", newAccount->phoneNumber);
	do
	{
		printf("输入用户名，这将是你的登陆用的账号，长度在%d个字符以内：\n", NAME_LEN);
		scanf(" %s", newAccount->UID);

	} while (findNode(T_UID, newAccount->UID)!=NULL && printf("用户名重复！请再次输入"));
	//条件：（用户名重复 && 错误信息）当用户名重复的时候，前面为真，然后打印后面表达式

	
	strcpy(newAccount->password, "666666");
	newAccount->accountType = 0;//设置权限为普通用户
	/*/==============================//
	FILE* fp = fopen(dataFileName, "r");
	if (fp == NULL)
	{
		return -1;
	}
	//获取下一个可用ID
	char nextUID[CARD_ID_LEN] = {0};
	int uid = 0;
	fscanf(fp, "%d", &uid);
	fclose(fp);
	uid++;
	for (int i = CARD_ID_LEN - 2;i >= 0; i--)
	{
		nextUID[i] = uid % 10+'0';
		uid /= 10;
	}
	nextUID[CARD_ID_LEN - 1] = '\0';
	//==============================/*/

	addNode(newAccount);
	delete newAccount;
	printf("注册成功！默认密码是666666\n");
	return 0;
}

int AccountList::signIn()
{
	
	printf("请输入你的借书卡ID：\n");
	char uid[CARD_ID_LEN] = { 0 };
	scanf("%s", uid);
	Account *loginAccount = findNode(T_UID, uid);
	if (loginAccount == NULL)
	{
		printf("没有这个ID\n");
		return -1;
	}
	printf("请输入你的借书卡密码：\n");
	char pwd[PWD_LEN] = { 0 };
	scanf(" %s", pwd);
	if (strcmp(pwd, loginAccount->password) != 0)
	{
		printf("密码错误\n");
		return -2;
	}
	currentAccount = loginAccount;
	printf("登陆成功！\n");
	return 0;
}





/*
函数名：~AccountList
函数功能：在程序退出的时候保存数据到文件
参数：无
返回值：无
*/
AccountList::~AccountList()
{
	saveData();
	Account*p = head->next;
	while (p != NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}
	delete head;//将最后一个节点删除
}

