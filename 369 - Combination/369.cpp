#include<cstdio>
using namespace std;
int n_things, m_at_a_time;
long long int arry[100][100];
void calculate()
{
    int i,j;
    arry[0][0] = 1;
    for(i=1;i<=100;i++)
    {
        arry[i][0] = 1;
        for(j=1;j<i;j++)
        {
            arry[i][j] = arry[i-1][j-1] + arry[i-1][j];
        }
        arry[i][i] = 1;
    }
}
int main()
{
    /*FILE *f = fopen("file.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }*/
    calculate();
    while(1)
    {
        scanf("%d %d", &n_things, &m_at_a_time);
        if((n_things == 0) && (m_at_a_time == 0))
            break;
        //fprintf(f,"%d things taken %d at a time is %lld exactly.\n",n_things,m_at_a_time,arry[n_things][m_at_a_time]);
        printf("%d things taken %d at a time is %lld exactly.\n",n_things,m_at_a_time,arry[n_things][m_at_a_time]);
    }
    //fclose(f);
    return 0;
}
