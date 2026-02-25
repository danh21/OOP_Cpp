#include <bits/stdc++.h>

using namespace std;

class Triangle {
    double a,b,c;
    enum Kind {scalene, isosceles, equilateral, right, right_isosceles};
public:
    Triangle(double x = 1, double y = 1, double z = 1) : a(x), b(y), c(z) {
    }

    void setEdges(double x, double y, double z) {
        if (x > 0 && y + z > x)
            a = x;

        if (y > 0 && x + z > y)
            b = y;
        
        if (z > 0 && x + y > z)
            c = z;
    }

    enum Kind getKind() {
        if (a == b && a == c)
            return equilateral;
        else if ((a == b || b == c || a == c) && (a*a + b*b == c*c || c*c + b*b == a*a || a*a + c*c == b*b))
            return right_isosceles;
        else if (a*a + b*b == c*c || c*c + b*b == a*a || a*a + c*c == b*b)
            return right;
        else if (a == b || b == c || a == c)
            return isosceles;
        else
            return scalene;
    }

    double getPerimeter() const {
        return a + b + c;
    }

    double getArea() const {
        double p = getPerimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main(int, char**) {
    Triangle triangle;
    string s[] = {"scalene", "isosceles", "equilateral", "right", "right isosceles"};
    triangle.setEdges(3, 4, 5);
    cout << "This is the " << s[triangle.getKind()] << " triangle" << endl;

    return 0;
}
