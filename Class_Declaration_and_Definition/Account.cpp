#include <bits/stdc++.h>

using namespace std;

class Account
{
public: // Thành viên thuộc về giao diện công khai:
    bool init( long = 1111111, const string & = "N/A", double = 0.0 );
    void display() const;
private: // Thành viên thuộc giao diện riêng tư, được bảo vệ:
    long code; // mã tài khoản
    string name; // tên chủ tài khoản
    double balance; // tiền trong tài khoản
};

bool Account::init(long c, const string& s, double b) 
{ 
    if (s.empty()) 
        return false; 

    code = c; 
    name = s; 
    balance = b; 
    return true; 
} 

// cài đặt phương thức display() hiển thị dữ liệu thành viên 
void Account::display() const 
{ 
    cout << fixed << setprecision(2) 
    << "--------------------------------------\n" 
    << "Account number : " << code << '\n' 
    << "Account holder : " << name << '\n' 
    << "Account balance: " << balance << '\n' 
    << "--------------------------------------\n" 
    << endl; 
} 

int main() 
{ 
    Account account; // trước tiên cần tạo một thể hiện của lớp 

    Account* p = &account; // cũng có thể dùng con trỏ chỉ đến thể hiện của lớp 

    account.init(1234567, "Pitt, Brad", 1963.75); 

    account.display(); // dùng toán tử "." 

    p->display(); // dùng toán tử "->" 

    return 0; 
} 
