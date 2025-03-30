#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    Employee(const string &name, int id) : name(name), id(id) {}

    virtual void work()
    {
        cout << "Employee " << name << " (ID: " << id << ") is working." << endl;
    }

    virtual ~Employee() {}
};

class Developer : public Employee
{
private:
    string programmingLanguage;

public:
    Developer(const string &name, int id, const string &programmingLanguage)
        : Employee(name, id), programmingLanguage(programmingLanguage) {}

    void work() override
    {
        cout << "Developer " << name << " (ID: " << id << ") is writing code in "
             << programmingLanguage << "." << endl;
    }
};

class Teacher : public Employee
{
private:
    string subject;

public:
    Teacher(const string &name, int id, const string &subject)
        : Employee(name, id), subject(subject) {}

    void work() override
    {
        cout << "Teacher " << name << " (ID: " << id << ") is teaching "
             << subject << "." << endl;
    }
};

int main()
{
    Employee *emp1 = new Developer("Alice", 101, "C++");
    Employee *emp2 = new Teacher("Bob", 102, "Mathematics");

    emp1->work();
    emp2->work();

    delete emp1;
    delete emp2;

    return 0;
}
