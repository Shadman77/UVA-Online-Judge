#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string in;
long long int seconds;
int ht, mt, st, ho, mo, so;
double dis;
int speed;
int main()
{
	dis = 0;
	seconds = 0;
	ho=0;
	mo=0;
	so=0;
	while(getline(cin, in))
	{
		ht = stoi(in.substr(0,2));
		mt = stoi(in.substr(3,2));
		st = stoi(in.substr(6,2));
		seconds = ((ht-ho)*3600) + ((mt-mo)*60) + (st-so);
		ho=ht;
		mo=mt;
		so=st;
		dis += ((double)(speed * seconds) / 3600);
		if(in.length()>8){
			speed = stoi(in.substr(8));
		}
		else
		{
			cout << in; 
			printf(" %.2lf km\n",dis);
		}
	}
}
