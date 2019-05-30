#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> input;
    int temp;
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&temp);
            input.push_back(temp);
        }
        sort(input.begin(), input.end());
        for(int i = 0; i < n - 1; i++)
        {
            printf("%d ",input[i]);
        }
        printf("%d\n",input[n-1]);
        input.clear();
    }
    return 0;
}
