#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Single Inheritance
class Teacher : public Person {
public:
    string subject;

    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}

    void displayTeacher() {
        displayPerson();
        cout << "Subject: " << subject << endl;
    }
};

// Hierarchical Inheritance
class Student : public Person {
public:
    string course;

    Student(string n, int a, string c) : Person(n, a), course(c) {}

    void displayStudent() {
        displayPerson();
        cout << "Course: " << course << endl;
    }
};

// Multiple Inheritance
class TA : public Teacher, public Student {
public:
    TA(string tn, int ta, string ts, string sn, int sa, string sc)
        : Teacher(tn, ta, ts), Student(sn, sa, sc) {}

    void displayTA() {
        Teacher::displayTeacher();
        Student::displayStudent();
    }
};

// Multilevel Inheritance
class HeadTeacher : public Teacher {
public:
    int yearsOfExperience;

    HeadTeacher(string n, int a, string s, int y) : Teacher(n, a, s), yearsOfExperience(y) {}

    void displayHeadTeacher() {
        displayTeacher();
        cout << "Years of Experience: " << yearsOfExperience << endl;
    }
};



int main() {
    // Single Inheritance
    Teacher t("Alice", 30, "Math");
    t.displayTeacher();

    // Multilevel Inheritance
    HeadTeacher ht("Bob", 50, "Science", 25);
    ht.displayHeadTeacher();

    // Multiple Inheritance
    TA ta("Charlie", 25, "Physics", "Dave", 20, "CS");
    ta.displayTA();

    // Hierarchical Inheritance
    Student s("Eve", 22, "Biology");
    s.displayStudent();

    return 0;
}