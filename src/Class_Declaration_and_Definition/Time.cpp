#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
    Time( int = 0, int = 0, int = 0 );
    // setters
    void setTime( int, int, int );
    void setHour( int );
    void setMinute( int );
    void setSecond( int );
    // getter
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
   
    void printUniversal() const; // HH:MM:SS
    void printStandard(); // HH:MM:SS AM or PM
private:
    int hour; // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

Time::Time( int hour, int minute, int second )
{ setTime( hour, minute, second ); }

void Time::setTime( int hour, int minute, int second )
{
    setHour( hour );
    setMinute( minute );
    setSecond( second );
}

void Time::setHour( int h )
{ hour = ( h >= 0 && h < 24 ) ? h : 0; }

void Time::setMinute( int m )
{ minute = ( m >= 0 && m < 60 ) ? m : 0; }

void Time::setSecond( int s )
{ second = ( s >= 0 && s < 60 ) ? s : 0; }

void Time::printUniversal() const
{
    cout << setfill( '0' ) << setw( 2 ) << hour << ":"
    << setw( 2 ) << minute << ":" << setw( 2 ) << second;
}

void Time::printStandard()
{
    cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
    << ":" << setfill( '0' ) << setw( 2 ) << minute
    << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
}

int main()
{
    Time wakeUp( 6, 45, 0 ); // non-constant
    const Time noon( 12 ); // constant
    // OBJECT MEMBER FUNCTION
    wakeUp.setHour( 18 ); // non-const non-const
    // noon.setHour( 12 ); // const non-const ERROR
    cout << wakeUp.getHour() << endl; // non-const const
    noon.getMinute(); // const const
    noon.printUniversal(); // const const
    // noon.printStandard(); // const non-const ERROR
    return 0;
}