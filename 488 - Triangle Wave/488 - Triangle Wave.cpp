#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //FILE * fp = fopen("text.txt","w");
    int testCase;
    int amp, freq;
    cin >> testCase;
    for(int i = 0; i < testCase; i++)
    {
        cin >> amp >> freq;
        for(int j = 0; j < freq; j++)
        {
            for(int k = 1; k <= amp; k++)
            {
                for(int l = 1; l <= k; l++)
                {
                    cout << k;
                    //fprintf(fp,"%d",k);
                }
                cout << endl;
                //fprintf(fp,"\n");
            }
            for(int k = amp - 1; k > 0; k--)
            {
                for(int l = 1; l <= k; l++)
                {
                    cout << k;
                    //fprintf(fp,"%d",k);
                }
                cout << endl;
                //fprintf(fp,"\n");
            }
            if((i == testCase - 1) && (j == freq - 1))
            {

            }
            else{
                cout << endl;
                //fprintf(fp,"\n");
            }
        }
    }
    //fclose(fp);
    return 0;
}
