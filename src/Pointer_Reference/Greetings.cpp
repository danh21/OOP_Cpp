#include <bits/stdc++.h>

using namespace std;

class Greetings {
public:
    void hello( const string & name ) const
    { cout << "Hello, " << name << endl; }
    
    void byebye( const string & name ) const
    { cout << "Byebye, " << name <<endl; }
};

typedef void ( Greetings::*VPF )( const string& ) const;
void greet( const Greetings* p, string name, VPF pFunc = &Greetings::hello )
{
    ( p->*pFunc )( name );
}

int main()
{
    Greetings* p = new Greetings();
    greet( p, "Albert Einstein", &Greetings::byebye );
    
    Greetings g;
    VPF pf = &Greetings::hello;
    (g.*pf)("danh");
    
    return 0;
}