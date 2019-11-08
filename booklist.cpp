#include"booklist.h"

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
	   cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(15)<<"������"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"�Ƿ񱻽�"<<endl;
	   e=&book[i];
	   e->display();
	   r++; 
	} 
	if(r==0)
	cout<<"�Ҳ�������!"<<endl;
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
	   	cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(15)<<"������"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"�Ƿ񱻽�"<<endl;
	    e=&book[i];
	   	e->display();
	   	r++; 
  	} 
  	if(r==0)
  	cout<<"�Ҳ�������!"<<endl;
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
void display()
{
	for(int i=0;i<=top;i++) 
  	if(book[i].gettag()==0) 
    book[i].display(); 
}
