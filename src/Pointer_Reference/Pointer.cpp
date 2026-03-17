#include <bits/stdc++.h>

using namespace std;

class Point
{
    int x, y;
public:
    Point( int a = 0, int b = 0 )
    { x = a; y = b; }
    void show()
    { std::cout << "( " << x << ", " << y << " )\n"; }
};

int main()
{
    // use reference to a dynamically allocated object
    Point& q = *new Point( 3, 4 );
    q.show();

    Point a(10, 20);
    Point b(120, 20);
    Point& p = a;
    p.show();   // show a

    p = b;
    a.show();   // a has been changed to b

    p = Point( 30, 40 );
    a.show();   // a has been changed to a temporary object
    b.show();   // b has not been changed

    return 0;
}