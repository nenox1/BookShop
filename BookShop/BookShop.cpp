#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Book.h"

using namespace std;

void insertBooks() {
    vector<Book> mainVec;

    Book book("The Iliad", "Homer", "Americana", 35.26, 25);
    Book book1("The Odissey", "Homer", "Toronto", 31.51, 38);
    Book book2("The Prometheus", "Aeschylus", "Americana", 28.76, 325);
    Book book3("Almagest", "Ptolemy", "Americana cd", 53.25, 4);
    Book book4("Guide for the perplexed", "Maimonides, Moses", "Americana", 71.01, 5);

    mainVec.push_back(book);
    mainVec.push_back(book1);
    mainVec.push_back(book2);
    mainVec.push_back(book3);
    mainVec.push_back(book4);

    ofstream outFile;
    outFile.open("text.txt");

    for (int i = 0; i < mainVec.size(); i++) {
        outFile << mainVec[i].getAuthor() << "\n";
        outFile << mainVec[i].getTitle() << "\n";
        outFile << mainVec[i].getPublisher() << "\n";
        outFile << mainVec[i].getPrice() << "\n";
        outFile << mainVec[i].getStock() << "\n";
    }
    outFile.close();
}

void outpootBooks() {
    vector<Book> mainVec;
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
                book.setAuthor(tp);
                break;
            case 2:
                book.setTitle(tp);
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

    for (int i = 0; i < mainVec.size(); i++) {
        cout << mainVec[i].getAuthor() << "\n";
        cout << mainVec[i].getTitle() << "\n";
        cout << mainVec[i].getPublisher() << "\n";
        cout << mainVec[i].getPrice() << "\n";
        cout << mainVec[i].getStock() << "\n";
    }
}

int main()
{ 
    //insertBooks();
    outpootBooks();
   
    return 0;
}
