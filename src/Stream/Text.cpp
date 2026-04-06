#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream inf ( "src/Stream/test.txt" ); // default: input mode, equivalent to ios::in
    ofstream outf ( "src/Stream/copy-test.txt" ); // create ofstream to write

    if ( !inf || !outf ) // overloaded operator! checks whether the stream object exists
    {
        cout << "Open file error!" << endl;
        return -1;
    }

    while ( inf && outf )
    {
        string s;
        getline( inf, s ); // getline() does not include the '\n' character
        outf << s + '\n'; // file operations are stream operations
    }
    cout << "Copy completed ..." << endl;

    return 0;
}
