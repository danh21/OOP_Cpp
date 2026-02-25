#include <bits/stdc++.h>

using namespace std;

class Star {
    friend ostream& operator<<(ostream& os, const Star& obj) {
        for (int i = 1; i <= obj.n; ++i )
        {
            for (int j = 1; j <= obj.n + i - 1; ++j )
                os << ( ( j < obj.n - i + 1 ) ? " " : "* " );
            os << endl;
        }
        return os;
    }
private:
    int n;
public:
    Star(int k) : n(k) {}
};

int main(int, char**) {
    Star a( 5 );
    cout << a;
    return 0;
}
