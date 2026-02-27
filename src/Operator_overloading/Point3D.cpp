#include <bits/stdc++.h>

using namespace std;

class Point3D {
    friend ostream & operator<<( ostream &, const Point3D & );
public:
    Point3D() { x = y = z = 0; }
    Point3D( int i, int j, int k ) : x( i ), y( j ), z( k ) { }
    void set( int i, int j, int k ) { x = i; y = j; z = k; }
    void *operator new( size_t size );
    void operator delete( void *p );
    void *operator new[]( size_t size );
    void operator delete[]( void *p );
private:
    int x, y, z;
};

ostream & operator<<( ostream & os, const Point3D & r ) {
    os << r.x << ", " << r.y << ", " << r.z << endl;
    return os;
}

void *Point3D::operator new( size_t size )
{
    cout << "Point3D::operator new" << endl;
    void* p = malloc( size );
    if ( !p ) throw bad_alloc();
    return p;
}

void Point3D::operator delete( void *p )
{
    cout << "Point3D::operator delete" << endl;
    free( p );
}

void *Point3D::operator new[]( size_t size )
{
    cout << "Point3D::operator new[]" << endl;
    void* p = malloc(size);
    if ( !p ) throw bad_alloc();
    return p;
}

void Point3D::operator delete[]( void *p )
{
    cout << "Point3D::operator delete[]" << endl;
    free( p );
}

int main()
{
    Point3D *p1, *p2;
    
    try {
        p1 = new Point3D ( 10, 20, 30 );
    } catch ( bad_alloc ba ) {
        cout << "Allocation Point3D object error" << endl;
        return 1;
    }
    cout << *p1;
    delete p1;
    
    try {
        p2 = new Point3D[4];
    } catch ( bad_alloc ba ) {
        cout << "Allocation Point3D array error" << endl;
    return 1;
    }
    p2[1].set( 17, 23, 31 );
    p2[3].set( -18, 24, -46 );
    cout << "Contents of Point3D array: " << endl;
    for( int i = 0; i < 4; ++i )
        cout << "array[" << i << "]: " << p2[i];
    delete [] p2;
    
    return 0;
}