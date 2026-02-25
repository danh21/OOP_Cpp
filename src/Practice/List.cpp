#include <bits/stdc++.h>
using namespace std;

class Date {
    int day;    
    int month;
    int year;

public:
    /* ===== constructor ===== */
    Date(int d = 1, int m = 1, int y = 1970) {
        setDate(d,m,y);
    }

    /* ===== accessor ===== */
    void setDate() {    // default
        day = 1;
        month = 1;
        year = 1970;
    }   

    void setDate(const Date& r) {
        day = r.day;
        month = r.month;
        year = r.year;
    }

    void setDate(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            setDate(); // default
        }
    }

    int getDay()   const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear()  const {
        return year;
    }

    /* ===== operator ===== */
    // prefix ++d
    const Date& operator++() {
        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (month == 2 && isLeapYear(year)) {
            if (day < 29) {
                day++;
                return *this;
            }
        } else {
            if (day < daysInMonth[month - 1]) {
                day++;
                return *this;
            }
        }

        // exceed max day in that month -> reset
        day = 1;

        if (month < 12) {
            month++;
        } else {
            month = 1;
            year++;
        }

        return *this;
    }  

    // postfix d++
    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }     

    /* ===== utility ===== */
    inline bool isLeapYear(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    inline bool isValid(int d, int m, int y) {
        if (y < 1 || m < 1 || m > 12 || d < 1)
            return false;

        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (m == 2 && isLeapYear(y))
            return d <= 29;

        return d <= daysInMonth[m - 1];
    }

    /* ===== business ===== */
    string toString() const {
        ostringstream oss;
        oss << setw(2) << setfill('0') << day   << "-"
            << setw(2) << setfill('0') << month << "-"
            << year;
        return oss.str();
    }

    inline bool isLess(const Date& d) const {
        if (year != d.year)   return year < d.year;
        if (month != d.month) return month < d.month;
        return day < d.day;
    }
};

class Node {
private:
    Date date;
    double amount;
    Node* next;

public:
    Node(const Date& d, double a)
        : date(d), amount(a), next(NULL) {}

    const Date& getDate() const { return date; }

    void setDate(const Date& d) { date = d; }

    double getAmount() const { return amount; }

    void setAmount(double a) { amount = a; }

    Node* getNext() const { return next; }

    friend class List;

    friend ostream& operator<<(ostream& os, const Node& node) {
        os << "[" << node.date.toString()
           << " Amount: "
           << fixed << setprecision(2)
           << node.amount << "]";
        return os;
    }
};

class List {
private:
    Node* first;
    Node* last;

public:
    List() : first(NULL), last(NULL) {}

    ~List() {
        while (first) {
            removeFirst();
        }
    }

    Node* head() const { return first; }
    Node* tail() const { return last; }

    void insertLast(const Date& d, double a) {
        Node* p = new Node(d, a);

        if (!first) {
            first = last = p;
        } else {
            last->next = p;
            last = p;
        }
    }

    void removeFirst() {
        if (!first) return;

        Node* oldFirst = first;
        first = first->next;

        if (!first)
            last = NULL;

        delete oldFirst;
    }

    friend ostream& operator<<(ostream& os, const List& list) {
        Node* p = list.first;
        while (p) {
            os << *p << endl;
            p = p->next;
        }
        return os;
    }
};

int main()
{
    List list;

    while (true) {
        string input;
        cout << "Date format Day-Month-Year: ";
        cin >> input;

        if (input == "q")
            break;

        int d, m, y;
        sscanf(input.c_str(), "%d-%d-%d", &d, &m, &y);

        double amount;
        cout << "Account change: ";
        cin >> amount;

        list.insertLast(Date(d,m,y), amount);
    }

    cout << "Content of the list:\n";
    cout << list;

    cout << "Removing the first node of the list:\n";
    list.removeFirst();

    cout << "Content of the list:\n";
    cout << list;

    cout << "Increasing date of the first node:\n";
    if (list.head())
        const_cast<Date&>(list.head()->getDate())++;

    cout << "Content of the list:\n";
    cout << list;

    cout << "Insert new node\n";
    list.insertLast(Date(21,12,2001), 100.5);

    cout << "Content of the list:\n";
    cout << list;

    return 0;
}