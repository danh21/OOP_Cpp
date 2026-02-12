#include <bits/stdc++.h>

using namespace std;

class X {
    mutable int times;
    int value;
public:
    X(int t, int v) : times(t), value(v) {}
    void display() const {
        this->times++;
        cout << times << endl;
    }
};

int main()
{
    X a(0,2);

    for (int i = 0; i < 5; i++)
        a.display();

    return 0;
}