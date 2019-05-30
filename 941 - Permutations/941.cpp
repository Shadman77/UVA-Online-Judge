#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char input[50],temp;
int n, divisor;//n = length
long long int fac[20],nth_term;
int j,k,i,f=1;
void factorial()
{
    if(f<20)
    {
        fac[f] = fac[f-1] * (f+1);
        //printf("fac %d = %lld\n",f+1,fac[f]);//remember that count starts from 0!
        f++;
        factorial();
    }
}
void permute()
{
    if(nth_term > 0) //how to end it when we want?
    {
        j = nth_term/fac[divisor];
        //printf("j = %d, n term = %lld, fac = %lld\n",j, nth_term, fac[divisor]);
        nth_term = nth_term - (fac[divisor] * j);
        divisor--;
        j = j + i;
        temp = input[j];
        for(k=j; k>i; k--)
        {
            input[k] = input[k-1];
        }
        input[i] = temp;//setting the first value
        //printf("input = %s\n\n\n",input);
        i++;
        permute();
    }
    /*else
    {
        //printf("input = %s\n\n\n",input);
        printf("%s\n",input);
        fprintf(f,"%s\n",input);
    }*/
}
int main()
{
    //FILE *fl = fopen("file.txt","w");
    int counter;
    long long int counter2,testcases;
    vector<char> v;
    vector<char>::iterator iter;
    fac[0] = 1;
    factorial();
    scanf("%lld",&testcases);
    for(counter2=0; counter2<testcases; counter2++)
    {
        scanf("%s %lld",input,&nth_term);
        //fprintf(fl,"%s\n%lld\n",input,nth_term);
        n = strlen(input);
        v.assign(input,input+n);
        divisor = n - 2;
        i = 0;
        sort(v.begin(), v.end());
        counter = 0;
        for(iter = v.begin(); iter < v.end(); iter++)
        {
            input[counter] = *iter;
            counter++;
        }
        permute();
        printf("%s\n",input);
        //fprintf(fl,"%s\n",input);
    }
    //sprintf(input,"abcdefghijklmnopqrst");
    //nth_term = 2432902008176639999;
    //fclose(fl);
    return 0;
}
