#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#include"book.h" 
#ifndef __booklist_h__
#define __booklist_h__
using namespace std;
class BookList{
	private:
		Book book[100];
		int top;
	public:
		BookList();
		~BookList();
		int addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);
		Book *findid(int bookid);
		Book *findname(char a[]);
		Book *findauthor(char a[]);
		void display();
};
#endif
