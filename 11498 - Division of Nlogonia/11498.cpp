#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //FILE *f = fopen("f.txt", "w");
    int query,m,n,x,y;
    int i;
    while(1)
    {
        cin >> query;
        if(query == 0)
            break;
        cin >> m >> n;
        for(i = 1; i <= query; i++)
        {
            cin >> x >> y;
            if((m==x)||(y==n))
                //cout << "divisa" << endl;
                printf("divisa\n");
            else if(x>m)
            {
                if(y>n)
                    //cout << "NE" << endl;
                    printf("NE\n");
                else
                    //cout << "SE" << endl;
                    printf("SE\n");
            }
            else
            {
                if(y>n)
                    //cout << "NO" << endl;
                    printf("NO\n");
                else
                    //cout << "SO" << endl;
                    printf("SO\n");
            }
        }

    }
    //fclose(f);
    return 0;
}
