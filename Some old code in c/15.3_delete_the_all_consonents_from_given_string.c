#include<stdio.h>
int length(char string[]);
void convert(char string[],char tester[5][2],int len_str);
int main()
{
    char string[50],tester[5][2]={{'A','a'},{'E','e'},{'I','i'},{'O','o'},{'U','u'}};
    int len_str;
    gets(string);
    len_str=length(string);
    convert(string,tester,len_str);
    return 0;
}
void convert(char string[],char tester[5][2],int len_str)
{
    unsigned short i,j,k,count=0;
    char backup[len_str+1];
    for(i=0;i<len_str;i++)
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<2;k++)
            {
                if(string[i]==tester[j][k])
                {
                    backup[count]=string[i];
                    count++;
                }
            }
        }
    }
    backup[count]='\0';
    puts(backup);
}

int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
