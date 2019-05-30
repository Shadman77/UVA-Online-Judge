#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
map<string, char> code;
map<string, char>::iterator it;
string input, buffer;
int counter, testcases;
//FILE *f;
void set_up()
{
    code.insert(make_pair(".-", 'A'));
    code.insert(make_pair("-...", 'B'));
    code.insert(make_pair("-.-.", 'C'));
    code.insert(make_pair("-..", 'D'));
    code.insert(make_pair(".", 'E'));
    code.insert(make_pair("..-.", 'F'));
    code.insert(make_pair("--.", 'G'));
    code.insert(make_pair("....", 'H'));
    code.insert(make_pair("..", 'I'));
    code.insert(make_pair(".---", 'J'));
    code.insert(make_pair("-.-", 'K'));
    code.insert(make_pair(".-..", 'L'));
    code.insert(make_pair("--", 'M'));
    code.insert(make_pair("-.", 'N'));
    code.insert(make_pair("---", 'O'));
    code.insert(make_pair(".--.", 'P'));
    code.insert(make_pair("--.-", 'Q'));
    code.insert(make_pair(".-.", 'R'));
    code.insert(make_pair("...", 'S'));
    code.insert(make_pair("-", 'T'));
    code.insert(make_pair("..-", 'U'));
    code.insert(make_pair("...-", 'V'));
    code.insert(make_pair(".--", 'W'));
    code.insert(make_pair("-..-", 'X'));
    code.insert(make_pair("-.--", 'Y'));
    code.insert(make_pair("--..", 'Z'));
    ////////////////////////////////////
    code.insert(make_pair("-----", '0'));
    code.insert(make_pair(".----", '1'));
    code.insert(make_pair("..---", '2'));
    code.insert(make_pair("...--", '3'));
    code.insert(make_pair("....-", '4'));
    code.insert(make_pair(".....", '5'));
    code.insert(make_pair("-....", '6'));
    code.insert(make_pair("--...", '7'));
    code.insert(make_pair("---..", '8'));
    code.insert(make_pair("----.", '9'));
    ////////////////////////////////////
    code.insert(make_pair(".-.-.-", '.'));
    code.insert(make_pair("--..--", ','));
    code.insert(make_pair("..--..", '?'));
    code.insert(make_pair(".----.", 39));
    code.insert(make_pair("-.-.--", '!'));
    code.insert(make_pair("-..-.", '/'));
    code.insert(make_pair("-.--.", '('));
    code.insert(make_pair("-.--.-", ')'));
    code.insert(make_pair(".-...", '&'));
    code.insert(make_pair("---...", ':'));
    code.insert(make_pair("-.-.-.", ';'));
    code.insert(make_pair("-...-", '='));
    code.insert(make_pair(".-.-.", '+'));
    code.insert(make_pair("-....-", '-'));
    code.insert(make_pair("..--.-", '_'));
    code.insert(make_pair(".-..-.", '"'));
    code.insert(make_pair(".--.-.", '@'));
}
void seperator()
{
    buffer = "";
    for(counter = 0; counter < input.length(); counter++)
    {
        if(input[counter] == ' ')
        {
            if(buffer != ""){
            it = code.find(buffer);
            //cout << it->second;
            printf("%c",it->second);
            buffer = "";
            }
            if(input[counter+1] == ' ')
            {
                //cout << " ";
                printf(" ");
            }
        }
        else
        {
            buffer += input[counter];
        }
    }
    if(buffer != "")
    {
        it = code.find(buffer);
        //cout << it->second;
        printf("%c",it->second);
    }
    //cout << endl;
    printf("\n");
}
int main()
{
    int i;
    set_up();
    //f = fopen("f.txt","w");
    cin >> testcases;
    cin.ignore();
    for(i = 1; i<=testcases; i++)
    {
        getline(cin, input);
        if(i>1)
            //cout << endl;
            printf("\n");
        //cout << "Message #" << i << endl;
        printf("Message #%d\n",i);
        seperator();
    }
    //fclose(f);
    return 0;
}
