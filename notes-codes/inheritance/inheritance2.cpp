#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person
{
protected:
    string name;
    int age;

public:
    Person() {}
    Person(string name, int age) : name(name), age(age) {}

    void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    void changeName(string nname)
    {
        name = nname;
    }
    void changeAge(int nage)
    {
        age = nage;
    }
    ~Person()
    {
        cout << "Person Destructor called " << endl;
    }
};

// Derived class: Student
class Student : public Person
{
private:
    string studentID;

public:
    Student() : Person() {}
    Student(string name, int age, string studentID) : Person(name, age), studentID(studentID)
    {
        cout << "C called" << endl;
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }

    void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }

    void changeStudentId(string nstudentID)
    {
        studentID = nstudentID;
    }
    ~Student()
    {
        cout << "Student destructor called " << endl;
    }
};

//

int main()
{
    Student S3("SK", 23, "ABSC213");

    return 0;
}
