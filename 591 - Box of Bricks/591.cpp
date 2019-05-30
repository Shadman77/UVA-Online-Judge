#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, h;
int minimun, average;
vector<int> v;
vector<int>::iterator it;
bool comp(int i, int j){return (i>j);}
void get_min()
{
    minimun = 0;
    sort(v.begin(),v.end(),comp);
    for(it = v.begin(); *it>average; it++)
        minimun += ( *it - average);
    v.clear();
}
int main()
{
    int i;
    int s = 0;
    cin >> n;
    while(n)
    {
        average = 0;
        s++;
        for(i = 0; i < n; i++)
        {
            cin >> h;
            v.push_back(h);
            average += h;
        }
        average /= n;
        get_min();
        cout << "Set #" << s << endl;
        cout << "The minimum number of moves is " << minimun << "." << endl << endl;
        cin >> n;
    }
    return 0;
}
