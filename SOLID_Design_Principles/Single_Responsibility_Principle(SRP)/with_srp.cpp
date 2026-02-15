#include <bits/stdc++.h>
using namespace std;

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
        cout << cart->calculateTotalPrice();
    }
};
class ShoppingCartSaver
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartSaver(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void saveToDb()
    {
        cout << "Saved to DB";
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
    saver->saveToDb();
}