#include<stdio.h>
int length(char string[]);
void swap_string(char s1[],char s2[],int count);
int main()
{
    char s1[50],s2[50];
    short int len_s1;

    gets(s1);
    len_s1=length(s1);

    swap_string(s2,s1,len_s1);

    puts(s2);

    return 0;
}
void swap_string(char s1[],char s2[],int count)
{
    short int i;
    for(i=0;i<=count;i++)
    {
        s1[i]=s2[i];
    }
}
int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}

