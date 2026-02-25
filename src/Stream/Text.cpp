#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream inf ( "Stream/test.txt" ); // mặc định: chế độ cập nhật, tương đương ios::in | ios::out
    ofstream outf ( "Stream/copy-test.txt" ); // tạo ofstream để ghi

    if ( !inf || !outf ) // nạp chồng toán tử ! kiểm tra đối tượng stream có tồn tại không
    {
        cout << "Open file error!" << endl;
        return -1;
    }

    while ( inf && outf )
    {
        string s;
        getline( inf, s ); // getline() không nhận ký tự '\n'
        outf << s +'\n'; // thao tác trên tập tin chính là thao tác trên stream
    }
    cout << "Copy completed ..." << endl;

    return 0;
}
