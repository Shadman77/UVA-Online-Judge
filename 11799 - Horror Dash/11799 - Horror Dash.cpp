#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //FILE *fp = fopen("test.txt","w");
    ///////////////////
    int testCases, numOfStudent, ans, input;
    cin >> testCases;
    for(int i = 1; i <= testCases; i++)
    {
        ans = 0;
        cin >> numOfStudent;
        for(int j = 0; j < numOfStudent; j++)
        {
            cin >> input;
            if(input > ans)
                ans = input;
        }
        printf("Case %d: %d\n",i,ans);
        //fprintf(fp,"Case %d: %d\n",i,ans);
    }
    //fclose(fp);
    return 0;
}
