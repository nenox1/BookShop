#include "Book.h"



Book::Book(string aut, string tit, string pub, float pri, int sto)
{
	author = aut;
	title = tit;
	publisher = pub;
	price = pri;
	stock = sto;
	
}


Book::~Book()
{	
}

void Book::inputAuthor()
{	
	getline(cin, author);

}
void Book::setAuthor(string &aut)
{
	author = aut;
}

string Book::getAuthor()
{
	return author;
}

void Book::inputTitle()
{
	//cout << "Enter book title:";
	getline(cin, title);

}
void Book::setTitle(string &tit)
{
	title = tit;

}

string Book::getTitle()
{
	return title;
}

void Book::inputPublisher()
{
	getline(cin, publisher);
}

void Book::setPublisher(string& pub)
{
	publisher = pub;
}

string Book::getPublisher()
{
	return publisher;
}

void Book::inputPrice()
{
	float pri;
	cin >> pri;
	
	if (cin) {
		price = pri;
	}
	else
	{		
		while (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');			
			cout << "Invalid price input please enter a number:";
			cin >> pri;		
		}
		price = pri;
	}

}

void Book::setPrice(float pri)
{
	price = pri;


}
float Book::getPrice()
{
	return price;
}

void Book::inputStock()
{
	int stck;
	cin >> stck;

	if (cin) {
		stock = stck;
	}
	else
	{
		while (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid stock input please enter a number:";
			cin >> stck;
		}
		stock = stck;
	}
}

void Book::setStock(int stck)
{
	stock = stck;
}

int Book::getStock()
{
	return stock;
}
/*
void Book::addBook()
{
	
	
}
*/

