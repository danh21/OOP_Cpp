#include <bits/stdc++.h>

using namespace std;

class X
{
    friend ostream& operator<<(ostream& o, const X& x) {
        return (o << x.n << endl);
    }
private:
    int n;
public:
    X(int val) : n(val) {}
    int& value() {
        return n;
    }
};

class X_ptr {
private:
    X *ptr;
public:
    X_ptr(X *p) : ptr(p) {}
    
    X_ptr operator+(int i) {
        return X_ptr(ptr + i);
    }
    
    X* operator->() {
        return ptr;
    }
    
    X_ptr operator++(int) {
        X_ptr temp(ptr);
        ptr++;
        return temp;
    }
    
    X operator*() {
        return *ptr;
    }
    
    // int operator-(const X *x) {
    //     return ptr - x; 
    // }
    
    int operator-(const X_ptr& x) {
        return ptr - x.ptr; 
    }
};

int main()
{
    int i;
    X a[3] = { X( 1 ), X( 2 ), X( 3 ) };
    X_ptr p = a;
    
    for ( i = 0; i < 3; ++i ) // phép cộng con trỏ, dùng toán tử truy xuất thành viên
        ( p + i )->value() += i; // cập nhật trị cho đối tượng được chỉ bởi con trỏ
        
    for ( i = 0; i < 3; ++i )
        cout << *p++; // tăng con trỏ lên 1, rồi dùng toán tử dereference
        
    cout << "\nNumber of element: "
    << p - a << endl; // phép trừ hai con trỏ, trả về số phần tử giữa hai con trỏ

    return 0;
}