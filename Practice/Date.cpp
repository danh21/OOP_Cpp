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
        oss << setw(2) << setfill('0') << day   << "/"
            << setw(2) << setfill('0') << month << "/"
            << year;
        return oss.str();
    }

    inline bool isLess(const Date& d) const {
        if (year != d.year)   return year < d.year;
        if (month != d.month) return month < d.month;
        return day < d.day;
    }
};

void printTest(const string& title, const Date& d) {
    cout << title << " -> " << d.toString() << "\n";
}

int main()
{
    cout << "===== BASIC INCREMENT =====\n";
    Date d1(15, 3, 2025);
    ++d1;
    printTest("15/03/2025 +1 day", d1);   // 16/03/2025


    cout << "\n===== END OF 31-DAY MONTH =====\n";
    Date d2(31, 1, 2025);
    ++d2;
    printTest("31/01/2025 +1 day", d2);   // 01/02/2025


    cout << "\n===== END OF 30-DAY MONTH =====\n";
    Date d3(30, 4, 2025);
    ++d3;
    printTest("30/04/2025 +1 day", d3);   // 01/05/2025


    cout << "\n===== FEB NORMAL YEAR =====\n";
    Date d4(28, 2, 2025);   // 2025 không nhuận
    ++d4;
    printTest("28/02/2025 +1 day", d4);   // 01/03/2025


    cout << "\n===== FEB LEAP YEAR =====\n";
    Date d5(28, 2, 2024);   // 2024 nhuận
    ++d5;
    printTest("28/02/2024 +1 day", d5);   // 29/02/2024
    ++d5;
    printTest("29/02/2024 +1 day", d5);   // 01/03/2024


    cout << "\n===== END OF YEAR =====\n";
    Date d6(31, 12, 2025);
    ++d6;
    printTest("31/12/2025 +1 day", d6);   // 01/01/2026


    cout << "\n===== PREFIX VS POSTFIX =====\n";
    Date d7(1, 1, 2025);
    Date old = d7++;
    printTest("Returned from postfix", old);  // 01/01/2025
    printTest("Original after postfix", d7);  // 02/01/2025


    cout << "\n===== isLess TEST =====\n";
    Date a(1,1,2025);
    Date b(2,1,2025);
    cout << "01/01/2025 < 02/01/2025 ? "
              << (a.isLess(b) ? "true" : "false") << "\n";


    cout << "\n===== INVALID DATE TEST =====\n";
    Date invalid(31, 2, 2025);  // invalid -> fallback default
    printTest("Invalid 31/02/2025", invalid);

    return 0;
}