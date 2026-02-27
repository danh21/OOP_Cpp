#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
public:
    // Constructors: implicit inline
    Account( long c = 1111111L, const string & s = "N/A", double b = 0.0 )
    : code( c ), name( s ), balance( b )
    { }
    // Destructor: implicit inline
    virtual ~Account(){ }
    void display() const;
private:
    long code;
    string name;
    double balance;
};

// explicit inline
inline void Account::display() const
{
    cout << fixed << setprecision(2)
    << "--------------------------------------\n"
    << "Account number : " << code << '\n'
    << "Account holder : " << name << '\n'
    << "Account balance: " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}

int main() {
    Account a(23234,"abc");
    a.display();
}