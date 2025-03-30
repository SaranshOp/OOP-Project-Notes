#include <iostream>
#include <string>
using namespace std;

// Compile-time Polymorphism
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &name, int id) : name(name), id(id) {}

    void work() { cout << name << " is working on general tasks." << endl; }
    void work(int hours) { cout << name << " is working for " << hours << " hours." << endl; }
};

class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(const string &name, int id, const string &programmingLanguage)
        : Employee(name, id), programmingLanguage(programmingLanguage) {}

    void work(const string &project) {
        cout << name << " is coding for project: " << project
             << " using " << programmingLanguage << endl;
    }
};

class Teacher : public Employee {
private:
    string subject;

public:
    Teacher(const string &name, int id, const string &subject)
        : Employee(name, id), subject(subject) {}

    void work() { cout << name << " is teaching subject: " << subject << endl; }
};

int main() {
    // Employee emp("Alice", 101);
    // emp.work();
    // emp.work(8);

    Developer dev("Bob", 102, "C++");
    Teacher teacher("Dr. Smith", 103, "Mathematics");
    
    dev.work("AI System");
    teacher.work();

    return 0;
}
