#include <bits/stdc++.h>

using namespace std;

#define MENU "1. Deposit\n" \
             "2. Withdraw\n" \
             "3. View balance\n" \
             "4. View transactions\n" \
             "5. Quit\n" \
             "Your choice? "

class Account {
    double balance;
    vector<string> log;
public:
    Account(double init = 0) : balance(init) {

    }

    double getBalance() const {
        return balance;
    }

    void credit (double amount) {
        if (amount > 0)
            balance += amount;
        else
            throw invalid_argument("amount must be > 0");

        char buffer[100];
        sprintf(buffer, "Deposit: %.2f, Balance: %.2f", amount, balance);

        log.push_back(string(buffer));
    }

    void debit (double &amount) {
        if (amount <= balance)
            balance -= amount;
        else 
            balance -= balance;

         char buffer[100];
        sprintf(buffer, "Depit: %.2f, Balance: %.2f", amount, balance);

        log.push_back(string(buffer));
    }

    string toString() {
        char buffer[100];
        sprintf(buffer, "Balance: %.2f", balance);
        return string(buffer);
    }

    void viewLog() const {
        for (auto s : log) {
            cout << s << endl;
        }
        cout << endl;
    }
};

int main(int, char**) {
    Account acc;
    bool quit = false;
    unsigned int opt;
    double amount;

    while (!quit) {
        cout << MENU;
        cin >> opt;

        if (cin.fail()) {
            cin.clear();                      // xóa trạng thái lỗi
            cin.ignore(10000, '\n');          // bỏ dữ liệu rác
            continue;
        }

        switch (opt)
        {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                acc.credit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                acc.debit(amount);
                break;

            case 3:
                cout << acc.toString() << endl;
                break;

            case 4:
                acc.viewLog();
                break;

            case 5:
                quit = true;
                break;
            
            default:
                break;
        }
    }

    return 0;
}
