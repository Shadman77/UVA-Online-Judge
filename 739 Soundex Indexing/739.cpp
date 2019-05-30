#include<cstdio>
#include<cstring>
using namespace std;
char ans[5], input[30], code[26], last_code;
//Setting code//
void set_code()
{
    int i;
    for(i=0;i<26;i++)
    {
        code[i] = '0';
    }
    code['B'%26] = code['P'%26] = code['F'%26] = code['V'%26] = '1';
    code['C'%26] = code['S'%26] = code['K'%26] = code['G'%26] = code['J'%26] = code['Q'%26] = code['X'%26] = code['Z'%26] = '2';
    code['D'%26] = code['T'%26] = '3';
    code['L'%26] = '4';
    code['M'%26] = code['N'%26] = '5';
    code['R'%26] = '6';
}

void get_ans()//WORKS
{
    int l = strlen(input), i = 1, j = 1;//j for ans and i for input
    char code_temp;
    ans[0] = input[0];
    last_code = code[input[0]%26];//Last code resets here
    while((j<4)&&(i<l))
    {
        code_temp = code[input[i]%26];
        //printf("code_temp = %c\n",code_temp);
        i++;
        if((code_temp != last_code) && (code_temp != '0'))
        {
            //printf("IF code_temp = %c\n",code_temp);
            ans[j] = code_temp;
            j++;
        }
        last_code = code_temp;
    }
    while(j<4)
    {
        ans[j] = '0';
        j++;
    }
    ans[j] = '\0';
}
void print()
{
    printf("         ");
    printf("%-25s",input);
    printf("%s\n",ans);
}
int main()
{
    //int i = 0;
    char temp[50] = "NAME";
    set_code();
    printf("         ");
    printf("%-25s",temp);
    printf("SOUNDEX CODE\n");
    while(scanf("%s",input)==1)
    //while(i < 5)
    {
        //scanf("%s",input);
        get_ans();
        print();
        //printf("%s\n",ans);
        //i++;
    }
    printf("                   END OF OUTPUT\n");
}

