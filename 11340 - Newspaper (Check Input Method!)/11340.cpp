#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
char input[10200];
int num_of_line, testcase, testcase_counter, num_of_letter, counter1, length, counter2;
long long int cents, total;
map<char, long long int> table;
map<char,long long int>::iterator it;
void make_table()
{
    table.clear();
    char c;
    for(counter1 = 0; counter1 < num_of_letter; counter1++)
    {
        scanf("%c%lld ",&c ,&cents);
        table.insert(make_pair(c, cents));
    }
}
void calculate_total()
{
    length = strlen(input);
    for(counter1 = 0; counter1 < length; counter1++)
    {
        it = table.find(input[counter1]);
        if(it != table.end())
            total += it->second;
    }
}
void scan_line()
{
    total = 0;
    for(counter2 = 0; counter2 < num_of_line; counter2++)
    {
        gets(input);//This is where I made the change!
        calculate_total();
    }
}
int main()
{
    scanf("%d ",&testcase);
    for(testcase_counter = 1; testcase_counter <= testcase; testcase_counter++)
    {
        scanf("%d ", &num_of_letter);
        make_table();
        scanf("%d ", &num_of_line);
        scan_line();
        cents = total%100;
        total /= 100;
        printf("%lld.%02lld$\n",total,cents);
    }
    return 0;
}
