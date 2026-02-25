/* Default arguments */
#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    Point( int = 0, int = 0 );
    void moveTo( int = 0, int = 0 );
    void display();
private:
    int x, y;
};

Point::Point( int a, int b ) : x( a ), y( b ) { }

void Point::moveTo( int dx, int dy )
{
    x += dx;
    y += dy;
}

void Point::display() {
    cout << "x: " << x << " ; y: " << y << endl;
}

int main()
{
    Point p; // Point( 0, 0 )
    p.display();
    
    p.moveTo(); // moveTo( 0, 0 )
    p.display();
    
    p.moveTo( 12 ); // moveTo( 12, 0 )
    p.display();
    
    p.moveTo( 36, 18 );
    p.display();
    return 0;
}