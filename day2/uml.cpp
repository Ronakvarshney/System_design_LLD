#include <iostream>
#include <string>

using namespace std;


// composition 
class Room
{
public:
    void construct()
    {
        cout << "Room has been constructed" << endl;
    }

    ~Room(){
        cout<< "Room has been destroyed" << endl;
    }
};

class House
{
public:
    Room *r;
    House()
    {
        r = new Room();
    }

    ~House(){
        delete r;
        cout << "House has been destroyed" << endl;
    }

    void house()
    {
        cout << "house has been maked" << endl;
    }
};






int main()
{
    House *h = new House();
    h->house();
    h->r->construct();
    delete h ;
    return 0;                    
}



