#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
char input[300];
char ans[300];
char temp[50];
int scan_string()
{
    sprintf(input,"");
    char c;
    while(scanf("%c",&c)==1)
    {
        //printf("c = %c\n",c);
        sprintf(input, "%s%c",input,c);
        if(c =='\n')
        {
            return 0;
        }
    }
    //printf("input = %s\n",input);
    return 1;
}
void string_reverse()
{
    char c;
    int i,j,l=strlen(temp);
    for(i=0,j=l-1; i<j; i++,j--)
    {
        c = temp[i];
        temp[i] = temp[j];
        temp[j] = c;
    }
}
void encode()
{
    int l = strlen(input),i;
    sprintf(ans,"");
    for(i=l-2; i>=0; i--)
    {
        sprintf(temp,"%d",input[i]);
        string_reverse();
        sprintf(ans,"%s%s",ans,temp);
    }
}
void decode()
{
    int j = strlen(input) - 2, ascii;
    char c;
    sprintf(ans,"");
    while(j>=0)
    {
        temp[0] = input[j];
        temp[1] = input[j-1];
        temp[2] = '\0';
        ascii = atoi(temp);
        if((ascii>=32)&&(ascii<=122))
        {
            c = ascii;
            j -= 2;
            sprintf(ans,"%s%c",ans,c);
        }
        else
        {
            temp[0] = input[j];
            temp[1] = input[j-1];
            temp[2] = input[j-2];
            temp[3] = '\0';
            ascii = atoi(temp);
            c = ascii;
            j -= 3;
            sprintf(ans,"%s%c",ans,c);
        }
    }
}
int main()
{
    int i;
    //FILE *f = fopen("file.txt","w");
    //while(scanf("%c",&c)==1)//this should take care of the eof thing
    while(1)
    {
        i = scan_string();
        if(i==1)
            break;
        else if(input[0] == '\n')
        {
            printf("\n");
            //fprintf(f,"\n");
            continue;
        }
        //if(strcmp(input,"000\n")==0)
        //break;
        else if((input[0]>='0') && (input[0] <= '9'))
            decode();
        else
            encode();
        //fprintf(f,"%s\n",ans);
        printf("%s\n",ans);
    }
    //fclose(f);
    return 0;
}
