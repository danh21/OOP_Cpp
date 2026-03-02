#include <iostream>
using namespace std;

class Instrument
{
protected:
    string artist;
public:
    enum note { middleC, Csharp, Cflat };
    Instrument( const string & s = "" ) : artist( s ) {}
    void play( note ) const
    { cout << "Instrument::play " << artist << endl; }
};

class Wind : public Instrument
{
public:
    Wind( const string & s = "" ) : Instrument( s ) {}
    void play( note ) const
    { cout << "Wind::play " << artist << endl; }
};

void tune( const Instrument & obj )
{
    // ...
    obj.play( Instrument::middleC );        // Instrument::play
}

int main()
{
    Wind saxophone( "Kenny G" );
    Instrument clarinet;
    clarinet = saxophone;                   // upcasting Wind to Instrument
    clarinet.play( Instrument::Csharp );    // Instrument::play

    Instrument* instr[2];                   
    Wind trumpet( "Louis Amstrong" );
    instr[0] = new Wind( "Kenny G" );      
    instr[1] = &trumpet;                   
    for ( int i = 0; i < 2; ++i )
        instr[i]->play( Instrument::Cflat ); // Instrument::play

    Wind flute( "Ron Korb" );
    tune( flute );                          // Instrument::play

    return 0;
}