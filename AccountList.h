#pragma once
#include "Account.h"
#include <iostream>
enum AccountCol//�˺����ֶ�����
{
	T_UID,T_NAME,T_USERNAME
};
class AccountList
{
private:
	Account* head;
	int registerNum;
public:
	AccountList();
	AccountList(const Account* data, int n);
	~AccountList();

	void displayList()const;
	void displayNode(const Account * p)const;//�ײ�const���޷�ͨ��p�޸�ָ��ĵ�ַ��ֵ
	int addNode(const Account* p);//��pָ�������ֻ��
	int deleteNode(Account *p);

	Account* findNode(AccountCol key, const char*value);
	Account* findNode(AccountCol key, int value);
	
};

