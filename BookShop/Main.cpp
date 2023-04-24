#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Book.h"
#include"BookShop.h"

using namespace std;

//prints the main Menu with choices for Book shop
int mainMenuPrint() {
    int choice;

    //print out choices
    cout << "\n\n\t\tMENU"
        << "\n1. Entry of New Book"
        << "\n2. Buy Book"
        << "\n3. Search For Book"
        << "\n4. Edit Details Of Book"
        << "\n5. Print all Books"
        << "\n6. Exit"
        << "\n\nEnter your Choice: ";
    cin >> choice;

    //checks if choices are in limits of menu
    while (!cin || choice > 6 || choice < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input please enter a valid input:";
        cin >> choice;
    }
      
    //clear the input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

int main()
{
    BookShop shop;
  
    int choice = 0;
    int find = -1;

    do {      
         choice = mainMenuPrint();
           switch (choice) {
            case 1:
                shop.addNewBook();
                break;
            case 2:
                shop.buyBook();
                break;
            case 3:
                find = shop.findBook();
                if (find != -1)
                {
                    shop.printFoundMember(find);
                    system("pause");
                }
                else {
                    cout << "Book not found." << endl;
                    system("pause");
                }
                break;
            case 4:
                shop.editData();
                break;
            case 5:
                cout << "Printam sve knjige!!!" << endl;
                system("pause");                
                break;
            case 6:
                cout << "Exiting...";                
                break;
            default:
                cout << "Unknown choice, please select offered numbers.";
                break;
            }

            system("CLS");
        } while (choice != 6);
          
        //shop.printFoundMember(5);


    return 0;
}
