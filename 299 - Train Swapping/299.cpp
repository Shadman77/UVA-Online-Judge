#include<cstdio>
using namespace std;
int train[60], length, bubble_counter1, bubble_counter2, swaps, l_counter;
int if_swapped, temp;
long long int testcase, t_counter;
void exchange()
{
    temp = train[bubble_counter2];
    train[bubble_counter2] = train[bubble_counter2+1];
    train[bubble_counter2+1] = temp;
}
void bubble_sort()
{
    swaps = 0;
    for(bubble_counter1 = 0; bubble_counter1 < length - 1; bubble_counter1++)//n-1 times
    {
        if_swapped = 0;
        for(bubble_counter2 = 0; bubble_counter2 < length - 1 - bubble_counter1; bubble_counter2++)
        {
            if(train[bubble_counter2] > train[bubble_counter2+1])
            {
                exchange();
                swaps++;
                if_swapped++;
            }
        }
        if(if_swapped == 0)
            break;
    }
}
int main()
{
    //FILE *f = fopen("f.txt", "w");
    scanf("%lld",&testcase);
    for(t_counter = 1; t_counter <= testcase; t_counter++)
    {
        scanf("%d",&length);
        for(l_counter = 0; l_counter < length; l_counter++)
            scanf("%d",&train[l_counter]);
        bubble_sort();
        printf("Optimal train swapping takes %d swaps.\n",swaps);
    }
    //fclose(f);
    return 0;
}
