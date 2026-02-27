#include <bits/stdc++.h>

using namespace std;

class Number {
private:
    long num;
    bool isPrime() const {
        if (num < 2)
            return false;
        for (long i = 2; i <= sqrt(num); ++i)
            if (num % i == 0)
                return false;
        return true;
    }
public:
    Number(int n) : num(n) {}
    operator const void*() const {
        return isPrime() ? this : NULL; 
    }
};

int main()
{
    // Number n( 523582853 );
    Number n( 1 );
    cout << boolalpha << ( bool )n << endl;
    
    return 0;
}