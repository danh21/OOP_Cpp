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

    using Pet::eat; // "công khai" một phương thức thành viên thừa kế private

    void sleep() const // gọi phương thức sleep lớp Pet
    { Pet::sleep(); cout << name << endl; }
};

int main(int, char**) {
    GoldFish bob( "Nemo" );
    cout << bob.name << endl;

    bob.eat(); // do phương thức eat đã "công khai" nên gọi được

    bob.sleep();

    return 0;
}
