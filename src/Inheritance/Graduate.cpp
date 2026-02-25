#include <bits/stdc++.h>

using namespace std;

class Person {
protected:
    string name, addr;
    int age, gen;
public:
    Person(string n = "", string a = "", int ag = 0, int g = 1) : name(n),addr(a),age(ag),gen(g) {}
    int getAge() const {
        return age;
    }
};

class Student : virtual public Person {
protected:
    double gpa;
public:
    Student(double gp = 0) : gpa(gp) {}
    double getGPA() const {
        return gpa;
    }
};

class Staff : virtual public Person {
protected:
    double salary;
public:
    Staff(double s = 0) : salary(s) {}
    double getSalary() const {
        return salary;
    }
};

class Graduate : public Student, public Staff {
public:
    Graduate(string n = "", string a = "", int ag = 0, int g = 1, double gp = 0, double s = 0) : Person(n,a,ag,g), Student(gp), Staff(s) {}
};

int main(int, char**) {
    Graduate p( "Arnold", "Hollywood", 30 );
    cout << p.getAge() << endl;
    return 0;
}
