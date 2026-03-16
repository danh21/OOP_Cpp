#include <bits/stdc++.h>

using namespace std;

class Fraction
{
public:
    int num, denom;
    void display()
    {
        cout << num << '/' << denom << std::endl;
    }
};

int main()
{
    Fraction u = { 2, 3 };          // Fraction 2/3
    Fraction* fp = &u;              // Pointer fp manages the Fraction object u

    (*fp).num = (*fp).denom + 1;    // Rarely used member access syntax, fraction becomes 4/3
    u.display();                    // Call display() method DIRECTLY
    fp->display();                  // Call display() method INDIRECTLY

    u.num = u.denom + 1;            // Change u DIRECTLY
                                    // Change u INDIRECTLY through pointer fp using -> operator
    fp->num = fp->denom + 2;        // Fraction becomes 5/3
    u.display();
    return 0;
}