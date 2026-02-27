#include <bits/stdc++.h>

using namespace std;

class Vector
{
    friend Vector operator+( const Vector & V1, const Vector & V2 );
    friend Vector operator-( const Vector & V1, const Vector & V2 );
    friend Vector operator*( const Vector & V, double k );
    friend Vector operator*( double k, const Vector & V );
private:
    double x, y;
public:
    // Vector() {}
    Vector( double a = 0, double b = 0 ) : x(a), y(b) {
        // println("ctor {} - {}\n", x, y);
    }
    friend ostream& operator<<(ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);
};


Vector operator+(const Vector & V1, const Vector & V2) {
    // cout << "operator+\n";
    return (Vector(V1.x + V2.x, V1.y + V2.y));
}

Vector operator-( const Vector & V1, const Vector & V2 ) { 
    return Vector( V1.x - V2.x, V1.y - V2.y );
}

Vector operator*( const Vector & V, double k )
{ return Vector( V.x * k + V.y * k ); }

Vector operator*( double k, const Vector & V )
{ return Vector( V.x * k + V.y * k ); }

ostream& operator<<(ostream& o, const Vector& obj) {
    o << obj.x << " - " << obj.y << endl;
    return o;
}

istream& operator>>(istream& i, Vector& obj) {
    i >> obj.x >> obj.y;
    return i;
}

int main()
{
    // Vector V1( 2.0, 3.0 ), V2( 4.0, 5.0 );

    // V1 = V1 + V2;
    // cout << V1;
    
    // V1 = V1 + 3.3;
    // cout << V1;
    
    // V1 = 2.1 + V2;
    
    Vector a;
    cin >> a;
    cout << a;
    return 0;
}