#ifndef ADMIN_H
#define ADMIN_H
#pragma
#include <string>
#include <fstream>
#include "customer.h"
#include "linklist.h"
#include "product.h"
using namespace std;




class admin// class that will manage admin 
{
    string adminName;
    int admin_id;
    ifstream history;

public:
    admin()
    {
        adminName = "\0";
        admin_id = -1;
    }
    void adminMenu()//admin menu
    {
        cout << "\n\n\t\t\t    Admin MENU";
        cout << "\n1. Add new product";
        cout << "\n2. Display stock";
        cout << "\n3. Modify existing product";
        cout << "\n4. Remove an item";
        cout << "\n5. Customers list ";
        cout << "\n6. Dequeue customer";
        cout << "\n7. Product Expiry Date Checker Function";
        cout << "\n8. sale ";
        cout << "\n0. Quit" << endl;
    }
    void adminModule(DoublyList<product>& products)
    {

        int choice;
        product p;
        string tmp;
        bool flag = true;
        while (flag)
        {
            system("clear");
            adminMenu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                p.addProduct();
                products.insert(p);
                break;
            case 2:
                products.displayProducts();
                char l;
                cin >> l;
                break;
            case 3:
                int i;
                cin >> i;
                p.addProduct();
                cout << "Prod id: ";
                products.updateProduct(p, i);
                break;
            case 4:
                cout << "Prod id: ";
                cin >> i;
                products.specificDeletion(i);
                break;
            case 5:
                history.open("history.txt", ios::in);
                while (getline(history, tmp))
                {
                    cout << tmp << "\n";
                }
            case 6:
                cout << "NO customers to show " << endl;
            case 7:
                cout << "give product id: ";
                cin >> i;
                p = products.returnNode(i);
                if (p.checkExpiryDate(p.getExpiry()))
                    cout << "\nProduct is expired";
                else
                    cout << "\nProduct is not expired";
                cout << "\n\tPress any key to go back!!";
                cin >> l;
                break;
            case 8:
                int sale;
                cout << "Enter the percentage of sale " << endl;
                cin >> sale;
                p.applySale(sale);
            case 0:
                flag = false;
                break;
            }
        }
    }
};

#endif // !ADMIN_H