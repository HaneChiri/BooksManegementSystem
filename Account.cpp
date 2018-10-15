#include "pch.h"
#include "Account.h"
#include <cstring>
#include <iostream>

int Account::accountSum = 0;//初始化
Account::Account(const char * p_name,const bool p_sex,const char * p_phoneNumber,const char * p_userName,const char * p_password)
{
	strcpy(name, p_name);
	sex = p_sex;
	strcpy(phoneNumber, p_phoneNumber);
	accountType = 0;//默认为普通用户
	strcpy(userName, p_userName);
	strcpy(password, p_password);
	//分配UID
	accountSum++;
	UID = accountSum;
}
Account::~Account()
{
	accountSum--;
}
Account::Account(const Account & a)
{
	strcpy(name, a.name);
	sex = a.sex;
	strcpy(phoneNumber, a.phoneNumber);
	accountType = 0;//权限不会复制
	strcpy(userName, a.userName);
	strcpy(password, a.password);
	//重新分配UID
	accountSum++;
	UID = accountSum;
}
void Account::displayBorrowList()
{
	for (int i = 0; i < MAX_BORROW_NUM; i++)
	{
		//borrowingBook[i].display(SingleLine);//调用书籍的单条显示
	}
	
}

int Account::changePwd()
{
	char pwd[PWD_LEN];
	char surePwd[PWD_LEN];
	printf("请输入你的密码：\n");
	scanf("%s", pwd);
	
	if (strcmp(pwd, password) == 0)
	{
		fflush(stdin);//连续输入需要这个
		printf("请输入你的新密码：\n");
		scanf("%s", pwd);
		fflush(stdin);
		printf("请输入你的确认密码：\n");
		scanf("%s", surePwd);
		if (strcmp(pwd, surePwd) == 0 )
		{
			strcpy(password, pwd);
			return 0;
		}
		
	}
	printf("密码不匹配！未修改\n");
	return -1;//未修改

}
