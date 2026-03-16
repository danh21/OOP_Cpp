#include <bits/stdc++.h>

using namespace std;

int add( int a, int b ) { return a + b; }
int mul( int a, int b ) { return a * b; }
typedef int ( *VPF )( int, int );

VPF v[] = { add, mul }; // array of function pointers

// int caller( int, int, int ( *p )( int, int ) );
int caller( int a, int b, VPF p )
{
    return p( a, b );
}

int main()
{
    VPF pFunc = mul;                        // use function name as a function pointer
    cout << pFunc( 4, 5 ) << endl;          // use function pointer like a function
    cout << v[0]( 4, 5 ) << endl;           // use function pointer from array of function pointers
    cout << caller( 4, 5, add ) << endl;    // call function with function pointer as argument
    return 0;
}
