#include <bits/stdc++.h>
using namespace std;

class Clock {
    int hour, minute, second;
public:
    Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // hh:mm:ss
    Clock(const string &timeStr) {
        vector<int> time = tokenize(timeStr, ':');
        hour = time[0];
        minute = time[1];
        second = time[2];
    }

    // n: total of seconds
    Clock(long n) {
        hour = n / 3600;
        int remaining = n % 3600;
        minute = remaining / 60;
        second = remaining % 60;
    }

    Clock(const Clock &o) {
        hour = o.hour;
        minute = o.minute;
        second = o.second;
    }

    // Setter
    void setTime(int h, int m, int s) {
        hour   = (0 <= h && h < 24) ? h : 0;
        minute = (0 <= m && m < 60) ? m : 0;
        second = (0 <= s && s < 60) ? s : 0;
    }

    // Getter (read-only)
    void getTime(int& h, int& m, int& s) const {
        h = hour;
        m = minute;
        s = second;
    }

    // Business methods
    void incrementSeconds() {
        second++;
        if (second == 60) {
            second = 0;
            incrementMinutes();
        }
    }

    void incrementMinutes() {
        minute++;
        if (minute == 60) {
            minute = 0;
            incrementHours();
        }
    }

    void incrementHours() {
        hour++;
        if (hour == 24) {
            hour = 0;
        }
    }

    void print() const {
        cout << setfill('0') 
            << setw(2) << hour   << ":"
            << setw(2) << minute << ":"
            << setw(2) << second << "\n";
    }

    // extract hh:mm:ss
    vector<int> tokenize(string s, char d) {
        vector<int> result;
        stringstream ss(s);
        string token;

        while (getline(ss, token, d)) {
            result.push_back(stoi(token));
        }

        return result;
    }
};

int main()
{
    // pass by value
    Clock c1(10,37,20);
    c1.incrementHours();
    c1.print();

    // pass by string
    Clock c2("1:7:59");
    c2.incrementSeconds();
    c2.print();

    // pass second
    Clock c3("23:59:59");
    c3.incrementMinutes();
    c3.print();

    return 0;
}