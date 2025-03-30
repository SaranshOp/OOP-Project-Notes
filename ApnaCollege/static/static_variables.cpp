#include <iostream>
using namespace std;

// Example of static variable in a function
void fun()
{
    static int count = 0; // Static variable retains its value between function calls
    count++;
    cout << "fun() called " << count << " times" << endl;
}

// Example of static variable in a class
class FunClass
{
public:
    static int staticVar; // Static variable shared by all objects of the class

    void incrementStaticVar()
    {
        staticVar++;
    }

    void displayStaticVar()
    {
        cout << "Static variable in FunClass: " << staticVar << endl;
    }
};

// Definition of static variable outside the class
int FunClass::staticVar = 0;

int main()
{
    // Static variable in a function
    fun();
    fun();
    fun();

    // Static variable in a class
    FunClass obj1, obj2;
    obj1.incrementStaticVar();
    obj2.incrementStaticVar();
    obj1.displayStaticVar(); // Displays the same value for both objects
    obj2.incrementStaticVar();
    obj2.displayStaticVar();

    return 0;
}