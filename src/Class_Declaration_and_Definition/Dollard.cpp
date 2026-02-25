#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Dollard
{
public:
    // conversion constructor
    Dollard( double x ) // double to Dollard
    {
        x *= 100.0; // make round
        cent = ( long )( x >= 0.0 ? x + 0.5 : x - 0.5 );
    }
    long getWholePart() const { return cent / 100; }
    int getCents() const { return ( int )( cent % 100 ); }
    const Dollard & operator+=( const Dollard & );
    string toString() const; // output Dollard as string
private:
    long cent;
};

inline string Dollard::toString() const
{
    stringstream ss;
    long temp = cent;
    if ( temp < 0 ) { ss << '-'; temp = -temp; }
    ss << temp/100 << '.' << setfill( '0' ) << setw( 2 ) << temp % 100;
    return ss.str();
}

const Dollard & Dollard::operator+=( const Dollard & right )
{
    cent += right.cent;
    return *this;
}

ostream & operator<<( ostream & os, const Dollard & right )
{
    os << right.toString() << " USD" << endl;
    return os;
}

int main()
{
    Dollard usd( 10.7 );    // conversion ctor: double to Dollard
    usd = 25.2;             // implicit conversion: double to Dollard
    usd += 42.5;            // implicit conversion: double to Dollard
    cout << usd;
    usd = Dollard( 99.9 );  // explicit conversion: conversion ctor
    usd = ( Dollard )12.3;  // explicit conversion: type casting
    cout << usd;
    return 0;
}