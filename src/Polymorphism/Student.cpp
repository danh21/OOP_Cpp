#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    enum Year { fresh, soph, junior, senior, grad };
    Student( const string &, int, double, Year );
    string toString() const;
protected:
    string name;
    int studentID;
    double gpa;
    Year year;
};

Student::Student( const string & nm, int id, double g, Year y ) : name( nm ), studentID( id ), gpa( g ), year( y )
{ }

string Student::toString() const
{
    stringstream ss;
    ss << "\nStudent: " << name << ", " << studentID << ", " << year << ", " << gpa << endl;
    return ss.str();
}

class GradStudent : public Student
{
public:
    enum Support { ta, ra, fellowship, other };
    GradStudent( const string &, int, double, Year, Support, const string &, const string & );
    string toString() const;
protected:
    Support s;
    string dept;
    string thesis;
};

GradStudent::GradStudent( const string & nm, int id, double g, Year x, Support t, const string & d, const string & th )
: Student( nm, id, g, x ), s( t ), dept( d ), thesis( th )
{ }

string GradStudent::toString() const
{
    stringstream ss;
    ss << Student::toString()
    << dept << ", thesis: \"" << thesis << "\"" << endl;
    return ss.str();
}

int main()
{
    Student s( "Bill Gates", 100, 3.425, Student::fresh );
    GradStudent gs( "Linus Tovarld", 200, 3.2564, Student::grad, GradStudent::ta, "Operating System","Linux OS");
    Student* ps = &s;
    GradStudent* pgs;
    
    cout << gs.Student::toString();     // Student::toString
    cout << gs.toString();              // GradStudent::toString
    cout << ps->toString();             // Student::toString
    
    ps = pgs = &gs;                    
    cout << pgs->toString();            // GradStudent::toString
    cout << ps->toString();             // Student::toString

    // GradStudent* pgs1 = &s;          // error: invalid conversion from 'Student*' to 'GradStudent*'

    return 0;
}