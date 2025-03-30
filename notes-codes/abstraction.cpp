#include <iostream>
#include <string>
using namespace std;

// one way to make class abstract is by adding 'abstract' keyword before
// Abstract class is created by having at least one pure virtual function

class Shape
{
public:
    virtual void draw() = 0; // Pure virtual function -  virtual and zero - this makes the class automatically abstract
    virtual ~Shape() {}      // Virtual destructor
};

class Circle : public Shape // contract
{
public:
    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Rectangle" << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Triangle" << endl;
    }
};

int main()
{
    // Shape S1; // Object of abstract class type "Shape" is not allowed
    Shape *shapes[] = {new Circle(), new Rectangle(), new Triangle()};

    for (Shape *shape : shapes)
    {
        shape->draw();
        delete shape;
    }

    return 0;
}