#include "pch.h"
#include "AccountList.h"
#include "Account.h"
#include <iostream>

#include "bookList.h"

using namespace std;
/*
��������AccountList
�������ܣ����캯��
��������
����ֵ����
*/
AccountList::AccountList():registerNum(0),dataFileName("data.txt")
{
	head = new Account;
	strcpy(head->UID, "NULL");
	head->next = NULL;
	currentAccount = head;
}
AccountList::AccountList(const Account data[],const int n):registerNum(n)//β�巨���캯��
{//�˺����������ˣ��벻Ҫʹ��
	head = new Account("root", true, "", "root", "");//ͷ�ڵ�
	head->next = NULL;
	Account*p1 ,*p2;//p2ָ��β�ڵ㣬p1ָ��p2ǰһ���ڵ�
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
��������displayList
�������ܣ���ʾ�����˺��б�
��������
����ֵ����
*/
void AccountList::displayList()const
{
	Account* p = head->next;
	printf("Ŀǰע��������%d\n", registerNum);
	printf("��ǰ��½�˺ţ�%s\n", currentAccount->UID);
	printf("UID\t�˺�Ȩ��\t����\t\t�Ա�\t��ϵ��ʽ\n");
	while (p != NULL)
	{
		displayNode(p);
		p = p->next;
	}
}
/*
��������displayNode
�������ܣ���ʾ�����˺���Ϣ
������ָ��Ҫ��ʾ���˺ŵ�ָ��
����ֵ����
*/
void AccountList::displayNode(const Account * p)const
{
	printf("%s\t%s\t%s\t%s\t%s\n",
		p->UID, p->accountType ? "����Ա" : "��ͨ�û�",
		p->name, p->sex ? "��" : "Ů", p->phoneNumber);
}
/*
��������addNode
�������ܣ�����һ���˻���������
������ָ��Ҫ���ӵ��˺ŵ�ָ��
����ֵ���Ƿ�ɹ�
*/
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
/*
��������deleteNode
�������ܣ�ɾ��һ���˺�
������ָ��Ҫɾ�����˺ŵ�ָ��
����ֵ���Ƿ�ɹ�
*/
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
��������deleteList
�������ܣ�ɾ�������˺ű�
��������
����ֵ���Ƿ�ɹ�
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
���غ�������findNode
�������ܣ�ͨ��ĳ�����Բ��ҵ�һ��ƥ��Ľڵ�
�������ֶ�����Ҫ���ҵ�ֵ
����ֵ��ָ���ҵ��Ľڵ��ָ��,�Ҳ����򷵻�NULL
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
��������saveData
�������ܣ��������ݵ��ļ���
���������浽���ļ���
����ֵ������ļ�¼����
*/
int AccountList::saveData()
{
	FILE* fp = fopen(dataFileName,"w");
	if (fp == NULL)
	{
		return -1;
	}
	//��������
	Account* data = head->next;
	while (data->next != NULL)
	{
		//����:�Ա�:Ȩ��:��ϵ��ʽ:UID:����
		fprintf(fp, "%s %d %d %s %s %s\n",
			data->name,(data->sex?1:0),data->accountType,data->phoneNumber,data->UID,data->password
			);
		data = data->next;
	}
	fprintf(fp, "%s %d %d %s %s %s",
		data->name, (data->sex ? 1 : 0), data->accountType, data->phoneNumber, data->UID, data->password
	);//��ֹ��¼��һ��\n
	fclose(fp);
	return registerNum;
}
/*
��������loadData
�������ܣ����ļ��ж�ȡ���ݸ��ǵ�ǰ��������
��������ȡ���ļ���
����ֵ����ȡ�ļ�¼����
*/
int AccountList::loadData()
{
	FILE* fp = fopen(dataFileName, "r");
	if (fp == NULL)
	{
		return -1;
	}
	deleteList();
	Account *data=new Account();//�������ų�ʼ���˶���
	int dataNum = 0;
	while (!feof(fp))//δ���ļ�β��һֱ��ȡ
	{
		//����:�Ա�:Ȩ��:��ϵ��ʽ:UID:����
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
	printf("����������\n");
	scanf("%s", newAccount->name);
	printf("�����Ա�\n");
	scanf(" %d", &newAccount->sex);
	printf("������ϵ��ʽ��\n");
	scanf(" %s", newAccount->phoneNumber);
	do
	{
		printf("�����û������⽫����ĵ�½�õ��˺ţ�������%d���ַ����ڣ�\n", NAME_LEN);
		scanf(" %s", newAccount->UID);

	} while (findNode(T_UID, newAccount->UID)!=NULL && printf("�û����ظ������ٴ�����"));
	//���������û����ظ� && ������Ϣ�����û����ظ���ʱ��ǰ��Ϊ�棬Ȼ���ӡ������ʽ

	
	strcpy(newAccount->password, "666666");
	newAccount->accountType = 0;//����Ȩ��Ϊ��ͨ�û�
	/*/==============================//
	FILE* fp = fopen(dataFileName, "r");
	if (fp == NULL)
	{
		return -1;
	}
	//��ȡ��һ������ID
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
	printf("ע��ɹ���Ĭ��������666666\n");
	return 0;
}

int AccountList::signIn()
{
	
	printf("��������Ľ��鿨ID��\n");
	char uid[CARD_ID_LEN] = { 0 };
	scanf("%s", uid);
	Account *loginAccount = findNode(T_UID, uid);
	if (loginAccount == NULL)
	{
		printf("û�����ID\n");
		return -1;
	}
	printf("��������Ľ��鿨���룺\n");
	char pwd[PWD_LEN] = { 0 };
	scanf(" %s", pwd);
	if (strcmp(pwd, loginAccount->password) != 0)
	{
		printf("�������\n");
		return -2;
	}
	currentAccount = loginAccount;
	printf("��½�ɹ���\n");
	return 0;
}





/*
��������~AccountList
�������ܣ��ڳ����˳���ʱ�򱣴����ݵ��ļ�
��������
����ֵ����
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
	delete head;//�����һ���ڵ�ɾ��
}

