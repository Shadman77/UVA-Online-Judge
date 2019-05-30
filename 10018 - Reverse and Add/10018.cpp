#include<cstdio>
#include<iostream>
using namespace std;
long long int a, b, temp;
int testcase, num_of_add;
void rev()
{
    temp = a;
    b = 0;
    while(temp != 0)
    {
        b = (b * 10) + (temp%10);
        temp /= 10;
    }
}
int main()
{
    cin >> testcase;
    while(testcase > 0)
    {
        num_of_add = 0;
        cin >> a;
        rev();
        do
        {
        	a += b;
            rev();
            num_of_add++;
        }
        while(a!=b);
        cout << num_of_add << " " << a << endl;
        testcase--;
    }
}
