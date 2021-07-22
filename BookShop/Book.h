#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string author;
	string title;
	string publisher;
	float price = 0;
	int stock = 0;

public:
	Book( string title = "", string author = "", string publisher = "", float price=0.0, int stock=0);
	~Book();

	void inputAuthor();
	void setAuthor(string &aut);
	string getAuthor();

	void inputTitle();
	void setTitle(string &tit);
	string getTitle();

	void inputPublisher();
	void setPublisher(string& pub);
	string getPublisher();

	void inputPrice();
	void setPrice(float price);
	float getPrice();

	void inputStock();
	void setStock(int stck);
	int getStock();

	friend ostream& operator << (ostream& out, const Book& obj)
	{
		out << obj.author << "\n" << obj.title << "\n" << obj.publisher << "\n"
			<< obj.price << "\n" << obj.stock << "\n" << endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Book& obj)
	{
		in >> obj.author;
		in >> obj.title;
		in >> obj.publisher;
		in >> obj.price;
		in >> obj.stock;

		return in;
	}


	//void addBook();

	



};

