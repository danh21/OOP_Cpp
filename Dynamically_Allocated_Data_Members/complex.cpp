#include <bits/stdc++.h>

using namespace std;

class Complex
{
    double real, image;
public:
    // dùng constructor có tất cả đối số mặc định như constructor mặc định
    Complex( double a = 0.0, double b = 2.0 ) : real( a ), image( b ) { }
    void display()
    {
        cout << real << " + " << image << "i" << std::endl;
    }
};

int main()
{
    // gọi constructor mặc định cho 5 phần tử của mảng quản lý bởi con trỏ a
    Complex *a = new Complex[5];
    // gọi constructor mặc định cho 1 phần tử của mảng b
    Complex *b = new Complex;

    for ( int i = 0; i < 5; ++i )
        ( a + i )->display();
    b->display();

    return 0;
}