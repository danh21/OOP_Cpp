#include <iostream>
using namespace std;

class Dollard
{
public:
    explicit Dollard( double x )
    {
        x *= 100.0; // làm tròn
        data = (long)( x >= 0.0 ? x + 0.5 : x - 0.5 );
    }
    long getData() const { return data; }
private:
    long data;
};

void deposit( const Dollard & d )
{
    cout << "Deposit: " << d.getData() << endl;
}

int main()
{
    // ::deposit( 10.7 );           // error becasue of implicit conversion
    deposit( Dollard( 12.52 ) );    // explicit conversion
    return 0;
}