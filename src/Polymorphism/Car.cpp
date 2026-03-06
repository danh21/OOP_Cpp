#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string brand;
    bool isSold;
    unsigned int id;
    string owner;

public:
    Car(string b, bool flag, unsigned int num, string o)
        : brand(b), isSold(flag), id(num), owner(o) {}

    virtual ~Car() = default;
};

class PassCar : public Car {
public:
    PassCar(string b, bool flag, unsigned int num, string o)
        : Car(b, flag, num, o) {}

    void display() {
        cout << owner << " owns car with id "
             << id << " and brand " << brand << endl;
    }
};

class Truck : public Car {
private:
    int* axles;  

public:
    Truck(string b, bool flag, unsigned int num, string o, int a)
        : Car(b, flag, num, o) {
        axles = new int(a);
    }

    void setAxles() {
        cout << "Truck axles = " << *axles << endl;
    }

    ~Truck() {
        delete axles;
    }
};

int main() {
    PassCar cabrio( "Spitfire", true, 1001, "Triumph" );
    Car* carPtr = &cabrio;                      // upcasting PassCar to Car
    ( (PassCar*) carPtr )->display();           // OK
    static_cast<PassCar*>( carPtr )->display(); // OK
    static_cast<Truck*>( carPtr )->setAxles();  // run-time error, trash return value, because carPtr points to an object of type Truck

    return 0;
}
