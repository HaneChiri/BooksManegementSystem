#pragma once
#include "Account.h"
#include <iostream>
#include "book.h"//��Ҫ�޸�

enum AccountCol//�˺����ֶ�����
{
	T_UID,T_NAME
};

class AccountList
{
private:
	Account* head;
	int registerNum;
	Account* currentAccount;//��ǰ�Ѿ���½���˺�
	const char* dataFileName;//�󶨵��ļ���
public:
	AccountList();
	AccountList(const Account data[], int n);//�������õĺ���
	AccountList(const char *fileName);
	~AccountList();

	Account * getCurrentAccount() { return currentAccount; }
	//�������
	void displayList()const;
	void displayNode(const Account * p)const;//�ײ�const���޷�ͨ��p�޸�ָ��ĵ�ַ��ֵ
	int addNode(const Account* p);//��pָ�������ֻ��
	int deleteNode(Account *p);
	int deleteList();

	Account* findNode(AccountCol key, const char*value);
	//�ļ�����
	int saveData();
	int loadData();

	int signUp();//ע��
	int signIn();//��½
	

	
};

