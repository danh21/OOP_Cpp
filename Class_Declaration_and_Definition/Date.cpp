#include <bits/stdc++.h>
using namespace std;

class Date
{
public:
    Date() {
        cout << "default constructor called" << endl;
    }

    // constructor with default arguments
    Date( int d = 1, int m = 1, int y = 1970 )
    : day( d ), month( m ), year( y )
    {
        cout << "constructor called" << endl;
    }
    
    // copy constructor
    Date( const Date & o )
    : day( o.day ), month( o.month ), year( o.year )
    { 
        cout << "copy constructor called" << endl;
    }
    
    static void today(Date d);
private:
    int day, month, year;
};

void Date::today( Date d )
{ 
    cout << "day " << d.day << " month " << d.month << " year " << d.year << endl;
}

int main()
{
    Date d1( 20, 4, 1976 );
    Date d2( d1 ); // copy constructor
    Date d3 = d1; // init, not be assignment -> copy constructor
    Date::today( d3 );
    return 0;
}