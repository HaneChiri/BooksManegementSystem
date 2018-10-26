#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#ifndef __book_h__
#define __book_h__
using namespace std;
class Book{
	private:
		int id,number;//编号、在架数量 
		char name[40];//书名 
		char author[20];//作者 
		char press[20];//出版社 
		float price;//价格 
		bool isBorrowed;//是否可借 
	public:
		Book(){}//无参构造函数 
		Book(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);//有参构造函数 
		bool borrow();//借书 
		bool back();//还书 
		void display();//输出书籍信息 
		~Book(){}//析构函数 
		char *getname();//获取书名 
		char *getauthor();//获取读者 
		char *getpresss();//获取出版社 
		float getprice();//获取价格 
		int getid();//获取编号 
		void setname(char na[]);//设置书名 
		void setauthor(char aa[]);//设置作者 
		void setpress(char pa[]);//设置出版社 
		void setprice(float pr);//设置价格 
		void setisBorrowed(int isB);//设置是否可借 
		void addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);//新增书籍 
};
#endif 
