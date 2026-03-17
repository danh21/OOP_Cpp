#include <bits/stdc++.h>

using namespace std;

size_t _strlen( const char *str )
{
    const char* p = str;
    while ( *p ) ++p;
    return ( p - str );
}

// compare len characters of string s1 with s2
int _strncmp( const char *s1, const char *s2, size_t len )
{
    if ( len > _strlen( s1 ) ) len = _strlen( s1 );
    if ( len > _strlen( s2 ) ) len = _strlen( s2 );
    for ( int i = 0; i < len; ++i )
    if ( s1[i] != s2[i] ) return 1;
    return 0;
}

// find string s2 in string s1
char* _strstr( const char *s1, const char *s2 )
{
    size_t len = _strlen( s2 );
    for ( ; *s1 != '\0'; ++s1 )
        if ( _strncmp( s1, s2, len ) == 0 )
            return ( char * )s1;
    return NULL;
}

// return the positions of s2 in s1
int main()
{
    char* s = "hom qua qua khong qua";
    char* p = s;
    while ( ( p = _strstr( p, "qua" ) ) != NULL )
    {
        std::cout << p - s << ' ';
        p++;
    }
    return 0;
}