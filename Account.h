#pragma once
//#include "AccountList.h"//�ƺ�����Ҫǰ�����ã�
const int MAX_BORROW_NUM = 5;
const int PWD_LEN = 20;
const int NAME_LEN = 20;
const int USERNAME_LEN = 20;
class Account
{
protected:
	friend class AccountList;
	static int accountSum;//��ǰ�˻�����
	int UID;//user identify�����ݵ�ǰ�˻������Զ���ʼ��������Ψһ��ʶ�û�
	char name[NAME_LEN];
	bool sex;//falseΪŮ��trueΪ��
	char phoneNumber[20];
	bool accountType;//0Ϊ��ͨ�û���1Ϊ����Ա
	char userName[USERNAME_LEN];
	char password[PWD_LEN];
	//Book borrowingBook[MAX_BORROW_NUM];//�����б�
	//int borrowingN;//���ڽ����鼮������
	Account* next;
public:
	Account(const char * p_name, const bool p_sex, const char * p_phoneNumber,
		const char * p_userName, const char * p_password);
	~Account();
	Account(const Account &a);
	void displayBorrowList();//�����б���ʾ
	//int borrow(Book book);
	//int returnBook();
	int changePwd();//�޸�����
	int getUID() { return UID; }
	char* getName() { return name; }

};
//int Account::accountSum = 0;//����cpp���涨��Ų������
