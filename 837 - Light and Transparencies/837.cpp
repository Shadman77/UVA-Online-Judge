#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
Both linked list systems seems to work properly.
*/
struct sorted_coordinate
{
    double coordinate;
    struct sorted_coordinate *next;
};

struct glass
{
    double coefficient;
    double low;
    double high;
    struct glass *next;
};

struct sorted_coordinate *sorted_coordinate_header = NULL, *sorted_coordinate_avail = NULL; //global head
struct glass *glass_header = NULL, *glass_avail = NULL; //global head
////////////////////////////////////////////////////////////////////

void push_sorted_coordinate_util(struct sorted_coordinate *node_ptr, double value)
{
    if ((node_ptr->next == NULL) || (node_ptr->next->coordinate >= value))
    {
        struct sorted_coordinate *new_node;
        if (sorted_coordinate_avail == NULL)
            new_node = (struct sorted_coordinate*) malloc(sizeof (struct sorted_coordinate));
        else
        {
            new_node = sorted_coordinate_avail;
            sorted_coordinate_avail = sorted_coordinate_avail->next;
        }
        new_node->coordinate = value;
        new_node->next = node_ptr->next;
        node_ptr->next = new_node;
    }
    else
    {
        push_sorted_coordinate_util(node_ptr->next, value);
    }
}

void push_sorted_coordinate(double value)//send the start of the list here
{
    if ((sorted_coordinate_header == NULL) || (sorted_coordinate_header->coordinate >= value))
    {
        struct sorted_coordinate *new_node;
        if (sorted_coordinate_avail == NULL)
            new_node = (struct sorted_coordinate*) malloc(sizeof (struct sorted_coordinate));
        else
        {
            new_node = sorted_coordinate_avail;
            sorted_coordinate_avail = sorted_coordinate_avail->next;
        }
        new_node->coordinate = value;
        if (sorted_coordinate_header == NULL)
            new_node->next = NULL;
        else
            new_node->next = sorted_coordinate_header;
        sorted_coordinate_header = new_node;
    }
    else
    {
        push_sorted_coordinate_util(sorted_coordinate_header, value);
    }
}
//////////////////////////////////////////////////////////////////////

void push_glass_util(double coefficient, double low, double high)
{
    struct glass *current, *new_node;
    if (glass_avail == NULL)
        new_node = (struct glass*) malloc(sizeof (struct glass));
    else
    {
        new_node = glass_avail;
        glass_avail = glass_avail->next;
    }
    current = new_node;
    //printf("69\n");
    current->next = glass_header;
    //printf("71\n");
    while (current->next != NULL)
    {
        current = current->next;
    }
    //printf("75\n");
    new_node->next = NULL;
    current->next = new_node;
    new_node->low = low;
    new_node->high = high;
    new_node->coefficient = coefficient;
}
void push_glass(double coefficient, double low, double high)
{
    if(glass_header == NULL)
    {
        struct glass *new_node;
        if (glass_avail == NULL)
            new_node = (struct glass*) malloc(sizeof (struct glass));
        else
        {
            new_node = glass_avail;
            glass_avail = glass_avail->next;
        }
        new_node->coefficient = coefficient;
        new_node->low = low;
        new_node->high = high;
        new_node->next = NULL;
        glass_header = new_node;
    }
    else
        push_glass_util(coefficient,low, high);
}
double find_coefficient(double low, double high)
{
    //printf("\n");
    double ans = 1;
    struct glass *glass_node = glass_header;
    while(glass_node!=NULL)
    {
        //printf("%lf %lf %lf %lf %lf\n", low, glass_node->low, high, glass_node->high, glass_node->coefficient);
        if((low>=glass_node->low)&&(high<=glass_node->high))
        {
            ans *= glass_node->coefficient;
            //printf("ans = %lf\n",ans);
        }
        glass_node=glass_node->next;
    }
    return ans;
    //printf("\n");
}
void print_answer()
{
    double total_coefficient;
    struct sorted_coordinate *sorted_coordinate_x1 = sorted_coordinate_header, *sorted_coordinate_x2 = sorted_coordinate_header->next;
    struct glass *glass_node = glass_header;
    printf("-inf %.3lf 1.000\n",sorted_coordinate_x1->coordinate);
    while(sorted_coordinate_x2 != NULL)
    {
        total_coefficient = find_coefficient(sorted_coordinate_x1->coordinate, sorted_coordinate_x2->coordinate);
        printf("%.3lf %.3lf %.3lf\n",sorted_coordinate_x1->coordinate, sorted_coordinate_x2->coordinate, total_coefficient);
        sorted_coordinate_x1 = sorted_coordinate_x2;
        sorted_coordinate_x2 = sorted_coordinate_x2->next;
    }
    printf("%.3lf +inf 1.000\n",sorted_coordinate_x1->coordinate);
}
int main()
{
    double x1,x2,y1,y2,coefficient;
    int testcases, i,j,num_of_glasses;
    scanf("%d",&testcases);
    for(i=1; i<=testcases; i++)
    {
        scanf("%d",&num_of_glasses);
        for(j=1; j<=num_of_glasses; j++)
        {
            scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &coefficient);
            if(x1 < x2)
                push_glass(coefficient,x1,x2);
            else
                push_glass(coefficient,x2,x1);
            push_sorted_coordinate(x1);
            push_sorted_coordinate(x2);
        }
        printf("%d\n",num_of_glasses*2+1);
        struct glass *glass_node = glass_header;
        print_answer();
        if(i<testcases)
            printf("\n");//this wont be at the last output
        glass_avail = glass_header;//this is the last action of each test case
        sorted_coordinate_avail = sorted_coordinate_header;//this is the last action of each test case
        glass_header = NULL;
        sorted_coordinate_header = NULL;
    }
}
