#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;

class Shape
{
public:
    Shape() : x( 0.0 ), y( 0.0 ) {}
    void setPos( double nx, double ny )
    { x = nx; y = ny; }
    virtual double getArea() const = 0;
    virtual string getName() const = 0;
protected:
    double x, y;
};

class Rectangle : public Shape
{
public:
    Rectangle( double h, double w ) : height( h ), width( w ) {}
    double getArea() const { return ( height * width ); }
    string getName() const { return ( " RECTANGLE " ); }
private:
    double height, width;
};

class Circle : public Shape
{
public:
    Circle( double r ) : radius( r ) {}
    double getArea() const { return ( PI * radius * radius ); }
    string getName() const { return ( " CIRCLE " ); }
private:
    double radius;
};

class Polygon : public Shape
{
public:
    Polygon( int n, double s ): number( n ), side( s ) {}
    double getArea() const
    { return ( side * side * number / ( 4.0 * tan( PI / number ) ) ); }
    string getName() const { return ( " POLYGON " ); }
private:
    int number;
    double side;
};

int main()
{
    Shape* shps[] = { new Circle( 2.2 ), new Polygon( 14, 1.3 ), new Rectangle( 5.2, 3.0 ) };
    for( int i = 0; i < 3; ++i )
        cout << shps[i]->getName() << "area = " << shps[i]->getArea() << endl;
    return 0;
}