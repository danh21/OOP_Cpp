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

int main()
{
    Point* a = new Point( 3, 5 );
    {
        Point b( 4, 7 );
    } // destructor của đối tượng b được gọi, do b ra ngoài tầm vực

    delete a; // destructor của đối tượng a được gọi, do con trỏ quản lý a bị hủy
}