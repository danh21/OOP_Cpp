#include <bits/stdc++.h>

using namespace std;

class Point
{
    int x, y, color;
    string label;
public:
    // ...
    Point( int a = 0, int b = 0, int c = 1, string s = "" )
    : x( a ), y( b ), color( c ), label( s ) { }

    void display()
    {
        cout << label << "( " << x << ", " << y
        << ", " << color << " )" << endl;
    }

    ~Point()
    {
        cout << "Point::destructor()" << endl;
        display();
    }
};

/**
 * @brief Demonstrates dynamic memory allocation and object destruction in C++.
 *
 * This program illustrates the lifecycle of Point objects:
 * - A Point object 'a' is dynamically allocated using 'new'.
 * - A local Point object 'b' is created on the stack.
 * - When 'b' goes out of scope, its destructor is automatically called.
 * - The dynamically allocated object 'a' is explicitly deleted, invoking its destructor.
 *
 * This example highlights the importance of proper memory management to avoid leaks.
 */
int main()
{
    Point* a = new Point( 3, 5 );
    {
        Point b( 4, 7 );
    }

    delete a;
}