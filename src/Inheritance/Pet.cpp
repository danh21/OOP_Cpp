#include <bits/stdc++.h>

using namespace std;

class Pet {
protected:
    string name;
public:
    Pet (const string& s) : name(s) {}
    void eat() {
        cout << "Pet::eat\n";
    }
    void sleep() const { cout << "Pet::sleep" << endl; }
};

class GoldFish : Pet {
public:
    using Pet::name;
    GoldFish(const string& s) : Pet(s) {}

    using Pet::eat; // public 1 member function inherited as private

    void sleep() const 
    { 
        Pet::sleep(); // call sleep() method of Pet class
        cout << name << endl; 
    }
};

int main(int, char**) {
    GoldFish bob( "Nemo" );
    // cout << bob.name << endl;

    bob.eat(); // because the eat() method has been made public in GoldFish class

    bob.sleep();

    return 0;
}
