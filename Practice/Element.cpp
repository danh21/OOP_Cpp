#include <bits/stdc++.h>

using namespace std;

class Element {
    int number;
    string symbol, name;
    double weight;
public:
    int getNumber() const {
        return number;
    }

    string getName() const {
        return name;
    }

    bool accept() {
        while(1) {
            cout << "\nEnter element number: ";
            cin >> number;
            if (number == 0)
                break;

            cout << "Enter symbol: ";
            cin >> symbol;

            cout << "Enter full name: ";
            cin >> name;

            cout << "Enter element weight: ";
            cin >> weight;

            break;
        }

        return true;
    }

    void display() const {
        cout << number << "\t" << symbol << "\t" << name << "\t" << weight << endl;
    }
};

int main(int, char**) {
    Element arr[110];
    cout << "[--- Element Information ---]";
    for (int i = 0; i < 110; i++) {
        arr[i].accept();
        if (arr[i].getNumber() == 0)
            break;
    }

    cout << "\nNo\tSymbol\tName\tWeight\n";
    cout << "------------------------------\n";
    for (int i = 0; i < 110; i++) {
        if (arr[i].getNumber() == 0)
            break;
        arr[i].display();
    }

    return 0;
}
