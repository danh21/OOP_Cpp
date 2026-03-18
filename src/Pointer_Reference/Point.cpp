#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    double x, y;
    
    Point( double x, double y )
    { this->x = x; this->y = y; }
    
    string toString()
    {
        stringstream ss;
        ss << "( " << x << ", " << y << " )\n";
        return ss.str();
    }
    
    Point upByVal( double dist )
    { y += dist; return *this; }
    
    Point& upByRef( double dist )
    { y += dist; return *this; }
    
    Point & mid( const Point & p ) const
    {
    return *new Point( ( x + p.x )/2, ( y + p.y )/2 );
    }
};

// Returns by value, a new object (an R-value)
Point leftmostVal( Point & p, Point & q )
{ return ( p.x < q.x ) ? p : q; }

// Returns by reference to an existing object (an L-value)
Point & leftmostRef( Point & p, Point & q )
{ return ( p.x < q.x ) ? p : q; }
    
int main()
{
    Point a( 4, 8 ), b( 2, 10 ), c( 1, 5 ), d( 1, 5 );
    cout << leftmostVal( a, b ).toString(); // Returns ( 2, 10 )
    cout << leftmostRef( a, b ).toString(); // Returns ( 2, 10 )
    
    leftmostRef( a, b ) = c;    // OK. Since leftmostRef() is an L-value -> b refers to c
    cout << b.toString();       // Returns ( 1, 5 )
    
    a = leftmostRef( a, b );    // OK. Converts Point& to Point
    cout << a.toString();       // Returns ( 1, 5 )
    
    a.upByVal( 1 ).upByVal( 2 );
    cout << a.toString();       // Returns ( 1, 6 )
    
    b.upByRef( 1 ).upByRef( 2 );// Returns ( 1, 8 ) still references object b
    cout << b.toString();
    
    cout << a.mid( b ).toString(); // Returns ( 1, 7 )
    
    return 0;
}