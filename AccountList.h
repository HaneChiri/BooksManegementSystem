#pragma once
#include "Account.h"
#include <iostream>
enum AccountCol//账号类字段类型
{
	T_UID,T_NAME
};

class AccountList
{
private:
	Account* head;
	int registerNum;
	Account* currentAccount;//当前已经登陆的账号
	const char* dataFileName;//绑定的文件名
public:
	AccountList();
	AccountList(const Account data[], int n);//准备废弃的函数
	AccountList(const char *fileName);
	~AccountList();
	//链表操作
	void displayList()const;
	void displayNode(const Account * p)const;//底层const，无法通过p修改指向的地址的值
	int addNode(const Account* p);//对p指向的内容只读
	int deleteNode(Account *p);
	int deleteList();

	Account* findNode(AccountCol key, const char*value);
	//文件操作
	int saveData();
	int loadData();

	int signUp();//注册
	int signIn();//登陆
	
	
};

