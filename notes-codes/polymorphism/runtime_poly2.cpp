#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}

    virtual void work() { // Virtual function for runtime polymorphism
        cout << "Employee " << name << " (ID: " << id << ") is working." << endl;
    }

    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

// Derived class: Developer
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(const string& name, int id, const string& programmingLanguage)
        : Employee(name, id), programmingLanguage(programmingLanguage) {}

    void work() override { // Function overriding
        cout << "Developer " << name << " (ID: " << id << ") is writing code in " 
             << programmingLanguage << "." << endl;
    }
};

// Derived class: Teacher
class Teacher : public Employee {
private:
    string subject;

public:
    Teacher(const string& name, int id, const string& subject)
        : Employee(name, id), subject(subject) {}

    void work() override { // Function overriding
        cout << "Teacher " << name << " (ID: " << id << ") is teaching " 
             << subject << "." << endl;
    }
};

int main() {
    Employee* emp1 = new Developer("Alice", 101, "C++"); // Base class pointer to derived class object
    Employee* emp2 = new Teacher("Bob", 102, "Mathematics"); // Base class pointer to another derived class object

    emp1->work(); // Calls Developer's work method
    emp2->work(); // Calls Teacher's work method

    // Clean up
    delete emp1;
    delete emp2;

    return 0;
}