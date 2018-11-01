#include "pch.h"
#include "book.h"

Book::Book(int _id, int _number, char *_name, char *_author, char *_press, float _price, bool _isBorrowed)
{
	this->id = _id;
	this->number = _number;
	strcpy(name, _name);
	strcpy(author, _author);
	strcpy(press, _press);
	this->price = _price;
	this->isBorrowed = _isBorrowed;
}

bool Book::borrow() {
	if (isBorrowed && number > 0)
	{
		number--;
		return 1;
	}
	else
	{
		return 0;

	}
}

bool Book::back() {
	isBorrowed = 1;
	number++;
	return 1;
}

char* Book::getname()
{
	return name;
}

char* Book::getauthor()
{
	return author;
}

char* Book::getpresss()
{
	return press;
}

float Book::getprice()
{
	return price;
}

int Book::getid()
{
	return id;
}

void Book::setname(char na[])
{
	strcpy(name, na);
}

void Book::setauthor(char aa[])
{
	strcpy(author, aa);
}

void Book::setpress(char pa[])
{
	strcpy(press, pa);
}

void Book::setprice(float pr)
{
	price = pr;
}

void Book::setisBorrowed(int isB)
{
	isBorrowed = isB;
}

void Book::addbook(int _id, int _number, char *_name, char *_author, char *_press, float _price, bool _isBorrowed)
{
	id = _id;
	number = _number;
	strcpy(name, _name);
	strcpy(author, _author);
	strcpy(press, _press);
	price = _price;
	isBorrowed = _isBorrowed;
}
void Book::display()
{
	cout << setw(3) << id << setw(10) << name << setw(10) << author << setw(15) << press << setw(10) << price << setw(10) << isBorrowed << endl;
}
