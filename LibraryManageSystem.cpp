// LibraryManageSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//
#include "pch.h"
#include <iostream>
#include <cstring>
#include <conio.h>
#include "AccountList.h"

#include "bookList.h"
using namespace std;

const char * DATA_FILE_NAME = "data.txt";


char menu();
int main()
{
	AccountList aList(DATA_FILE_NAME);
	BookList bList;
	char cmd=' ';
	int bookID = 0;
	int ret = 0;//返回值测试
	while (cmd != 'q'&&cmd != 'Q')
	{
		system("cls");
		cmd=menu();
		switch (cmd)
		{
		case 'A':case 'a'://借书
			ret=aList.signIn();
			if(ret!=0)//登陆
			{
				system("pause");
				ret = 0;
				break;
			}
			else
			{
				printf("请输入你要借的书的ID\n");
				scanf("%d", bookID);
				aList.getCurrentAccount()->borrow(&bList, bookID);//借书暂时不可用
			}
			break;
		case 'B':case 'b'://还书暂时不可用
			printf("请输入你要还的书的ID\n");
			scanf("%d", bookID);
			aList.getCurrentAccount()->returnBook(&bList, bookID);//借书
			break;
		case 'C':case 'c'://借阅查询
			
			break;
		case 'D':case 'd'://查询图书

			break;
		default:
			break;
		}
	}
	
	return 0;
}
char menu()
{
	cout << "图书馆管理系统\n" << endl;
	cout << "请输入序号选择要使用的功能：\n" << endl;
	cout << "A.借书\n" << endl;
	cout << "B.还书\n" << endl;
	cout << "C.借阅查询\n" << endl;
	cout << "D.查询图书\n" << endl;
	cout << "Q.退出\n" << endl;
	char cmd =getchar();
	return cmd;
}
