#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int buf, testcases, i;
    cin >> testcases;
    for(i=0; i<testcases; i++)
    {
        cin >> buf;
        /*
        \Multiply n
        by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide
        by 47, then subtract 498. What is the digit in the tens column?"
        */
        buf = (((((buf * 567) / 9) + 7492) * 235) / 47) - 498;
        //cout << buf << endl;
        buf /= 10;//eliminating the last digit
        //cout << buf << endl;
        buf %= 10;//getting the last digit which is actually the second last digit
        buf = abs(buf);//absolute value
        cout << buf << endl;
    }
    return 0;
}
