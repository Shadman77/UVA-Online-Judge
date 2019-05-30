#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<fstream>
using namespace std;
vector<char> parentheses;
string input;
int test_cases;
char temp;
bool check()
{
    for(int i = 0; i < input.length(); i++)
    {
        //cout << input[i] << endl;
        if(input[i] == '(' || input[i] == '[')
        {
            parentheses.push_back(input[i]);
            //cout << "push" << endl;
        }
        else if(input[i] == ')' || input[i] == ']')
        {
            if(!parentheses.empty())
            {
                if((parentheses.back() == '(' && input[i] == ')')||(parentheses.back() == '[' && input[i] == ']'))
                {
                    //cout << "pop" << endl;
                    parentheses.pop_back();
                }
                else
                    return false;
            }
            else
            {
                //cout << "else" << endl;
                return false;
            }
        }
        //cout << endl;
    }
    if(parentheses.empty())
        return true;
    else
        return false;
}

int main()
{
    /*(())()(])*/
    //FILE *fp = fopen("test.txt", "w");
    //ofstream out("test2.txt");
    getline(cin, input);//need to get the whole line
    test_cases = stoi(input, nullptr, 0);
    for(int i = 0; i < test_cases; i++)
    {
        getline(cin, input);
        //out << i+1 << " " << input << endl;
        parentheses.clear();
        //cout << input << endl << input.length();
        if(check()){
            cout << "Yes" << endl;
            //fprintf(fp,"Yes\n");
        }
        else{
            cout << "No" << endl;
            //fprintf(fp,"No\n");
        }
    }
    //fclose(fp);
    //out.close();
    return 0;
}
