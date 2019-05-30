#include<iostream>
using namespace std;
int f91(int n)
{
    if(n >= 101)
        return n - 10;
    else
        return f91(f91(n+11));
}
int main()
{
    int temp;
    while(1)
    {
        cin >> temp;
        if(temp == 0)
            break;

        cout << "f91(" << temp << ") = " << f91(temp) << endl;
    }
    return 0;
}
