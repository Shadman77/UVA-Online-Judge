#include<cstdio>
#include<cstring>
using namespace std;
char names[12][15], temp_name[15];
int money_of_person[12], num_of_people, giving_to, money_temp, money_each_person,testcase=0;
void set_index()
{
    int i;
    for(i=0; i<num_of_people; i++)
    {
        money_of_person[i] = 0;
    }
}
void deduct_money()
{
    int i, deducted;
    for(i=0; i<num_of_people; i++)
    {
        if(strcmp(temp_name,names[i])==0)
            break;
    }
    if(money_temp > 0)
    {
        if(giving_to > 0)
            money_each_person = money_temp/giving_to;
        deducted = money_each_person * giving_to;
        money_of_person[i] = money_of_person[i] - deducted;
    }
    else
        money_each_person = 0;
}
void add_money()
{
    int i;
    for(i=0; i<num_of_people; i++)
    {
        if(strcmp(temp_name,names[i])==0)
        {
            money_of_person[i] += money_each_person;
            break;
        }
    }
}
void result()
{
    int i,j;
    for(i = 0; i < num_of_people; i++)
    {
        scanf("%s %d %d",temp_name, &money_temp, &giving_to);
        deduct_money();
        for(j=0; j<giving_to; j++)
        {
            scanf("%s",temp_name);
            add_money();
        }
    }
}
void print()
{
    int i;
    for(i = 0; i < num_of_people; i++)
    {
        printf("%s %d\n",names[i],money_of_person[i]);
    }
}
int main()
{
    int i;
    while(scanf("%d",&num_of_people)==1)
    {
        if(testcase>0)
            printf("\n");
        set_index();
        for(i=0; i<num_of_people; i++)
        {
            scanf("%s",names[i]);
        }
        result();
        print();
        testcase++;
    }
    return 0;
}
