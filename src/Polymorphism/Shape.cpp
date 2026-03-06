#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;

class Shape
{
public:
    Shape( const string & s = "" ) : name( s ) {}
    virtual double getArea() const = 0;
    string getName() const { return name; }
protected:
    string name;
};

class Rectangle : public Shape
{
public:
    Rectangle( const string & s, double w, double h ) : Shape( s ), width( w ), height( h ) { }
    double getArea() const { return width * height; }
private:
    double height, width;
};

class Circle : public Shape
{
public:
    Circle( const string & s, double r ) : Shape( s ), radius( r ) {}
    double getArea() const { return ( PI * radius * radius ); }
private:
    double radius;
};

class Polygon : public Shape
{
public:
    Polygon(const string &s, int n, double r ): Shape( s ), number( n ), side( r ) {}
    double getArea() const
    { return ( side * side * number / ( 4.0 * tan( PI / number ) ) ); }
private:
    int number;
    double side;
};

void display( const Shape & shape )
{
    shape.getName();
}

int main()
{
    Shape* shps[] = { new Circle("Circle", 2.2 ), new Polygon("Polygon", 14, 1.3 ), new Rectangle("Rectangle", 5.2, 3.0 ) };
    for( int i = 0; i < 3; ++i )
        cout << shps[i]->getName() << " area = " << shps[i]->getArea() << endl;
    return 0;
}