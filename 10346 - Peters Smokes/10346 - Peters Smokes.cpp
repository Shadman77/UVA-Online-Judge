#include<iostream>
using namespace std;
int main()
{
    int n,k,remainder,temp1, temp2;
    long long int sum;
    while(cin >> n >> k)
    {
        sum = n;
        remainder = n;
        //cout << n <<" " << k << endl;
        while(remainder >= k)
        {
            temp2 = remainder%k;
            temp1 = remainder/k;
            sum += temp1;
            remainder = temp1 + temp2;
            //cout << "remainder = " << remainder << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
