#include <iostream>
#include <map>
#include<cstdio>
using namespace std;

int numOfStudents, temp;
int j;
long long int testCases;
double ans;
map<int, int> grades;
pair<map<int,int>::iterator,bool> gradesIterator;

int main()
{
    cin >> testCases;
    for(long long int i = 0; i < testCases; i++)
    {
        grades.clear();
        cin >> numOfStudents;
        ////////////////////////////
        for(j = 0; j < numOfStudents; j++)
        {
            cin >> temp;
            gradesIterator = grades.insert(make_pair(temp, 1));
            if(gradesIterator.second == false)
            {
                gradesIterator.first->second += 1;
            }
        }
        /////////////////////////////
        temp = 0;
        for(gradesIterator.first = grades.begin(); gradesIterator.first != grades.end(); gradesIterator.first++)
        {
            temp += (gradesIterator.first->first * gradesIterator.first->second);
        }
        ////////////////////////////
        temp /= numOfStudents;//Average
        ////////////////////////////
        j = 0;
        for(gradesIterator.first = grades.begin(); gradesIterator.first != grades.end(); gradesIterator.first++)
        {
            if(gradesIterator.first->first > temp)
                j += gradesIterator.first->second;
        }
        ////////////////////////////
        ans = (double)j/numOfStudents*100;
        printf("%.3lf%%\n",ans);
    }
    return 0;
}
