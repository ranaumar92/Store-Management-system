#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma
#include <string>
#include "linklist.h"
#include "product.h"
#include <fstream>
#include <iostream>
#include "queue.h"
using namespace std;

class complaint  //complaint management 
{
    int no;
    string comp;
    ofstream compFile;
    ifstream icompFile;
    queue<product>cart;

public:
    complaint()
    {
        no = -1;
        comp = "\0";
        compFile.open("complaint.txt");//file that will contain complains

        compFile.close();
    }
    void generateComplaint(string c)
    {
        comp = c;
        ++no;
        compFile.open("complaint.txt");
        compFile << "COMPLAINT NO: " << no << endl
            << "Complaint: " << comp << endl;
        compFile.close();
    }
};

class returnProduct // return management 
{
    int no;
    string retReq;
    ofstream returnFile;
    ifstream ireturnile;

public:
    returnProduct()
    {
        no = -1;
        retReq = "\0";
        returnFile.open("complaint.txt");
        returnFile.close();
    }
    void generateRequest(string c)
    {
        retReq = c;
        ++no;
        returnFile.open("returnFile.txt");
        returnFile << "request NO: " << no << endl
            << "request: " << retReq << endl;
        returnFile.close();
    }
};

class customer  // customer class that will manage customer 
{
    string customerName;
    ofstream ofHistory;
    ifstream history;
    DoublyList<product> favouritetProducts;
    returnProduct returnRe;
    queue<product> cart;

public:
    customer(string n)
    {
        customerName = n;
        ofHistory.open("history.txt", ios::out);

        if (!ofHistory.is_open())
            cout << "\x1b[1;31mhistory file is not open\x1b[0m\n";

        ofHistory << customerName;
        ofHistory.close();
    }
    double calculateBill() {//bill calculation 
        double bill = 0.0;
        product tmp;
        while (!cart.isEmpty())
        {
            cart.dequeue(tmp);
            bill = +tmp.getPrice();
        }
        return bill;
    }
    void customerMenu()//customer module menu 
    {
        cout << "\n\t\t\t    customer MENU";
        cout << "\n1.Buying History ";
        cout << "\n2.Fovourite Products ";
        cout << " \n3.Complaints";
        cout << " \n4.Return Request";
        cout << "\n5. Discount ";
        cout << "\n0.Quit" << endl;
    }
    void customerModule(DoublyList<product>& products)
    {
        string historyString;
        string complaintString;
        int choice;
        double bill = 0.0;
        product tmp;
        int subChoice;
        complaint com;
        bool innerflag = true;
        int indes;
        int selectFavourite;
        bool flag = true;
        int  selection;
        cout << "Press  to 1 buy products OR Press 0 to open portal: ";
        cin >> selection;
        if (selection == 1)
        {
            cout << "Add products to shopping cart: " << endl;;
            while (flag)
            {
                system("clear");
                products.displayProducts();
                cout << "\nEnter the product id: ";
                cin >> indes;
                tmp = products.returnNode(indes);
                cart.enqueue(tmp);
                int forBuyChoice;
                cout << "press 0 to exit: \n";
                cin >> forBuyChoice;
                if (forBuyChoice == 0)
                    flag = false;
            }
            cout << "Shoping cart: " << endl;
            cart.display();

            cout << "\n Bill: " << calculateBill();
            cout << "\x1b[1;32m     THANK YOU FOR SHOPPING HERE      .\x1b[0m\n";

            ofHistory.open("history.txt", ios::out);
            ofHistory << "Bill: " << bill << endl;
            ofHistory.close();
            exit(0);
        }
        else if (selection == 0)

        {
            while (flag == true)
            {
                customerMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    history.open("history.txt", ios::in);
                    if (history.is_open())
                    {
                        while (getline(history, historyString))
                        {
                            cout << historyString;
                        }
                    }
                    break;
                case 2:
                    while (innerflag == true)
                    {
                        cout << "Add products to your favourite list: ";
                        products.displayFavourite();

                        cin >> selectFavourite;

                        tmp = products.returnNode(selectFavourite);
                        products.insert(tmp);
                        cout << "1. Go back";
                        cout << "\npress any other key to keep inserting";

                        cin >> subChoice;
                        if (subChoice == 1)
                            innerflag = false;
                        break;
                    }
                case 3:
                    cout << "\x1b[1;31mRegister Complaint:\x1b[0m\n";
                    cin >> complaintString;
                    com.generateComplaint(complaintString);
                                       break;
                case 4:
                    cout << "request for return: ";
                    cin >> complaintString;
                    returnRe.generateRequest(complaintString);
                    break;
                }
            }
        }
        else
        {
            cout << "\x1b[1;31m.WRONG INPUT\nEXITING CUSTOMER MODULE \x1b[0m\n";

            exit(0);
        }
    }

};

#endif