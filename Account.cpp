#include "pch.h"
#include "Account.h"
#include <cstring>
#include <iostream>

/*
��������Account
�������ܣ����캯��
������
����ֵ��
*/
Account::Account(const char * p_name,const bool p_sex,const char * p_phoneNumber,const char * p_userName,const char * p_password)
{
	strcpy(name, p_name);
	sex = p_sex;
	strcpy(phoneNumber, p_phoneNumber);
	accountType = 0;//Ĭ��Ϊ��ͨ�û�
	strcpy(UID, p_userName);
	strcpy(password, p_password);
}
Account::~Account()
{
}
Account::Account(const Account & a)
{
	strcpy(name, a.name);
	sex = a.sex;
	strcpy(phoneNumber, a.phoneNumber);
	accountType = 0;//Ȩ�޲��Ḵ��
	strcpy(UID, a.UID);
	strcpy(password, a.password);
}
/*
��������displayBorrowList
�������ܣ���ʾ���ڽ��ĵ��鼮�б�
��������
����ֵ����
*/
void Account::displayBorrowList()
{
	for (int i = 0; i < MAX_BORROW_NUM; i++)
	{
		//borrowingBook[i].display(SingleLine);//�����鼮�ĵ�����ʾ
	}
	
}
/*
��������changePwd
�������ܣ��޸�����
��������
����ֵ���Ƿ��޸ĳɹ�
*/
int Account::changePwd()
{
	char pwd[PWD_LEN];
	char surePwd[PWD_LEN];
	printf("������������룺\n");
	scanf("%s", pwd);
	
	if (strcmp(pwd, password) == 0)
	{
		fflush(stdin);//����������Ҫ���
		printf("��������������룺\n");
		scanf("%s", pwd);
		fflush(stdin);
		printf("���������ȷ�����룺\n");
		scanf("%s", surePwd);
		if (strcmp(pwd, surePwd) == 0 )
		{
			strcpy(password, pwd);
			return 0;
		}
		
	}
	printf("���벻ƥ�䣡δ�޸�\n");
	return -1;//δ�޸�

}
