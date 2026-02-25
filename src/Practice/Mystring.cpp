#include <bits/stdc++.h>
using namespace std;

class MyString {
private:
    char* s;
    int length;

public:
    /* ===== constructor ===== */
    MyString(const char* const str = "") {
        length = strlen(str);
        s = new char[length + 1];
        strcpy(s, str);
    }

    MyString(const MyString& o) {
        length = o.length;
        s = new char[length + 1];
        strcpy(s, o.s);
    }

    /* ===== destructor ===== */
    ~MyString() {
        delete[] s;
    }

    /* ===== assignment ===== */
    const MyString& operator=(const MyString& right) {
        if (this == &right)
            return *this;

        delete[] s;

        length = right.length;
        s = new char[length + 1];
        strcpy(s, right.s);

        return *this;
    }

    /* ===== + ===== */
    MyString operator+(const MyString& right) const {
        int newLen = length + right.length;
        char* buffer = new char[newLen + 1];

        strcpy(buffer, s);
        strcat(buffer, right.s);

        MyString temp(buffer);
        delete[] buffer;

        return temp;
    }

    /* ===== += ===== */
    const MyString& operator+=(const MyString& right) {
        *this = *this + right;
        return *this;
    }

    /* ===== ! ===== */
    bool operator!() const {
        return length == 0;
    }

    /* ===== ==, != ===== */
    bool operator==(const MyString& right) const {
        return strcmp(s, right.s) == 0;
    }

    bool operator!=(const MyString& right) const {
        return !(*this == right);
    }

    /* ===== < ===== */
    bool operator<(const MyString& right) const {
        return strcmp(s, right.s) < 0;
    }

    /* ===== [] ===== */
    char& operator[](int i) {
        return s[i];          // lvalue
    }

    char operator[](int i) const {
        return s[i];          // rvalue
    }

    /* ===== substring operator() ===== */
    MyString operator()(int i, int n = 0) const {
        if (i < 0 || i >= length)
            return MyString("");

        if (n == 0 || i + n > length)
            n = length - i;

        char* buffer = new char[n + 1];
        strncpy(buffer, s + i, n);
        buffer[n] = '\0';

        MyString temp(buffer);
        delete[] buffer;
        return temp;
    }

    /* ===== cast operator ===== */
    operator char*() const {
        return s;
    }

    /* ===== friend I/O ===== */
    friend ostream& operator<<(ostream& os, const MyString& right) {
        os << right.s;
        return os;
    }

    friend istream& operator>>(istream& is, MyString& right) {
        char buffer[1000];
        is >> buffer;
        right = MyString(buffer);
        return is;
    }

    friend MyString operator+(const char* left, const MyString& right) {
        return MyString(left) + right;
    }
};

int main()
{
    MyString s1, s2("Computer ");
    MyString s3("Science");

    if (!s1) cout << "s1 is empty" << endl;
    else cout << "s1: \"" << s1 << "\"" << endl;

    cout << "s2: \"" << s2 << "\"" << endl;
    cout << "s3: \"" << s3 << "\"" << endl;

    cout << "s1 = s2 + s3: \"" << (s1 = s2 + s3) << "\"" << endl;

    cout << "s1(0, 8): \"" << s1(1, 9) << "\"" << endl;
    
    s2[0] = s2[7];
    cout << "s2[0] = s2[7]: \"" << s2 << "\"" << endl;
    
    cout << "s1 += \" \" + s1: \"" << (s1 += " " + s1) << "\"" << endl;
    
    cout << "s2 < s3 is " << boolalpha << (s2 < s3) << endl;
    
    MyString *p = new MyString(s3);
    cout << "p -> s3: \"" << *p << "\"" << endl;

    return 0;
}