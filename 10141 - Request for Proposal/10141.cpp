#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    string input, accepted, buffer;
    int num_of_requirement, num_of_proposals;
    int requirements_meet = 0;
    double price = -1;
    int requirements_meet_temp;
    double price_temp;
    int i,j,testcase = 1;
    //FILE *f = fopen("file.txt","w");
    while(1)
    {
        scanf("%d %d", &num_of_requirement, &num_of_proposals);
        cin.ignore();
        if((num_of_proposals==0)&&(num_of_requirement==0))
            break;
        for(i = 0; i < num_of_requirement; i++){
            getline(cin,input);
            //cin.ignore();
            //cout << input;
            //printf("------1\n");
        }
        for(i=0; i<num_of_proposals; i++)
        {
            getline(cin,input);
            //printf("--------------1.5\n");
            scanf("%lf %d",&price_temp, &requirements_meet_temp);
            cin.ignore();
            //printf("-------------2\n");
            for(j=0; j<requirements_meet_temp; j++){
                getline(cin,buffer);
                //printf("------------3\n");
            }
            if(price == -1)
            {
                price = price_temp;
                requirements_meet = requirements_meet_temp;
                accepted = input;
            }
            else if(requirements_meet_temp > requirements_meet)
            {
                price = price_temp;
                requirements_meet = requirements_meet_temp;
                accepted = input;
            }
            else if(requirements_meet == requirements_meet_temp)
            {
                if(price_temp < price)
                {
                    price = price_temp;
                    requirements_meet = requirements_meet_temp;
                    accepted = input;
                }
            }
        }
        if(testcase>1)
            printf("\n");
        printf("RFP #%d\n",testcase);
        testcase++;
        cout << accepted;
        cout << "\n";
        price = -1;

    }
    //fclose(f);
    return 0;
}
