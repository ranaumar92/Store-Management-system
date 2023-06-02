#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include "linklist.h"

using namespace std;
int currentDay;
int currentMonth;
int currentYear;


class expiryDate   //expiry management 
{
public:
    int day;
    int month;
    int year;

    friend ostream& operator<<(ostream& os, const expiryDate& e); //operator overloading , it will display the product details 
                                                                  //from the product class and the expiry date also from the expiry class

    expiryDate()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    void insert()
    {
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
    }

    void display()
    {
        cout << day << "-" << month << "-" << year << endl;
    }
};
ostream& operator<<(ostream& os, const expiryDate& e)
{
    os << "\nday: " << e.day << "month: " << e.month << "year: " << e.year;
    return os;
}

class product//product class it will deal with the product management 
{
    string prodName;
    int prod_id;
    expiryDate exp;
    double price;
    int quantity;
    friend ostream& operator<<(ostream& os, const product& p);
    int salePercent;

public:
    product()
    {
        prodName = "\0";
        prod_id = -1;
        this->exp = expiryDate();
        price = 0.0;
        quantity = 0;
        salePercent = 0;
    }

    double getPrice() {
        return price;
    }
    product(string n, int i, expiryDate exp, double p, int quantity)
    {
        prodName = n;
        prod_id = i;
        this->exp = exp;
        price = p;
        quantity = quantity;
    }

    expiryDate getExpiry() {
        return exp;
    }

    void addProduct()// add product to the store
    {

        cout << "Product Name: ";
        cin >> prodName;
        cout << "product ID: ";
        cin >> prod_id;
        cout << "expiryDate: ";
        exp.insert();
        this->exp = exp;
        cout << "price: ";
        cin >> price;
        cout << "Quantity : ";
        cin >> quantity;
    }

    void applySale(int sale)//this will apply sale 
    {
        if (sale > 0)
            price = (price * sale) / 100;
        cout << sale << "\x1b[1;32m% sale applied.\x1b[0m\n" << endl;
    }

    bool checkExpiryDate(expiryDate exp)// this will compare current date and expiry date 
    {
        if (exp.year < currentYear)
        {
            return true;
        }
        else if (exp.year == currentYear)
        {
            if (exp.month < currentMonth)
            {
                return true;
            }
            else if (exp.month == currentMonth)
            {
                if (currentDay > exp.day) {
                    return true;
                    cout << "\x1b[1;32mProduct is expired\x1b[0m\n";

                }
            }
        }
        cout << "\x1b[1;31mProduct is not  expired \x1b[0m\n";
        return false;
    }
};

ostream& operator<<(ostream& os, const product& p)      // operator overloading 
{
    os << "product Name: ";
    os << p.prodName;
    os << "\nproduct id: ";
    os << p.prod_id;
    os << "\nprice: ";
    os << p.price;
    os << "\nexpiry date: ";
    os << p.exp;
    os << "\n quantity:";
    os << p.quantity << endl;
    return os;
}

#endif // !PRODUCT_H