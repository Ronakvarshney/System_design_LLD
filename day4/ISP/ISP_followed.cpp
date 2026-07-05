#include<iostream>
#include<string>


using namespace std;


class shape_2d {
    public:
    virtual double area() = 0 ;
};

class shape_3d {
    public:
    virtual double area() = 0 ;
    virtual double volume()  =0 ;
};



class Square : public shape_2d{
    private:
    double side ;
    public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side ;
    }
};



class Cube : public shape_3d {
    private :
    double side ;
    public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6*side* side ;
    }

    double volume() override {
        return side * side * side ;
    }
};



int main(){
    shape_2d * sq = new Square(5);
    sq->area();

    shape_3d * cub  = new Cube(5);
    cub->area();
    cub->volume();
    
    return 0 ;
}