#include <bits/stdc++.h>
using namespace std;

class Article
{
public:
    Article( const string & = "", double = 0.0 );
    virtual ~Article();
private:
    long code;
    string name;
    double price;
    static int countObj;
};

// define static member
int Article::countObj = 0;

Article::Article( const string & s, double p )
: name( s ), price( p )
{
    code = countObj;
    ++countObj;
    cout << "[" << code << "] " << name << " is created.\n"
    << "This is the #" << countObj << " article!" << endl;
}

Article::~Article()
{
    cout << "[" << code << "] " << name << " is destroyed.\n"
    << "There are still " << --countObj << " article!"
    << endl;
}

int main() {
    Article a("law", 123.4);
    Article b("entertainment", 43.4);
}