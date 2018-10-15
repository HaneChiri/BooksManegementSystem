#include "pch.h"
#include "AccountList.h"
#include "Account.h"
#include <iostream>
using namespace std;
AccountList::AccountList():registerNum(0)
{
	head = new Account("root", true,"" , "root", "");
	head->next = NULL;
}

AccountList::AccountList(const Account* data,const int n):registerNum(n)//尾插法构造函数
{
	head = new Account("root", true, "", "root", "");//头节点
	head->next = NULL;
	Account*p1 ,*p2;//p2指向尾节点，p1指向p2前一个节点
	p1 = p2 = head;
	for (int i = 0; i < n; i++)
	{
		p2 = new Account(data[i].name, data[i].sex, data[i].phoneNumber, data[i].userName, data[i].password);
		p1->next = p2;
		p1 = p1->next;
	}
	p2->next = NULL;
}

void AccountList::displayList()const
{
	Account* p = head->next;
	printf("目前注册人数：%d\n", registerNum);
	printf("UID\t账号权限\t姓名\t性别\t联系方式\n");
	while (p != NULL)
	{
		displayNode(p);
		p = p->next;
	}
}

void AccountList::displayNode(const Account * p)const
{
	printf("%d\t%s\t%s\t%s\t%s\n",
		p->UID, p->accountType ? "管理员" : "普通用户",
		p->name, p->sex ? "男" : "女", p->phoneNumber);
}

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
函数名：findNode
函数功能：通过某个属性查找第一个匹配的节点
返回值：指向找到的节点的指针
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
	case T_USERNAME:
		while (p != NULL)
		{
			if (strcmp(p->userName, value) == 0)
			{
				return p;
			}
			p = p->next;
		}
		break;
	}
	
	return NULL;
}
Account * AccountList::findNode(AccountCol key, int value)
{
	Account* p = head->next;
	switch (key)
	{
	case T_UID:
		while (p != NULL)
		{
			if (p->UID==value)
			{
				return p;
			}
			p = p->next;
		}
		break;
	}

	return NULL;
}






AccountList::~AccountList()
{
	Account*p = head->next;
	while (p != NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}
	delete head;//将最后一个节点删除
}

