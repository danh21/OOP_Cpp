#include <iostream>
using namespace std;

class ClientData {
    int x;
public:
    ClientData(int val) : x(val) {}
    int getX() const { return x; }
};

class B {
    int y;
public:
    B(int val) : y(val) {}
    int getY() const { return y; }
};

int main() {
    ClientData a{100};

    B* b = reinterpret_cast<B*>(&a);

    cout << b->getY() << endl;
}