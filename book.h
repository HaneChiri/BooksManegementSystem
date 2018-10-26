#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#ifndef __book_h__
#define __book_h__
using namespace std;
class Book{
	private:
		int id,number;//��š��ڼ����� 
		char name[40];//���� 
		char author[20];//���� 
		char press[20];//������ 
		float price;//�۸� 
		bool isBorrowed;//�Ƿ�ɽ� 
	public:
		Book(){}//�޲ι��캯�� 
		Book(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);//�вι��캯�� 
		bool borrow();//���� 
		bool back();//���� 
		void display();//����鼮��Ϣ 
		~Book(){}//�������� 
		char *getname();//��ȡ���� 
		char *getauthor();//��ȡ���� 
		char *getpresss();//��ȡ������ 
		float getprice();//��ȡ�۸� 
		int getid();//��ȡ��� 
		void setname(char na[]);//�������� 
		void setauthor(char aa[]);//�������� 
		void setpress(char pa[]);//���ó����� 
		void setprice(float pr);//���ü۸� 
		void setisBorrowed(int isB);//�����Ƿ�ɽ� 
		void addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);//�����鼮 
};
#endif 
