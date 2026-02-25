#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    enum year {fresh, soph, junior, senior, grad};
    Student(string n, unsigned int i, double s, year y) : name(n),id(i),gpa(s),status(y) {}
    virtual string toString() const {
        stringstream ss;
        ss << "name: " << name << " id: " << id << " gpa: " << gpa << " status: " << status << endl;
        return ss.str();
    }
protected:
    string name;
    unsigned int id;
    double gpa;
    year status;
};

class GradStudent : public Student {
public:
    enum Support { ta, ra, fellowship, other };
    GradStudent(string n, unsigned int i, double g, year y, Support s, string d, string t) : Student(n, i, g, y),sp(s),dept(d),thesis(t) {}
    string toString() const {
        stringstream ss;
        ss << Student::toString() << dept << ", thesis: \"" << thesis << "\"" << endl;
        return ss.str();
    }
protected:
    Support sp;
    string dept;
    string thesis;
};

int main(int, char**) {
    Student s( "Bill Gates", 101, 6.3, Student::junior );
    GradStudent g( "James Gosling", 201, 9.8, Student::grad, GradStudent::other, "Computer Science", "Java language" );
    cout << s.toString();
    cout << g.toString();

    return 0;
}
