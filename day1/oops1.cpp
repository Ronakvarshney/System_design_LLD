// evolution of language
// Machine language(0-1) -> assembly language(mov r 2+3) -> procedural programming(functions , loop) -> object oriented prog
// (real world modeling), give context of real world things and also includes data security and oops is highly scalable and
// resuable
// Pillars of OOPS -> Abstraction , Encapsulation , Inheritance , Polymorphism
// Abstraction hides the uncessaries details or inner working from user and showcase only what is necessary.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// abstraction
class car
{
public:
    virtual void accerlate() = 0;
    virtual void brake() = 0;
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
};

class sportcar : public car
{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentspeed;

    sportcar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentspeed = 0;
    }

    void startEngine()
    {
        cout << model << brand << "start engine";
        this->isEngineOn = true;
    }

    void accerlate()
    {
        cout << "accerlate has been increased and current speed is" << currentspeed;
    }

    void brake()
    {
        cout << "brake has been applied and its speed now becomes 0";
        this->currentspeed = 0;
    }

    void stopEngine()
    {
        cout << "Engine will be stoped";
        this->currentspeed = 0;
        this->isEngineOn = false;
    }
};

// encapsulation

class Bank
{
private:
    unordered_map<int, int> mp;
    //    account_number , balance

public:
    int account_number;

    void create_account(int acc_no)
    {
        if (mp.find(acc_no) != mp.end())
        {
            cout << "The account number already exists" << endl;
            return;
        }
        mp[acc_no] = 0;
        cout << "The account number has been created successfully" << endl;
    }

    void deposit(int acc_no, int amount)
    {
        if (amount < 0 || mp.find(acc_no) == mp.end())
        {
            cout << "The account number not exists, in which you want to deposit money." << endl;
            return;
        }
        if (amount > 0)
        {
            mp[acc_no] += amount;
            cout << "The updated amount is" << mp[acc_no] << endl;
        }
    }

    void withdraw(int acc_no, int amount)
    {
        if (amount < 0 || mp.find(acc_no) == mp.end())
        {
            cout << "The account number not exists, in which you want to deposit money." << endl;
            return;
        }
        if (amount < mp[acc_no])
        {
            mp[acc_no] -= amount;
            cout << "The updated amount is" << mp[acc_no] << endl;
        }
        else
        {
            cout << "The withdraw amount is greater than account balance" << endl;
        }
    }

    int get_balance(int acc_no)
    {
        return this->mp[acc_no];
    }
};

// inheritance

class Animal
{
public:
    virtual void eat(string name)
    {
        cout << "The animal " << name << " eats the food" << endl;
    }
};

class Dog : public Animal
{
public:
    void eat(string name) override
    {
        cout << "Dog " << name << " eats the food" << endl;
    }
};




int main()
{

    // car *mycar = new sportcar("bmw", "s12");
    // mycar->startEngine();

    // mycar->accerlate();
    // mycar->brake();
    // mycar->stopEngine();

    // Bank *acc = new Bank();
    // acc->create_account(202);
    // acc->get_balance(202);
    // acc->deposit(202, 2000);
    // acc->get_balance(202);
    // acc->withdraw(202, 3000);

    Dog *d1 = new Dog();
    d1->eat("roadwheelar");

    return 0;
}