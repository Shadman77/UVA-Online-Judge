#include<cstdio>
using namespace std;
char table[128];
////////////////////
void setup()
{
    /*int i;
    for(i = 0; i < 50; i++)
        table[i] = 'a';*/
//////////////////////
    table['1'] = '`';
    table['2'] = '1';
    table['3'] = '2';
    table['4'] = '3';
    table['5'] = '4';
    table['6'] = '5';
    table['7'] = '6';
    table['8'] = '7';
    table['9'] = '8';
    table['0'] = '9';
    table['-'] = '0';
    table['='] = '-';
//////////////////////
    table['W'] = 'Q';
    table['E'] = 'W';
    table['R'] = 'E';
    table['T'] = 'R';
    table['Y'] = 'T';
    table['U'] = 'Y';
    table['I'] = 'U';
    table['O'] = 'I';
    table['P'] = 'O';
    table['['] = 'P';
    table[']'] = '[';
    table['\\'] = ']';
///////////////////////
    table['S'] = 'A';
    table['D'] = 'S';
    table['F'] = 'D';
    table['G'] = 'F';
    table['H'] = 'G';
    table['J'] = 'H';
    table['K'] = 'J';
    table['L'] = 'K';
    table[';'] = 'L';
    table[39] = ';';
///////////////////////
    table['X'] = 'Z';
    table['C'] = 'X';
    table['V'] = 'C';
    table['B'] = 'V';
    table['N'] = 'B';
    table['M'] = 'N';
    table[','] = 'M';
    table['.'] = ',';
    table['/'] = '.';
//////////////////////
}
int main()
{
    setup();
    char c;
    //printf("%d\n",table['`']);
    while(scanf("%c",&c)==1)
    {
        if(table[c] != 0)
        {
            printf("%c",table[c]);
        }
        else
            printf("%c",c);
    }
    return 0;
}
