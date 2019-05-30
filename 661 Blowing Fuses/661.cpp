#include<cstdio>
#include<iostream>
using namespace std;
int num_of_devices;
long long int capacity,num_of_operations,total_power_use,max_power_use,testcase = 0;
long long int devices_power[25];
int devices_status[25],fuse;
void power_of_devices()
{
    int i;
    for(i=1; i<=num_of_devices; i++)
    {
        scanf("%lld",&devices_power[i]);
    }

}
void status_of_devices_reset()
{
    int i;
    for(i=1; i<=num_of_devices; i++)
    {
        devices_status[i]=0;
    }
}
void ans()
{
    fuse = 0;
    total_power_use=0;
    max_power_use = 0;
    int get_devices_toggled, i;
    for(i=1;i<=num_of_operations;i++)
    {
        scanf("%d",&get_devices_toggled);
        if(devices_status[get_devices_toggled] == 0)
        {
            devices_status[get_devices_toggled] = 1;
            total_power_use += devices_power[get_devices_toggled];
            if(total_power_use > capacity)
                fuse = 1;
            if(total_power_use > max_power_use)
                max_power_use = total_power_use;
        }
        else
        {
            devices_status[get_devices_toggled] = 0;
            total_power_use -= devices_power[get_devices_toggled];
        }
    }
}
void print()
{
    testcase++;
    printf("Sequence %lld\n",testcase);
    if(fuse == 0)
    {
        printf("Fuse was not blown.\n");
        printf("Maximal power consumption was %lld amperes.\n",max_power_use);
    }
    else
    {
        printf("Fuse was blown.\n");
    }
    printf("\n");
}
int main()
{
    while(1)
    {
        scanf("%d %lld %lld",&num_of_devices, &num_of_operations, &capacity);
        if((num_of_devices == 0) && (num_of_operations == 0) && (capacity == 0))
            break;
        power_of_devices();
        status_of_devices_reset();
        ans();
        print();
    }
    return 0;
}
