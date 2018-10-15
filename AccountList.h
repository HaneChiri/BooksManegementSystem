#pragma once
#include "Account.h"
#include <iostream>
enum AccountCol//账号类字段类型
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
	void displayNode(const Account * p)const;//底层const，无法通过p修改指向的地址的值
	int addNode(const Account* p);//对p指向的内容只读
	int deleteNode(Account *p);

	Account* findNode(AccountCol key, const char*value);
	Account* findNode(AccountCol key, int value);
	
};

