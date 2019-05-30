#include<iostream>
using namespace std;
int main()
{
    long long int testcases = 0;
    int m, n;
    char A[120][120];
    int i, j;
    int ans;
    while(1)
    {
        testcases++;
        cin >> m >> n;
        if((m==0)&&(n==0))
            break;
        if(testcases > 1)
            cout << endl;
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                cin >> A[i][j];

        cout << "Field #" << testcases << ":" << endl;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(A[i][j] != '*')
                {
                    ans = 0;
                    if((i-1) >= 0)
                    {
                        if(((j-1) >= 0) && (A[i-1][j-1] == '*'))
                            ans++;
                        if(A[i-1][j] == '*')
                            ans++;
                        if(((j+1) <= (n-1)) && (A[i-1][j+1] == '*'))
                            ans++;
                    }
                    if((i+1) <= (m-1))
                    {
                        if(((j-1) >= 0) && (A[i+1][j-1] == '*'))
                            ans++;
                        if(A[i+1][j] == '*')
                            ans++;
                        if(((j+1) <= (n-1)) && (A[i+1][j+1] == '*'))
                            ans++;
                    }
                    if(((j-1) >= 0) && (A[i][j-1] == '*'))
                        ans++;
                    if(((j+1) <= (n-1)) && (A[i][j+1] == '*'))
                        ans++;
                    cout << ans;
                }
                else
                    cout << "*";

            }
            cout << endl;
        }

    }
}
