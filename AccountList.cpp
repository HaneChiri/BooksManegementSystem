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

AccountList::AccountList(const Account* data,const int n):registerNum(n)//β�巨���캯��
{
	head = new Account("root", true, "", "root", "");//ͷ�ڵ�
	head->next = NULL;
	Account*p1 ,*p2;//p2ָ��β�ڵ㣬p1ָ��p2ǰһ���ڵ�
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
	printf("Ŀǰע��������%d\n", registerNum);
	printf("UID\t�˺�Ȩ��\t����\t�Ա�\t��ϵ��ʽ\n");
	while (p != NULL)
	{
		displayNode(p);
		p = p->next;
	}
}

void AccountList::displayNode(const Account * p)const
{
	printf("%d\t%s\t%s\t%s\t%s\n",
		p->UID, p->accountType ? "����Ա" : "��ͨ�û�",
		p->name, p->sex ? "��" : "Ů", p->phoneNumber);
}

int AccountList::addNode(const Account * p)
{
	Account*q = new Account(*p);//��ʼ���½ڵ�
	Account*s = head;//ָ������β�ڵ�
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
	if (pre->next == NULL)//ɾ���Ľڵ㲻��������
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
��������findNode
�������ܣ�ͨ��ĳ�����Բ��ҵ�һ��ƥ��Ľڵ�
����ֵ��ָ���ҵ��Ľڵ��ָ��
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
	delete head;//�����һ���ڵ�ɾ��
}

