#include <bits/stdc++.h>

using namespace std;

class Point {
    double x, y;
public:
    Point(double a = 0, double b = 0) : x(a), y(b) {}
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
};

class Line {
    Point start, end; // subobject
    double length;
public:
    Line(const Point& a, const Point& b) : start(a), end(b) {
        length = double(*this);
    }
    Line(double x1, double y1, double x2, double y2) : start(x1,y1), end(x2,y2) {
        length = double(*this);
    }
    operator double() const {
        double dx = end.getX() - start.getX();
        double dy = end.getY() - start.getY();
        return sqrt(dx * dx + dy * dy);
    }
    double getLen() const {
        return length;
    }
};

int main(int, char**){
    Point p( 3, 2 ), q( -1, 4 );
    Line pq( p, q ); // hoặc Line pq( Point( 3, 2 ), Point( -1, 4 ) );
    cout << (double)pq << endl;

    Line pq1( 3, 2, -1, 4 );
    cout << pq1.getLen() << endl;
    return 0;
}
