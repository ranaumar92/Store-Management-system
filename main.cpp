
#include <iostream>
#include <string>
#include <fstream>
#include "queue.h"
#include "linklist.h"
#include "admin.h"
#include "customer.h"
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// to handle colors 

void displayMenu() //menu of the system
{
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\n\n\n\n\n\n\n\n\n"
        << "\t+----------------------------------------------------------+\n"
        << "\t|\t      WELCOME TO STORE MANAGEMENT SYSTEM           |\n"
        << "\t|                                                          |\n"
        << "\t+----------------------------------------------------------+\n"
        << "\t| 1. Admin Menu                                            |\n"
        << "\t| 2. Customer Menu                                         |\n"
        << "\t| 0. Quit                                                  |\n"
        << "\t+----------------------------------------------------------+\n"
        << "\t|     Enter Your Choice:                                   |\n"
        << "\t+----------------------------------------------------------+\n\n";

}
int main()
{


    time_t Time; // declare a time object
    time(&Time); // Get the current time
    //using this because we have to check if the product is expired or not 

    struct tm* time;
    time = localtime(&Time);

    currentDay = time->tm_mday; // specific variable for the current date
    currentMonth = time->tm_mon + 1;
    currentYear = time->tm_year + 1900;

    admin admin1;
    customer customer1("NULL");
    DoublyList<product> list_of_Products;
    int choice;
    while (1)
    {

        displayMenu();

        cin >> choice;
        if (choice == 1)
        {
            admin1.adminModule(list_of_Products);
        }
        else if (choice == 2)
        {
            if (!list_of_Products.isEmpty())
                customer1.customerModule(list_of_Products);
            else {
                cout << "\n\t\t\x1b[1;31mNo items currently \x1b[0m\n";
                break;
            }

        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "\x1b[1;31mWRONG INPUT!!!\x1b[0m\n";
        }
    }
}