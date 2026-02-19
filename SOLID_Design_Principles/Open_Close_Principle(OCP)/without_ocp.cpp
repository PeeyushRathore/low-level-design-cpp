#include <bits/stdc++.h>
using namespace std;

// 1. Product class representing any item in e-commerce.
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

// 2. ShoppingCart : Only responsible for cart related business logic
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProducts(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> &getProducts()
    {
        return products;
    }
    double calculateTotalPrice()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        // cout << "Total Price : " << total << endl;
        return total;
    }
};

// 3. ShoppingCartPrinter : Only responsible for printing invoices.
class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {
        cout << "Printing Invoice" << endl;
        for (auto c : cart->getProducts())
        {
            cout << c->name << " :" << c->price << endl;
        }
        cout << cart->calculateTotalPrice()<< endl;
    }
};

// ShoppingCartSaver : Only responsible for saving the cart to DB.
class ShoppingCartSaver
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartSaver(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    // Problem -------->>>> if we want to to modify the class we can do it within the same class as it violate OCP
    // Example --------->>>> we want to save cart in mongoDB and file also what we do usually without following OCP :

    // Method used to save the invoice to sql DB.
    void saveToSQLDb()
    {
        cout << "Saved to DB" << endl;
    }

    // We create another method by modifying the existing class
    void saveToMongoDB()
    {
        cout << " Saved to mongoDB" << endl;
    }

    void saveToFile()
    {
        cout << "Saved to file" << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("Laptop", 10000));
    cart->addProducts(new Product("Toy", 120.88));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartSaver *saver = new ShoppingCartSaver(cart);
    saver->saveToSQLDb();
    saver->saveToFile();
    saver->saveToMongoDB();
}