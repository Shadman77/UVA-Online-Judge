#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int a, b, c;
    long long int ans;
    int testcase, farmers;
    int i, j;
    cin >> testcase;
    for(i=0; i<testcase; i++)
    {
        ans = 0;
        cin >> farmers;
        for(j=0;j<farmers;j++)
        {
            cin >> a >> b >> c;
            ans += (a*c);
        }
        cout << ans << endl;
    }
    return 0;
}
