
#pragma once
//#include "AccountList.h"//�ƺ�����Ҫǰ�����ã�
#include "bookList.h"


const int MAX_BORROW_NUM = 5;
const int PWD_LEN = 20;
const int NAME_LEN = 20;
const int CARD_ID_LEN = 20;

class Account
{
protected:
	friend class AccountList;
	char name[NAME_LEN];//����
	bool sex;//�Ա� falseΪŮ��trueΪ��
	char phoneNumber[20];//�绰����
	bool accountType;//0Ϊ��ͨ�û���1Ϊ����Ա
	char UID[CARD_ID_LEN];//�˺�
	char password[PWD_LEN];//����
	//======================//

	Book borrowingBooks[MAX_BORROW_NUM];//�����б�
	int borrowingN;//���ڽ����鼮������

	//======================/*/
	Account* next;
public:
	Account(const char * p_name, const bool p_sex, const char * p_phoneNumber,
		const char * p_userName, const char * p_password);
	Account(){} 
	~Account();
	Account(const Account &a);
	//======================//
	void displayBorrowList();//�����б���ʾ
	int borrow( BookList *book, int bookID);
	int returnBook(BookList *bookDataBase, int bookID);
	//======================/*/
	int changePwd();//�޸�����
	char* getName() { return name; }

};
//int Account::accountSum = 0;//����cpp���涨��Ų������
