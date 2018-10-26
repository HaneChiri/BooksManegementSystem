
#pragma once
//#include "AccountList.h"//似乎不需要前向引用？
#include "bookList.h"


const int MAX_BORROW_NUM = 5;
const int PWD_LEN = 20;
const int NAME_LEN = 20;
const int CARD_ID_LEN = 20;

class Account
{
protected:
	friend class AccountList;
	char name[NAME_LEN];//姓名
	bool sex;//性别 false为女，true为男
	char phoneNumber[20];//电话号码
	bool accountType;//0为普通用户，1为管理员
	char UID[CARD_ID_LEN];//账号
	char password[PWD_LEN];//密码
	//======================//

	Book borrowingBooks[MAX_BORROW_NUM];//借阅列表
	int borrowingN;//正在借阅书籍的数量

	//======================/*/
	Account* next;
public:
	Account(const char * p_name, const bool p_sex, const char * p_phoneNumber,
		const char * p_userName, const char * p_password);
	Account(){} 
	~Account();
	Account(const Account &a);
	//======================//
	void displayBorrowList();//借阅列表显示
	int borrow( BookList *book, int bookID);
	int returnBook(BookList *bookDataBase, int bookID);
	//======================/*/
	int changePwd();//修改密码
	char* getName() { return name; }

};
//int Account::accountSum = 0;//放在cpp里面定义才不会出错
