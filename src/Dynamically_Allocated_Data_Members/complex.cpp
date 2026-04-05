#include <bits/stdc++.h>

using namespace std;

class Complex
{
    double real, image;
public:
    // use constructor with all default arguments as default constructor
    Complex( double a = 0.0, double b = 2.0 ) : real( a ), image( b ) { }
    void display()
    {
        cout << real << " + " << image << "i" << std::endl;
    }
};

int main()
{
    // call default constructor for 5 elements of the array managed by pointer a
    Complex *a = new Complex[5];
    // call default constructor for 1 element of array b
    Complex *b = new Complex;

    for ( int i = 0; i < 5; ++i )
        ( a + i )->display();
    b->display();

    return 0;
}