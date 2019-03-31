#include <cmath>
#include <string>
#include <iostream>

class Rectangle : Figure{
    double a, b;
public:
    Rectangle() : a(0), b(0){}
    double get_square() const {
        return a * b;
    }
    static Rectangle *make(std::string const & str){
        Rectangle *temp = new Rectangle;
        size_t next = 0;
        temp->a = stod(str, &next);
        temp->b = stod(str.substr(next));
        return temp;
    }

};
class Square : Figure {
    double a;
public:
    Square() : a(0){}
    double get_square() const {
        return a * a;
    }
    static Square *make(std::string const & str){
        Square *temp = new Square;
        size_t next = 0;
        temp->a = stod(str, &next);
        return temp;
    }
};

class Circle : Figure {
    double r;
public:
    Circle() : r(0){}
    double get_square() const {
        return M_PI * r * r;
    }
    static Circle *make(std::string const & str){
        Circle *temp = new Circle;
        size_t next = 0;
        temp->r = stod(str, &next);
        return temp;
    }
};
