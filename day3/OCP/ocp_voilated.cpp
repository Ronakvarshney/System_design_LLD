#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    int price;

    Product(string name, int price)
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
    };

    const vector<Product *> getProducts()
    {
        return products;
    }

    double calculateTotal()
    {
        double total = 0;
        for (auto it : products)
        {
            total += it.price;
        }
        return total;
    }
};

class GenerateInvoice
{
private:
    ShoppingCart *cart;

public:
    GenerateInvoice(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

class SavetoDB
{
private:
    ShoppingCart *cart;

public:
    void saveToSQLDatabase()
    {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase()
    {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile()
    {
        cout << "Saving shopping cart to File..." << endl;
    }
};



