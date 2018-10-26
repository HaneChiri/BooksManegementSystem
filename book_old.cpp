#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;
class Book{
	private:
		int id,number;
		char name[40];
		char author[20];
		char press[20];
		float price;
		bool isBorrowed;
	public:
		Book(){}
		Book(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed);
		bool borrow();
		bool back();
		void display();
		~Book(){}
		char *getname(){return name;} 
		char *getauthor(){return author;} 
		char *getpresss(){return press;} 
		float getprice(){return price;}
		int getid(){return id;}
		void setname(char na[]){strcpy(name,na);} 
		void setauthor(char aa[]){strcpy(author,aa);}
		void setpress(char pa[]){strcpy(press,pa);}
		void setprice(float pr){price=pr;}
		void setisBorrowed(int isB){isBorrowed=isB;} 
		void addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed); 
};
Book::Book(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed)
{
	this->id=_id;
	this->number=_number;
	strcpy(name,_name);
	strcpy(author,_author);
	strcpy(press,_press);
	this->price=_price;
	this->isBorrowed=_isBorrowed;
}
bool Book::borrow(){
	if(isBorrowed)
		{
			return 0;
		}
		else{
			isBorrowed=1;
			number--;
			return 1;
		}
}
bool Book::back(){
	isBorrowed=0;
	number++;
	return 1;
}
void Book::addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed) 
{ 
  	id=_id;
	number=_number;
	strcpy(name,_name);
	strcpy(author,_author);
	strcpy(press,_press);
	price=_price;
	isBorrowed=_isBorrowed;
} 
void Book::display(){
	cout<<setw(3)<<id<<setw(10)<<name<<setw(10)<<author<<setw(15)<<press<<setw(10)<<price<<setw(10)<<isBorrowed<<endl;
}
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
};

BookList::BookList(){
	  Book b; 
	  top=-1; 
	  fstream file("book.txt",ios::in); 
	  while (1) 
	  { 
	  file.read((char *)&b,sizeof(b)); 
	  if (!file) 
	   break; 
	  top++; 
	  book[top]=b; 
	  } 
	  file.close();  
}

Book* BookList::findid(int bookid)
{
	for(int i=0;i<=top;i++) 
	if(book[i].getid()==bookid) 
	{ 
	   return &book[i]; 
	} 
	return NULL; 
}

Book* BookList::findname(char a[])
{
	Book *e;
	int r=0;
	for(int i=0;i<=top;i++)
	if(strcmp(book[i].getname(),a)==0) 
	{ 
	   if(r==0)
	   cout<<setw(3)<<"编号"<<setw(10)<<"书名"<<setw(10)<<"作者"<<setw(15)<<"出版社"<<setw(10)<<"图书价格"<<setw(10)<<"是否被借"<<endl;
	   e=&book[i];
	   e->display();
	   r++; 
	} 
	if(r==0)
	cout<<"找不到该书!"<<endl;
	return NULL; 
}

Book* BookList::findauthor(char a[])
{
	Book *e;
  	int r=0;
  	for(int i=0;i<=top;i++) 
  	if(strcmp(book[i].getauthor(),a)==0) 
  	{ 
   		if(r==0)
	   	cout<<setw(3)<<"编号"<<setw(10)<<"书名"<<setw(10)<<"作者"<<setw(15)<<"出版社"<<setw(10)<<"图书价格"<<setw(10)<<"是否被借"<<endl;
	    	e=&book[i];
	   	e->display();
	   	r++; 
  	} 
  	if(r==0)
  	cout<<"找不到该书!"<<endl;
   	return NULL; 
}

int BookList::addbook(int _id,int _number,char *_name,char *_author,char *_press,float _price,bool _isBorrowed)
{
	Book *p=findid(_id); 
    	if (NULL==p) 
   { 
	   top++; 
	   book[top].addbook(_id,_number,_name,_author,_press,_price,_isBorrowed); 
	   return 1; 
   } 
   return 0; 
}

BookList::~BookList()
{
  	fstream file("book.txt",ios::out); 
  	for(int i=0;i<=top;i++)
  	file.write((char *)&book[i],sizeof(book[i])); 
  	file.close(); 	
}

int main()
{
	return 0;
}
