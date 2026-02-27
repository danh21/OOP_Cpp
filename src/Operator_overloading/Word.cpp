#include <bits/stdc++.h>

using namespace std;

class Word
{
    friend ostream& operator<<(ostream& o, const Word& w) {
        return (o << w.str << endl);
    }
private:
    char* str;
    int len;
public:
    // default ctor for functor
    Word() : str(nullptr), len(0) {}
    
    // COPY CONSTRUCTOR
    Word(const Word& w) {
        // cout << " COPY CONSTRUCTOR\n";
        len = w.len;
        str = new char[len + 1];
        strcpy(str, w.str);
    }
    
    ~Word() {
        delete []str;
    }
    
    Word(const char *s) {
        // cout << "Word(const char *s)\n";
        str = new char[len = strlen(s)+1];
        strcpy(str, s);
    }
    
    Word operator()(int i = 0, int n = 0) {
        i = ( i < 0 ) ? 0 : ( ( i > len ) ? len : i );
        n = ( n < 0 ) ? 0 : ( ( n > len - i ) ? ( len - i ) : n );
        char *s = new char[n+1];
        strncpy(s, str + i, n);
        s[n] = '\0';
        Word res(s);
        delete[] s;
        return res;
    }
    
    void operator()(const Word& w) {
        cout << w;
    }
};

int main()
{
    Word a = "danhphan";
    cout << a(0,4);
    
    std::vector<Word> vWord;
    vWord.push_back(Word("abc daefa"));
    vWord.push_back(Word("abcerfe 45y54h4"));
    for_each(vWord.begin(), vWord.end(), Word());
    
    return 0;
}