/* Declare & define a class */
#include <bits/stdc++.h>

using namespace std;

class Account
{
public:
    bool init( long = 1111111, const string & = "N/A", double = 0.0 );
    void display() const;
private:
    long code; 
    string name; 
    double balance;
};

bool Account::init(long c, const string& s, double b) 
{ 
    if (s.empty()) 
        return false; 

    code = c; 
    name = s; 
    balance = b; 
    return true; 
} 

void Account::display() const 
{ 
    cout << fixed << setprecision(2) 
    << "--------------------------------------\n" 
    << "Account number : " << code << '\n' 
    << "Account holder : " << name << '\n' 
    << "Account balance: " << balance << '\n' 
    << "--------------------------------------\n" 
    << endl; 
} 

int main() 
{ 
    Account account; 

    Account* p = &account;

    account.init(1234567, "Pitt, Brad", 1963.75); 

    account.display(); 

    p->display(); 

    return 0; 
} 
