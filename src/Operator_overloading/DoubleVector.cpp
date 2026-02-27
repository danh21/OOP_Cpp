#include <bits/stdc++.h>

using namespace std;

class DoubleVector
{
    friend ostream& operator<<(ostream&, const DoubleVector&);
private:
    double *p;
    size_t size = 0;
public:
    DoubleVector(const DoubleVector& v) {
        cout << "copy ctor\n";
        p = new double[size = v.size];
        for (int i = 0; i < size; i++)
            p[i] = v.p[i];
    }
    DoubleVector(int x = 10) {
        p = new double[size = x];
        for (int i = 0; i < size; i++)
            p[i] = i;
    }
    double operator[](int) const;
    DoubleVector& operator=(const DoubleVector&);
    ~DoubleVector() {
        delete []p;
        p = NULL;
    }
    int ubound() {
        return size;
    }
};

double DoubleVector::operator[](int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("error");
    return p[index];
}

DoubleVector& DoubleVector::operator=(const DoubleVector& v) {
    cout << "operator=\n";
    if (this != &v) {
        delete[] p;
        p = new double[v.size];
        size = v.size;
        for (int i = 0; i < size; i++)
            p[i] = v.p[i];
    }
    return *this;
}

ostream& operator<<(ostream& o, const DoubleVector& obj) {
    for (int i = 0; i < obj.size; i++) {
        o << obj[i] << " ";
    }
    return (o << endl);
}

int main()
{
    DoubleVector A(4);
    cout << A;
    
    DoubleVector B;
    B=A;
    cout << B;
    
    DoubleVector C(B);
    cout << C;
    
    return 0;
}