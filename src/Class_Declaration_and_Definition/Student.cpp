/* Use this pointer */
#include <bits/stdc++.h>

using namespace std;

class Student 
{ 
public: 
    Student(int id, string fname, string lname, bool g) : ID(id), firstName(fname), lastName(lname), graduation(g) { } 

    void display() const 
    { 
        cout << "Student: [" << this->ID << "] " << this->firstName << " " << this->lastName 
        << "\nGraduated: " << this->isGraduation() << endl; 
    } 

    void setGraduation(bool graduation) { this->graduation = graduation; } 

private: 
    int ID; 
    bool graduation; 
    string firstName, lastName; 

    string isGraduation() const 
    { 
        return graduation ? "yes" : "no"; // this->graduation 
    } 
}; 

int main() { 
    Student A(1, "danh", "phan", true); 

    A.display(); 

    return 0; 
} 