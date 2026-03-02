#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    { cout << "Constructor of class Base\n"; }
    virtual ~Base()
    { cout << "Destructor of class Base\n"; }
};

class Derived : public Base
{
private:
    string data;
public:
    Derived( const string & n ) : data( n )
    { cout << "Constructor of class Derived\n"; }
    ~Derived() 
    { cout << "Destructor of class Derived\n"; }
};

int main()
{
    Base *bPtr = new Derived( "DEMO" );
    cout << "\nCall to the virtual Destructor!\n";
    delete bPtr;
    // Destructor of class Derived
    // Destructor of class Base
    return 0;
}