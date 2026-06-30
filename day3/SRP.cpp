

// Single Responsibility Principle
// Taking the example of kirana store =>
// in which customer buy product and generate the invoice and
// after that the list of products counts update

// In bad design this all functionalities happen in same class

#include <iostream>
#include <string>
#include <vector>

struct Item
{
    std::string name;
    int quantity;
    int price;
};

namespace Bad_design
{

    class KiranaStore
    {
    public:
        void productsList(std::vector<Item> &store)
        {
            std::vector<std::string> list;
            for (auto item : store)
            {
                list.push_back(item.name);
            }
            std::cout << "The available Items list are" << std::endl;
            for (auto item : list)
            {
                std::cout << item << std::endl;
            }
            return;
        }

        void Buy(std::string name, int quantity, std::vector<Item> &store)
        {
            for (auto &item : store)
            {
                if (item.name == name && item.quantity > quantity)
                {
                    item.quantity -= quantity;
                    std::cout << "Item purchase successfully" << std::endl;
                    return;
                }
            }

            std::cout << "Item not available" << std::endl;
        }

        void generateInvoice(std::string name, int quantity)
        {
            std::cout
                << "Customer purchased "
                << quantity
                << " units of "
                << name
                << std::endl;
        }
    };
};

namespace good_design
{

    class ProductCatalog
    {
    public:
        explicit ProductCatalog(std::vector<Item> items)
            : items_(std::move(items))
        {
        }

        void listProducts() const
        {
            std::cout << "Available items in the store:" << std::endl;
            for (const auto &item : items_)
            {
                std::cout << item.name << " (" << item.quantity << " available)" << std::endl;
            }
        }

        const Item *findItem(const std::string &name) const
        {
            for (const auto &item : items_)
            {
                if (item.name == name)
                {
                    return &item;
                }
            }
            return nullptr;
        }

        bool reduceStock(const std::string &name, int quantity)
        {
            for (auto &item : items_)
            {
                if (item.name == name && item.quantity >= quantity)
                {
                    item.quantity -= quantity;
                    return true;
                }
            }
            return false;
        }

    private:
        std::vector<Item> items_;
    };

    class InvoiceGenerator
    {
    public:
        void generateInvoice(const std::string &name, int quantity, int unitPrice) const
        {
            std::cout << "Customer purchased "
                      << quantity
                      << " units of "
                      << name
                      << " for a total of "
                      << unitPrice * quantity
                      << std::endl;
        }
    };

    class SalesService
    {
    public:
        SalesService(ProductCatalog &catalog, InvoiceGenerator &invoiceGenerator)
            : catalog_(catalog), invoiceGenerator_(invoiceGenerator)
        {
        }

        void purchaseProduct(const std::string &name, int quantity)
        {
            const Item *item = catalog_.findItem(name);
            if (item == nullptr)
            {
                std::cout << "Item not available" << std::endl;
                return;
            }

            if (!catalog_.reduceStock(name, quantity))
            {
                std::cout << "Insufficient quantity available" << std::endl;
                return;
            }

            invoiceGenerator_.generateInvoice(name, quantity, item->price);
        }

    private:
        ProductCatalog &catalog_;
        InvoiceGenerator &invoiceGenerator_;
    };
}

int main()
{
    good_design::ProductCatalog catalog({{"tomato", 35, 200},
                                         {"beans", 60, 100},
                                         {"aalo", 20, 50},
                                         {"chicken", 30, 320}});

    good_design::InvoiceGenerator invoiceGenerator;
    good_design::SalesService sales(catalog, invoiceGenerator);

    catalog.listProducts();
    sales.purchaseProduct("tomato", 5);
    catalog.listProducts();
    return 0;
}