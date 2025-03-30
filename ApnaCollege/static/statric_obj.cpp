#include <iostream>
using namespace std;

class ABC
{
private:
    int value;
    static int count; // Static member to count objects

public:
    // Constructor
    ABC(int v) : value(v)
    {
        count++;
        cout << "Constructor called for object with value: " << value << endl;
    }

    // Destructor
    ~ABC()
    {
        cout << "Destructor called for object with value: " << value << endl;
        count--;
    }

    // Static member function to get count
    static int getCount()
    {
        return count;
    }

    // Member function to display value
    void display() const
    {
        cout << "Value: " << value << endl;
    }
};

// Initialize static member
int ABC::count = 0;

int main()
{
    cout << "Initial object count: " << ABC::getCount() << endl;

    // Static objects
    static ABC obj1(10);

    if (true)
    {
        static ABC obj2(20); // Static object inside a block
        ABC obj3(30);        // Non-static object inside a block
    }

    cout << "Object count after creating static objects: " << ABC::getCount() << endl;

    obj1.display();
    // obj2.display(); // Error: obj2 is not accessible here but it still persists in memory.

    return 0;
}