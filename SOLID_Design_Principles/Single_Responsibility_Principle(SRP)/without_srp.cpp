#include <bits/stdc++.h>
using namespace std;

// Product class representing any product of the e-commerce
class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// Violating SRP : Handling multiple responsibilites in a single class;
// this award goes to you ye kya m bnata hun uska muh
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    // 1. Calculate Total price in cart
    double calculateTotalPrice()
    {
        double total = 0;
        for (auto p : products)
        {
            total = total + p->price;
        }
        return total;
    }

    // 2. Prints invoice : ->> Violating the SRP Principle
    void printInvoice()
    {
        cout << "Shoppint cart Invoice\n";
        for (auto p : products)
        {
            cout << p->price << " " << p->name << endl;
        }
        cout << "Total : " << calculateTotalPrice() << endl;
    }

    // 3. Saves to DB; --->> Violationg the SRP Principle
    void saveToDB()
    {
        cout << "Saving shopping cart to DB" << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Book", 78.67));

    cart->printInvoice();
    cart->saveToDB();
    cout << cart->calculateTotalPrice();

    return 0;
}