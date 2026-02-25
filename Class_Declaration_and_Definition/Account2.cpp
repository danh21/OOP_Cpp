/* Function overloading */
#include <bits/stdc++.h>
using namespace std;
class Account
{
public:
    // constructor overloading
    Account( long, const string &, double );
    Account( const string & );
    void display();
private:
    long code;
    string name;
    double balance;
};

Account::Account( long c, const string & s, double b ) : code( c ), name( s ), balance( b )
{ }

Account::Account( const string & s ) : code( 1111111 ), name( s ), balance( 0.0 )
{ }

void Account::display() {
    cout << code << " - " << name << " - " << balance << endl;
}

int main()
{
    Account giro( 1234567, "Mouse, Mickey", -1200.45 ), save( "Luke, Lucky" );
    // Account depot; // error because not define default constructor
    giro.display();
    save.display();
    return 0;
}