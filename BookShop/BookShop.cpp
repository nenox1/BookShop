#include "BookShop.h"

void BookShop::Initialize()
{
    Book book;
    string tp;
    int brojac = 1;
    float pri = 0;
    int stck = 0;

    ifstream file("text.txt");

    if (file.is_open()) {
        while (file)
        {
            getline(file, tp);
            switch (brojac) {
            case 1:
                book.setTitle(tp);
                break;
            case 2:                
                book.setAuthor(tp);
                break;
            case 3:
                book.setPublisher(tp);
                break;
            case 4:
                pri = stof(tp);
                book.setPrice(pri);
                break;
            case 5:
                stck = stoi(tp);
                book.setStock(stck);
                break;
            default:
                break;
            }
            if (brojac != 5)
                brojac++;
            else {
                mainVec.push_back(book);
                brojac = 1;
            }
        }
    }

}

void BookShop::SaveToFile()
{
     ofstream outFile;
    outFile.open("text.txt");

    for (int i = 0; i < mainVec.size(); i++) {
        outFile << mainVec[i].getTitle() << "\n";
        outFile << mainVec[i].getAuthor() << "\n";       
        outFile << mainVec[i].getPublisher() << "\n";
        outFile << mainVec[i].getPrice() << "\n";
        outFile << mainVec[i].getStock() << "\n";
    }
    outFile.close();
}

void BookShop::PrintAllMembers()
{    
    for (int i = 0; i < mainVec.size(); i++) {       
        cout << mainVec[i].getTitle() << "\n";
        cout << mainVec[i].getAuthor() << "\n";
        cout << mainVec[i].getPublisher() << "\n";
        cout << mainVec[i].getPrice() << "\n";
        cout << mainVec[i].getStock() << "\n";
    }
  

}

void BookShop::printFoundMember(int mem)
{
    if(mem <= mainVec.size() && mem > -1){
    cout << mainVec[mem].getTitle() << "\n";
    cout << mainVec[mem].getAuthor() << "\n";
    cout << mainVec[mem].getPublisher() << "\n";
    cout << mainVec[mem].getPrice() << "\n";
    cout << mainVec[mem].getStock() << "\n";
    }
    else
    {
        cout << "Unknown member!" << endl;
    }
}

void BookShop::addNewBook()
{
    cout << "Enter Title: ";
    book.inputTitle();
    cout << "Enter Author: ";
    book.inputAuthor();
    cout << "Enter Publisher: ";
    book.inputPublisher();
    cout << "Enter price: ";
    book.inputPrice();
    cout << "Enter stock: ";
    book.inputStock();
   
    mainVec.push_back(book);
}

void BookShop::buyBook()
{
    int pos = findBook();
    int noOfBooks = 0;

    if (pos != -1)
    {
        printFoundMember(pos);
        cout << "How many books do you want to buy: ";
        cin >> noOfBooks;

        while (!cin || noOfBooks < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please enter a valid input:";
            cin >> noOfBooks;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (noOfBooks > mainVec[pos].getStock()) {
            char input =' ';
            cout << "Required Copies not in Stock, new input: Y/N? \n";
            cin >> input;
            if (input == 'Y' || input == 'y') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "How many books do you want to buy: ";
                cin >> noOfBooks;

                while (!cin || noOfBooks < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input please enter a valid input:";
                    cin >> noOfBooks;
                }
                cout << "\nBooks Bought Sucessfully\n";
                cout << "Price of purchased books is: " << noOfBooks * mainVec[pos].getPrice() << endl;
                mainVec[pos].setStock(mainVec[pos].getStock() - noOfBooks);
                cout << "New data:";
                printFoundMember(pos);

            }
            else
            {
                cout << "Book purchase unsuccessful!\n";
                
            }

        }
        else
        {
            cout << "\nBooks Bought Sucessfully\n";
            cout << "Price of purchased books is: " << noOfBooks * mainVec[pos].getPrice() << endl;
            mainVec[pos].setStock(mainVec[pos].getStock() - noOfBooks);
            cout << "New data:";
            printFoundMember(pos);           
        }
        system("pause");
    }
    else {
        cout << "Book not found." << endl;
        system("pause");
    }
}

int BookShop::findBook()
{    
    string title;
    string author;
    int pos = -1;

    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);    

    for (int  i = 0; i < mainVec.size(); i++)
    {        
       if (mainVec[i].getTitle() == title  && mainVec[i].getAuthor() == author) {           
           //printFoundMember(i);
           pos = i;
            break;           
        }
        else
        {           
           pos = -1;
       }

    }

    return pos;
}

void BookShop::editData()
{
    int pos = findBook();
    string newTitle = "";
    string newAuthor = "";
    string newPublisher = "";
    float newPrice = 0;
    int newStock = 0;

    if (pos != -1)
    {
        printFoundMember(pos);
        
        cout << "Input new title, press enter to keep old title: ";
        if (!getline(cin, newTitle).width() == 0) {
            mainVec[pos].inputTitle();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Input new author, press enter to keep old author: ";
        if (!getline(cin, newAuthor).width() == 0) {
            mainVec[pos].inputAuthor();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }  

        cout << "Input new publisher, press enter to keep old publisher: ";
        if (!getline(cin, newPublisher).width() == 0) {
            mainVec[pos].inputPublisher();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Input new price, press enter to keep old price: ";
        if (cin.peek() != '\n') {
            mainVec[pos].inputPrice();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Input new stock, press enter to keep old stock: ";
        if (cin.peek() != '\n') {
            mainVec[pos].inputStock();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      
        system("pause");
    }
    else {
        cout << "Book not found." << endl;
        system("pause");
    }

}
