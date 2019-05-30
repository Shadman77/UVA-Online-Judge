#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std;
char input;
char longest_word[120], buffer[120];
int longest_lentgh, temp;
int main()
{
    int i;
    longest_lentgh = 0;
    sprintf(buffer,"");
    while(1)
    {
        scanf("%c",&input);
        //printf("c = %c\n",input);
        if(((input >= 'a')&&(input<='z'))||((input >= 'A')&&(input <= 'Z'))||(input=='-'))
        {
            sprintf(buffer,"%s%c",buffer,input);
            //printf("buffer = %s\n", buffer);
            if(strcmp(buffer,"E-N-D")==0){
                    for(i = 0; i < longest_lentgh; i++)
                    {
                        longest_word[i] = tolower(longest_word[i]);
                    }
                    printf("%s\n",longest_word);
                return 0;
            }
        }
        else
        {
            temp = strlen(buffer);
            if(temp > longest_lentgh)
            {
                longest_lentgh = temp;
                strcpy(longest_word,buffer);
            }
            sprintf(buffer,"");
            //printf("longest_word = %s\n",longest_word);
        }
    }
    return 0;
}
