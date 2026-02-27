#include <bits/stdc++.h>

using namespace std;

class Complex {
private:
    double re;
    double im;
public:
    Complex(double r, double i) : re(r), im(i) {}
    Complex operator-() const;
    Complex& operator++();
    Complex operator++(int);
    Complex operator+(const Complex& right) const;
    Complex& operator+=(const Complex& right);
    friend ostream& operator<<(ostream& os, const Complex& obj);
};

Complex Complex::operator-() const {
    return Complex(-re, -im);
}

Complex& Complex::operator++() {
    ++re;
    ++im;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++re;
    ++im;
    return temp;
}

Complex Complex::operator+(const Complex& right) const {
    return Complex(re + right.re, im + right.im);
}

Complex& Complex::operator+=(const Complex& right) {
    re += right.re;
    im += right.im;
    return *this;
}

ostream& operator<<(ostream& os, const Complex& obj) {
    os << obj.re << " + " << obj.im << "i\n";
    return os;
}

int main()
{
    Complex A(2.5, -3);
    // cout << -A;
    
    // cout << ++A;
    
    // cout << A++;
    // cout << A;
    
    Complex B(4, 1);
    cout << A + B;
    
    A += B;
    cout << A;

    return 0;
}