#include <bits/stdc++.h>
using namespace std;

class Account {
protected:
    string name;   // owner
    string code;
    double balance;

public:
    Account(const string& c = "N/A",
            double b = 0.0,
            const string& n = "")
        : code(c), balance(b), name(n) {}

    virtual ~Account() {}

    const string& getName() const { return name; }

    void setName(const string& n) { name = n; }

    string getCode() const { return code; }

    void setCode(const string& c) { code = c; }

    double getBalance() const { return balance; }

    void setBalance(double b) { balance = b; }

    virtual void deposit(double a) {
        balance += a;
    }

    virtual bool withdraw(double a) {
        if (a > balance) return false;
        balance -= a;
        return true;
    }

    virtual void display(ostream& os) const {
        os << "[" << code << "]-------------------------\n";
        os << "Balance : $" << fixed << setprecision(2)
           << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double rate;

public:
    SavingsAccount(const string& c,
                   double b,
                   double r,
                   const string& n = "")
        : Account(c, b, n), rate(r) {
            balance += (rate * balance);
        }

    double getRate() const { return rate; }

    void setRate(double r) { rate = r; }

    void display(ostream& os) const override {
        Account::display(os);
        os << "Interest rate : "
           << fixed << setprecision(2)
           << rate << endl;
    }
};

class CheckingAccount : public Account {
private:
    double fee;

public:
    CheckingAccount(const string& c,
                    double b,
                    double f,
                    const string& n = "")
        : Account(c, b, n), fee(f) {}

    double getFee() const { return fee; }

    void setFee(double f) { fee = f; }

    bool withdraw(double a) override {
        double total = a + fee;
        if (total > balance) return false;
        balance -= total;
        return true;
    }

    void display(ostream& os) const override {
        Account::display(os);
        os << "Fee : "
           << fixed << setprecision(2)
           << fee << endl;
    }
};

class Customer {
private:
    string name;
    vector<Account*> accounts;

public:
    Customer(const string& n) : name(n) {}

    ~Customer() {
        for (auto acc : accounts)
            delete acc;
    }

    void addAccount(Account* a) {
        accounts.push_back(a);
    }

    const string& getName() const { return name; }

    vector<Account*> getAccounts() const { return accounts; }

    void display(ostream& os) const {
        os << "Owner: " << name << endl;
        for (auto acc : accounts)
            acc->display(os);
    }
};

class Bank {
private:
    string name;
    vector<Customer*> customers;

public:
    Bank(const string& n) : name(n) {}

    ~Bank() {
        for (auto c : customers)
            delete c;
    }

    void addCustomer(Customer* c) {
        customers.push_back(c);
    }

    void display(ostream& os) const {
        os << name << endl;
        for (size_t i = 0; i < customers.size(); ++i) {
            os << "\n+ Account #" << i+1 << endl;
            customers[i]->display(os);
        }
    }
};

int main() {
    Bank bank("AGRIBANK");

    Customer* c1 = new Customer("Mickey Mouse");
    c1->addAccount(new SavingsAccount("SAV1234", 15000, 3.5));
    c1->addAccount(new CheckingAccount("CHK1357", 21000, 0.50));

    Customer* c2 = new Customer("Donald Duck");
    c2->addAccount(new CheckingAccount("CHK5678", 24000, 4.20));
    c2->addAccount(new SavingsAccount("SAV2468", 18000, 0.20));

    bank.addCustomer(c1);
    bank.addCustomer(c2);

    c2->getAccounts()[0]->withdraw(5000); // Withdraw from Donald's checking account

    bank.display(cout);

    return 0;
}