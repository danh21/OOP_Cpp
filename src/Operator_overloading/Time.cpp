#include <bits/stdc++.h>

using namespace std;

class Time {
private:
    int hths;
public:
    Time(int h = 0, int m = 0, int s = 0) : hths(h * 3600 + m * 60 + s) {}
    operator int() const {
        return hths;
    }
};

int main()
{
    Time t(1,15,30);
    cout << t;
    
    return 0;
}