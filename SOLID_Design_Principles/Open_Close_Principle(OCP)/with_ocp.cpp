// In the file without_ocp we see how OCP is violating in ShoppinCartSaver Class
// Now we see how to achieve OCP principle (Abstraction , Polymorphism, Inheritance)

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

// 2. ShoppingCart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // create getter and setter method to get and set productes

    void addProducts(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> &getProducts()
    {
        return products;
    }

    // Method to calculate total price;
    double calculateTotalPrice()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

// 3. ShoppingCartPrinter
class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInovices()
    {
        cout << "Printing Invoice...." << endl;
        for (auto c : cart->getProducts())
        {
            cout << c->name << " : " << c->price << endl;
        }
        cout << "Total Price : " << cart->calculateTotalPrice() << endl;
    }
};

// Abstract class the only behave as a interface for save cart to diffence places;
class DBPersistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save() = 0; // Pure vitual method;
};

class saveToSQLDB : public DBPersistence
{
public:
    void save()
    {
        cout << "Shopping cart save to SQL...." << endl;
    }
};
class saveToMongoDB : public DBPersistence
{
public:
    void save()
    {
        cout << "Shopping cart save to MongoDB...." << endl;
    }
};
class saveToFile : public DBPersistence
{
public:
    void save()
    {
        cout << "Shopping cart save to file...." << endl;
    }
};
int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("Bike", 120384));
    cart->addProducts(new Product("Facewash", 130));
    cart->addProducts(new Product("Shoes", 1600));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInovices();

    DBPersistence *file = new saveToFile();
    DBPersistence *mongo = new saveToMongoDB();
    DBPersistence *sql = new saveToSQLDB();

    file->save();
    mongo->save();
    sql->save();
}