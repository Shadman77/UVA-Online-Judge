#include <iostream>
using namespace std;
long long int testCases, temp, sum, diff;
int main()
{
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> sum >> diff;
        if((diff > sum)||((sum - diff)%2)!=0)
            cout << "impossible" << endl;
        else
        {
            temp = (sum - diff)/2;
            cout << temp + diff << " " << temp << endl;
        }
    }
    return 0;
}
