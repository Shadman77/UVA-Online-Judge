#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> v;
vector<int>::iterator it1, it2;
int input1, input2;
int n,i,diff_sw;
int main()
{
    while(scanf("%d",&n)==1)
    {
        v.clear();
        if(n==1)
        {
            scanf("%d",&input1);
            printf("Jolly\n");
        }
        else
        {
            scanf("%d",&input1);
            for(i = 1; i < n; i++)
            {
                scanf("%d",&input2);
                diff_sw = abs(input1 - input2);
                v.push_back(diff_sw);
                input1 = input2;
            }
            sort(v.begin(),v.end());
            diff_sw = 0;
            it1 = v.begin();
            if(*it1==1)
            {
                for(it2 = it1 + 1; it2!=v.end(); it2++)
                {
                    if((*it2 - *it1)!=1)
                    {
                        diff_sw = 1;
                        break;
                    }
                    it1++;
                }
            }
            else
                diff_sw = 1;
            if(diff_sw == 0)
                printf("Jolly\n");
            else
                printf("Not jolly\n");
        }
    }
    return 0;
}
