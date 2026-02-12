#include <bits/stdc++.h>

using namespace std;

class DoubleVector
{
    friend ostream & operator<<( ostream &, const DoubleVector & );
    double* p; // thành phần dữ liệu động của lớp
    size_t size;
public:
    DoubleVector( int = 10 );
    // copy constructor
    DoubleVector( const DoubleVector & );
    ~DoubleVector()
    { delete p; } // giải phóng cấp phát trong destructor
    int ubound() const { return size - 1; }
    double & operator[]( int i );
    void getAddrPointer() const {
        cout << (void*) p << endl;
    }
};

DoubleVector:: DoubleVector( int n ) : size( n ) {
    if ( n < 0 ) throw bad_alloc();
    p = new double[ size ]; // cấp phát trong constructor
    cout << (void*) p << " " << size << endl;
}

DoubleVector:: DoubleVector( const DoubleVector & dv ) : size( dv.size )
{
    cout << "copy ctor ...\n";
    p = new double[size];
    memcpy( p, dv.p, size * sizeof( double ) );
}

double & DoubleVector::operator[]( int i )
{
    if ( i < 0 || i >= size )
        throw out_of_range( "::operator[]" );
    return p[i];
}

ostream & operator<<( ostream& os, const DoubleVector& right )
{
    for ( int i = 0; i < right.size; ++i )
        os << right.p[i] << ' ';
    return os << endl;
}

DoubleVector & foo( DoubleVector & dv )
{
    for ( int i = 0; i <= dv.ubound(); ++i )
        dv[i] = i + i/10.0;
    return dv;
}

DoubleVector boo( DoubleVector dv )
{
    for( int i = 0; i < dv.ubound(); ++i )
        dv[i] = i + i/10.0;
    return dv;
}

int main()
{
    DoubleVector s( 5 );
    // foo( s );
    boo(s);
    cout << s;
    // cout << s[11] << endl;

    DoubleVector b = s;
    b.getAddrPointer();
    // b = s;
    // b.getAddrPointer(); // p of b is same as p of s

    return 0;
}