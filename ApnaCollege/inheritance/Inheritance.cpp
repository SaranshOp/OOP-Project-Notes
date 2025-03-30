#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person
{
private:
    string name;
    int age;

public:
    Person() {}
    Person(string name, int age) : name(name), age(age)
    {
        cout << "Person Cons called" << endl;
    }

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
        cout << "Derived Cons called" << endl;
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }

    void displayInfo()
    {
        Person::displayInfo();
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
    if (true)
    {
        Person S1("A", 21);
        S1.displayInfo();
    }
    Student S2;
    S2.changeName("B"); // base class setter function
    S2.changeAge(22);   // base class setter function
    S2.changeStudentId("ABC123");
    cout << "Info:" << endl;
    S2.displayInfo();

    Student S3("SK", 23, "ABSC213"); // constructor of derived class even when its private

    return 0;
}
// Derived class: Teacher
// class Teacher : public Person
// {
// private:
//     string subject;

// public:
//     Teacher(string name, int age, string subject)
//         : Person(name, age), subject(subject) {}

//     void displayTeacherInfo()
//     {
//         displayInfo();
//         cout << "Subject: " << subject << endl;
//     }
// };

// cout << "\nTeacher Info:" << endl;
// teacher.displayTeacherInfo();