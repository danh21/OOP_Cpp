#include <iostream>
using namespace std;

class Person
{
public:
    Person( const string &, const string & );
    virtual ~Person();
    const string & getFirstName() const
    { return firstName; }
    const string & getLastName() const
    { return lastName; }
    // static method
    static int getCount(); // static method access static data (non-const)
private:
    string firstName;
    string lastName;
    static int count;   // static data
};

// init static data
int Person::count = 0;

// definition of static method, no need to have static keyword
int Person::getCount()
{ return count; }

Person::Person( const string & first, const string & last )
{
    firstName = first;
    lastName = last;
    count++; // modify static data
}

Person::~Person()
{ count--; } // modify static data

int main()
{
    cout << "Before instantiate: " << Person::getCount() << " person(s)" << endl;
    Person *p1 = new Person( "Gates", "Bill" );
    Person *p2 = new Person( "Gosling", "James" );

    cout << "After instantiate : " << p1->getCount() << " person(s)" << endl;
    delete p1; p1 = NULL;
    delete p2; p2 = NULL;

    cout << "After destroy : " << Person::getCount() << " person(s)" << endl;
    return 0;
}