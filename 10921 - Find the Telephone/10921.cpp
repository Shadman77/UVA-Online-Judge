#include<iostream>
#include<cstdio>
using namespace std;
int index[26];
void setup()
{
    index['A'%26] = 2;
    index['B'%26] = 2;
    index['C'%26] = 2;

    index['D'%26] = 3;
    index['E'%26] = 3;
    index['F'%26] = 3;

    index['G'%26] = 4;
    index['H'%26] = 4;
    index['I'%26] = 4;

    index['J'%26] = 5;
    index['K'%26] = 5;
    index['L'%26] = 5;

    index['M'%26] = 6;
    index['N'%26] = 6;
    index['O'%26] = 6;

    index['P'%26] = 7;
    index['Q'%26] = 7;
    index['R'%26] = 7;
    index['S'%26] = 7;

    index['T'%26] = 8;
    index['U'%26] = 8;
    index['V'%26] = 8;

    index['W'%26] = 9;
    index['X'%26] = 9;
    index['Y'%26] = 9;
    index['Z'%26] = 9;
}
int main()
{
    setup();
    char c;
    while(scanf("%c",&c)==1)
    {
        if((c >= 'A')&&(c <= 'Z'))
            cout << index[c%26];
        else
            cout << c;
    }
    return 0;
}
