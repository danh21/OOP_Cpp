#include <bits/stdc++.h>
using namespace std;


class Fraction {
private:
    int num;
    int denom;

    void normalize() {
        if (denom == 0)
            throw invalid_argument("Denominator cannot be zero");

        if (num == 0) {
            denom = 1;
            return;
        }

        int _gcd = gcd(num, denom);
        num /= _gcd;
        denom /= _gcd;

        // denominator always positive
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }

public:
    /* ===== constructor ===== */
    Fraction(int n = 0, int d = 1) : num(n), denom(d)
    {
        normalize();
    }

    /* ===== unary operator ===== */
    Fraction operator-() const {
        return Fraction(-num, denom);
    }

    /* ===== friend arithmetic ===== */
    friend Fraction operator+(const Fraction& x, const Fraction& y) {
        return Fraction(
            x.num * y.denom + y.num * x.denom,
            x.denom * y.denom
        );
    }

    friend Fraction operator-(const Fraction& x, const Fraction& y) {
        return Fraction(
            x.num * y.denom - y.num * x.denom,
            x.denom * y.denom
        );
    }

    friend Fraction operator*(const Fraction& x, const Fraction& y) {
        return Fraction(
            x.num * y.num,
            x.denom * y.denom
        );
    }

    friend Fraction operator/(const Fraction& x, const Fraction& y) {
        if (y.num == 0)
            throw invalid_argument("Divide by zero fraction");

        return Fraction(
            x.num * y.denom,
            x.denom * y.num
        );
    }

    /* ===== compound assignment ===== */
    Fraction& operator+=(const Fraction& y) {   // custom use 1 arg
        num = num * y.denom + y.num * denom;
        denom = denom * y.denom;
        normalize();
        return *this;
    }

    friend Fraction& operator-=(Fraction& x, const Fraction& y) {
        x = x - y;
        return x;
    }

    friend Fraction& operator*=(Fraction& x, const Fraction& y) {
        x = x * y;
        return x;
    }

    friend Fraction& operator/=(Fraction& x, const Fraction& y) {
        x = x / y;
        return x;
    }

    /* ===== comparison ===== */
    friend bool operator==(const Fraction& x, const Fraction& y) {
        return x.num == y.num && x.denom == y.denom;
    }

    friend bool operator<(const Fraction& x, const Fraction& y) {
        return x.num * y.denom < y.num * x.denom;
    }

    friend bool operator>(const Fraction& x, const Fraction& y) {
        return y < x;
    }

    /* ===== output ===== */
    friend ostream& operator<<(ostream& os, const Fraction& right) {
        if (right.denom == 1)
            os << right.num;
        else
            os << right.num << "/" << right.denom;
        return os;
    }
};

int main()
{
    Fraction a(1, 4), b(3, 2), c, d;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "-b = " << -b << endl;

    c = 5 + a;
    cout << "c = 5 + a = " << c << endl;
    d = 1 - b;
    cout << "d = 1 - b = " << d << endl;
    c = 7 * a;
    cout << "c = 7 * a = " << c << endl;
    d = 2 / b;
    cout << "d = 2 / b = " << d << endl;

    c += 3;
    cout << "c += 3, c = " << c << endl;
    d *= 2;
    cout << "d *= 2, d = " << d << endl;

    cout << "a < 5: " << boolalpha << (a < 5) << endl;
    cout << "1 < b: " << boolalpha << (1 < b) << endl;
    cout << "d * b - a == c - 1: " << boolalpha << (d * b - a == c - 1) << endl;

    return 0;
}