#include <bits/stdc++.h>

using namespace std;

#define datafile "Stream/data.bin"

class Account {
    friend ostream& operator<<(ostream& os, const Account& obj) {
        os << "[" << obj.code << "] " << obj.name << " ($" << obj.balance << ")";
        return os;
    }
private:
    unsigned int code;
    string name;
    double balance;
public:
    Account(unsigned int c = 0, string n = "", double b = 0.0) : code(c),name(n),balance(b) {}

    unsigned int getCode() const {
        return code;
    }

    ostream& write(ostream& os) {
        os.write(reinterpret_cast<char*>(this), sizeof(Account));
        return os;
    }

    istream& read(istream& is) {
        is.read(reinterpret_cast<char*>(this), sizeof(Account));
        return is;
    }
};

int main()
{
    Account* accounts[] = {
        new Account( 1, "Whitney Elizabeth Houston", 2500 ),
        new Account( 2, "Michael Joseph Jackson", 3400 )
    };

    // Fix segmentation fault when run consecutively
    if (filesystem::exists(datafile))
        remove(datafile);

    // write data to data.bin
    fstream outf ( datafile, ios::out | ios::app | ios::binary );
    for ( int i = 0; i < sizeof(accounts)/sizeof(accounts[0]); ++i )
        if ( ! accounts[i]->write(outf) )
            cerr << "Error in writing!" << endl;
    outf.close();

    // read data from data.bin
    cout << "display accounts" << endl;
    fstream inf ( datafile, ios::in | ios::binary );
    for ( unsigned int i = 1; i <= sizeof(accounts)/sizeof(accounts[0]); ++i ) {
        Account temp(i);
        inf.seekp( ( temp.getCode() - 1 ) * sizeof( Account ) );
        if ( ! temp.read( inf ) )
            cerr << "Error in reading!" << endl;
        else
            cout << temp << endl;
    }
    inf.close();

    for ( int i = 0; i < sizeof(accounts)/sizeof(accounts[0]); ++i )
        delete accounts[i];

    return 0;
}
