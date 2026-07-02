#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
    int price;
    string name;

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
            total += it->price;
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

// Abstract class
class Persistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0; // Pure virtual function
};

class SQLPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("Laptop", 50000));
    cart->addProducts(new Product("Mouse", 2000));

    cart->getProducts();
    GenerateInvoice *invoice = new GenerateInvoice(cart);
    invoice->printInvoice();

    Persistence *db = new SQLPersistence();
    Persistence *mongo = new MongoPersistence();
    Persistence *file = new FilePersistence();

    db->save(cart);    // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;
}
