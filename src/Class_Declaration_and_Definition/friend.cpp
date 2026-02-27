#include <bits/stdc++.h>
using namespace std;

class C; // khai báo forward2 do trình biên dịch chưa

class B // biết đến lớp C nhưng cần C khi cài đặt lớp B
{
public:
    int foo( C & );
};



// class C
// {
//     // chỉ định phương thức foo của lớp B là "bạn" của lớp C
//     // cho phép foo của B có thể truy xuất phần private của lớp C
//     friend int B::foo( C & );
// private:
//     int data;
// public:
//     C(int d) : data(d) {}
// };



// tất cả các hàm thành viên của lớp khác đó đều là "bạn" của lớp đang xây dựng.
class C {
    friend class B;
private:
    int data;
public:
    C(int d) : data(d) {}
};



int B::foo(C& obj) {
    return obj.data;
}



int main() {
    C obj(21);
    B b;
    cout << b.foo(obj);
}