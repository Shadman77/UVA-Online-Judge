#include<cstdio>
#include<cstring>
using namespace std;
int add(char high[], char low[], int h, int l)
{
    int carry = 0, num_of_carry = 0;
    int a, b, answer;
    l--;
    h--;
    while(l>=0)
    {
        a = high[h] - '0';
        b = low[l] - '0';
        answer = a + b + carry;
        carry = 0;
        if(answer>9)
        {
            carry = 1;
            answer %= 10;
            num_of_carry++;
        }
        l--;
        h--;
    }
    while(h>=0)
    {
        a = high[h] - '0';
        answer = a + carry;
        carry = 0;
        if(answer>9)
        {
            carry = 1;
            answer %= 10;
            num_of_carry++;
        }
        h--;
    }
    return num_of_carry;
}
int main()
{
    //FILE *f = fopen("f.txt","w");
    int l1,l2;
    int ans;
    char a[15], b[15];
    while(1)
    {
        scanf("%s %s",a,b);
        if((strcmp(a,"0")==0)&&(strcmp(b,"0")==0))
            break;
        l1 = strlen(a);
        l2 = strlen(b);
        if(l1>l2)
            ans = add(a,b,strlen(a),strlen(b));
        else
            ans = add(b,a,strlen(b),strlen(a));
        if(ans==0)
            printf("No carry operation.\n");
        else if (ans>1)
            printf("%d carry operations.\n",ans);
        else
            printf("%d carry operation.\n",ans);
    }
    //fclose(f);
    return 0;
}

