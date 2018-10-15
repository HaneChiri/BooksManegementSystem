#pragma once
//#include "AccountList.h"//似乎不需要前向引用？
const int MAX_BORROW_NUM = 5;
const int PWD_LEN = 20;
const int NAME_LEN = 20;
const int USERNAME_LEN = 20;
class Account
{
protected:
	friend class AccountList;
	static int accountSum;//当前账户数量
	int UID;//user identify，根据当前账户数量自动初始化，用于唯一标识用户
	char name[NAME_LEN];
	bool sex;//false为女，true为男
	char phoneNumber[20];
	bool accountType;//0为普通用户，1为管理员
	char userName[USERNAME_LEN];
	char password[PWD_LEN];
	//Book borrowingBook[MAX_BORROW_NUM];//借阅列表
	//int borrowingN;//正在借阅书籍的数量
	Account* next;
public:
	Account(const char * p_name, const bool p_sex, const char * p_phoneNumber,
		const char * p_userName, const char * p_password);
	~Account();
	Account(const Account &a);
	void displayBorrowList();//借阅列表显示
	//int borrow(Book book);
	//int returnBook();
	int changePwd();//修改密码
	int getUID() { return UID; }
	char* getName() { return name; }

};
//int Account::accountSum = 0;//放在cpp里面定义才不会出错
