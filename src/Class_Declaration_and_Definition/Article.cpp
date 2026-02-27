#include <bits/stdc++.h>
using namespace std;

class Article
{
public:
    Article( const string & = "", double = 0.0 );
    virtual ~Article();
    
    // accessors methods
    // getters
    long getCode() const { return code; }
    const string & getName() const { return name; }
    double getPrice() const { return price; }
    
    // setters
    void setName( const string & s )
    {
        if ( s.size() < 1 )
            throw string( "Empty string!" );
        name = s;
    }
    void setPrice( double p )
    {
        price = p > 0.0 ? p : 0.0;
    }
private:
    long code;
    string name;
    double price;
    static int countObj;    // static member
    void setCode() { code = countObj; }
};

int Article::countObj = 0; // init

Article::Article( const string & s, double p ) : name( s )
{
    setPrice( p );
    setCode();
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
    Article a("law");
    a.setPrice(123.4);
    cout << a.getPrice() << endl;
    
    Article b("entertainment", 43.4);
}