#include <iostream>
#include <iomanip>
using namespace std;

class SalesPerson
{
public:
    SalesPerson();
    void getSalesFromUser(); 
    void setSales( int, double ); 
    void printAnnualSales() const;
private:
    double totalAnnualSales() const;    //helper method
    double sales[3];
};

SalesPerson::SalesPerson()
{
    for ( int i = 0; i < 3; ++i )
        sales[i] = 0.0;
}

void SalesPerson::getSalesFromUser()
{
    double salesFigure;
    for ( int i = 1; i <= 3; ++i )
    {
        cout << "Enter sales amount for month " << i << ": ";
        cin >> salesFigure;
        setSales( i, salesFigure );
    }
}

void SalesPerson::setSales( int month, double amount )
{
    if ( month < 1 && month > 3 && amount <= 0 )
        throw string( "Invalid month or sales figure" );
    sales[month - 1] = amount;
}

void SalesPerson::printAnnualSales() const
{
    cout << setprecision( 2 ) << fixed << "\nThe total annual sales are: $"
    << totalAnnualSales() << endl;
}

double SalesPerson::totalAnnualSales() const
{
    double total = 0.0;
    for ( int i = 0; i < 3; ++i ) total += sales[i];
    return total;
}

int main() {
    SalesPerson a;
    a.getSalesFromUser();
    
    a.printAnnualSales();
}