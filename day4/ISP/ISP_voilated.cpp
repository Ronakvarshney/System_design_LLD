#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw logic_error("Volume not applicable for square");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}
    double area() override
    {
        return 6 * side * side;
    }

    double volume() override
    {
        return side * side * side;
    }

};

int main()
{
    Shape *sq = new Square(5.0);
    cout << sq->area() << endl;
    cout << sq->volume() << endl;
    Shape *vl = new Cube(5.0);
    cout << vl->area() << endl;
    cout << vl->volume() << endl;
    return 0;
}