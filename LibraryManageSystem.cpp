// LibraryManageSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include "AccountList.h"
using namespace std;


int main()
{
	Account data[]=
	{
		Account("小明",true,"123456789","xiaoming","987654321"),
		Account("小美", false, "123456789", "xiaomei", "987654321"),
		Account("小刚", true, "123456789", "xiaogang", "987654321"),

	};
	AccountList*p=new AccountList(data,3);
	p->displayList();
	p->addNode(&data[2]);
	p->displayList();
	cout << "=================" << endl;
	Account a("", true, "", "xiaoming", "");
	p->displayNode(p->findNode(T_NAME,"小刚"));//注意这里只能测试找得到的情况，更正确的是需要检测是否返回值为NULL
	p->deleteNode(p->findNode(T_NAME, "小刚"));
	p->displayList();

	data[1].changePwd();

	return 0;
}

