#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    map<string, int> map_of_country;
    pair<map<string, int>::iterator, bool> it;
    string country;
    char buffer[100];
    int testcases, i;
    cin >> testcases;
    for(i=0;i<testcases;i++)
    {
        cin >> country;
        scanf(" %[^\n]",buffer);
        it = map_of_country.insert(make_pair(country, 1));
        if(it.second==false)
            it.first->second = it.first->second + 1;
    }

    for(it.first = map_of_country.begin(); it.first!=map_of_country.end(); it.first++)
        cout << it.first->first << " " << it.first->second << endl;
    return 0;
}
