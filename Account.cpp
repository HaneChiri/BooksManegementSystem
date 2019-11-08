
#include "pch.h"
#include "Account.h"
#include <cstring>
#include <iostream>

#include "bookList.h"

/*
函数名：Account
函数功能：构造函数
参数：
返回值：
*/
Account::Account(const char * p_name,const bool p_sex,const char * p_phoneNumber,const char * p_userName,const char * p_password)
{
	strcpy(name, p_name);
	sex = p_sex;
	strcpy(phoneNumber, p_phoneNumber);
	accountType = 0;//默认为普通用户
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
	accountType = 0;//权限不会复制
	strcpy(UID, a.UID);
	strcpy(password, a.password);
}
/*
函数名：displayBorrowList
函数功能：显示正在借阅的书籍列表
参数：无
返回值：无
*/
void Account::displayBorrowList()
{
	for (int i = 0; i < MAX_BORROW_NUM; i++)
	{
		//borrowingBook.display(SingleLine);//调用书籍的单条显示
	}
	
}
/*
函数名：borrow
函数功能：借书
参数：书库指针，书指针
返回值：是否正常执行
备注：暂时不可用
*/
int Account::borrow(BookList *bookDataBase,int bookID)
{
	if (borrowingN >= MAX_BORROW_NUM || borrowingN<0)
	{
		return -1;
	}

	Book* b;
	if ((b=bookDataBase->findid(bookID))==NULL)
	{
		return -1;
	}//需要增加判断是否被借阅的分支，等待book类更新
	else
	{
		b->borrow();//借书
		borrowingBooks[borrowingN]= *b;//录入到借阅列表
		borrowingN++;
		printf("借阅成功！\n");
	}
	return 0;
}
/*
函数名：returnBook
函数功能：还书
参数：书库指针，书指针
返回值：是否正常执行
备注：暂时不可用
*/
int Account::returnBook(BookList *bookDataBase, int bookID)
{
	if (borrowingN >= MAX_BORROW_NUM || borrowingN < 0)
	{
		return -1;
	}
	Book* b;
	if ((b = bookDataBase->findid(bookID)) == NULL)
	{
		return -1;
	}//需要增加判断是否被借阅的分支，等待book类更新
	else
	{
		b->back();
		for (int i = 0; i < borrowingN; i++)
		{
			if (borrowingBooks[i].getid() == b->getid())
			{
				for (int j = i; j < borrowingN - 1; j++)//删除后，后面的书前移
				{
					borrowingBooks[j] = borrowingBooks[j + 1];
				}
			}
		}
		borrowingN--;
		printf("还书成功！\n");
	}
	
	
	return 0;
}
/*
函数名：changePwd
函数功能：修改密码
参数：无
返回值：是否修改成功
*/
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
