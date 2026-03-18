#include <bits/stdc++.h>

using namespace std;

class Matrix
{
    double m[100][100];
    int deg;
public:
    Matrix( int n = 0, int val = 1 );
    double& value( int i, int j )
    { return m[i][j]; }
    Matrix operator*( int k );
    void display();
};

Matrix::Matrix( int n, int val ) : deg( n )
{
    for ( int i = 0; i < deg; ++i )
        for ( int j = 0; j < deg; ++j )
            value( i, j ) = val;
}

Matrix Matrix::operator*( int k )
{
    Matrix a( deg );
    for ( int i = 0; i < a.deg; ++i )
        for ( int j = 0; j < a.deg; ++j )
            a.value( i, j ) = k * value( i, j );
    return a;
}

void Matrix::display()
{
    for ( int i = 0; i < deg; ++i )
    {
        for ( int j = 0; j < deg; ++j )
            cout << value( i, j ) << '\t';
        cout << endl;
    }
}
    
int main()
{
    Matrix a( 4, 3 );
    ( a * 3 ).display();
    cout << endl;
    a.display();
    return 0;
}