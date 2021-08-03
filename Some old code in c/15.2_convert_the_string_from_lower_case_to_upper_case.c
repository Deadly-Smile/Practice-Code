#include<stdio.h>
int length(char string[]);
void initial(char tester[26][2]);
void convert(char string[],char tester[26][2],int len_str);
int main()
{
    char string[50];
    gets(string);
    int len_str,con;
    len_str=length(string);
    char tester[26][2];
    initial(tester);
    convert(string,tester,len_str);
    puts(string);
    return 0;
}
void convert(char string[],char tester[26][2],int len_str)
{
    unsigned short i,j,k;
    for(i=0;i<len_str;i++)
    {
        for(j=0;j<26;j++)
        {
            for(k=0;k<2;k++)
            {
                if(string[i]==tester[j][k])
                {
                    string[i]=tester[j][0];
                    break;
                }
            }
        }
    }
}

void initial(char tester[26][2])
{
    char i,j,p=0;
    for(i=0;i<2;i++)
    {
        if(i==0){
        for(j='A';j<='Z';j++)
        {
            tester[p][0]=j;
            p++;
        }
        }
        else{
                p=0;
            for(j='a';j<='z';j++)
            {
                tester[p][1]=j;
                p++;
            }
        }
    }
}

int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
