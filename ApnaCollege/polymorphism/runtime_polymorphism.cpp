#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() { cout << "Animal sound\n"; } // virtual function IS NECESSARY
    void move() { cout << "Animal moves\n"; }              // OTHERWISE IT WILL NOT WORK
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    void makeSound() { cout << "Dog barks\n"; }
    void move() { cout << "Dog runs\n"; }
};

class Cat : public Animal
{
public:
    void makeSound() { cout << "Cat meows\n"; }
    void move() { cout << "Cat jumps\n"; }
};

class Bird : public Animal
{
public:
    void makeSound() { cout << "Bird chirps\n"; }
    void move() { cout << "Bird flies\n"; }
};

int main()
{
    Animal *animals[] = {new Dog(), new Cat(), new Bird()}; // parent class pointer
    for (Animal *a : animals)
    {
        a->makeSound();
        a->move();
        delete a;
    }
    return 0;
}

// Dog barks
// Animal moves
// Cat meows
// Animal moves
// Bird chirps
// Animal moves