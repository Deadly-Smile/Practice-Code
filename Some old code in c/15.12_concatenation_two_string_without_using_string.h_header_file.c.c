#include<stdio.h>
int length(char s1[]);
int main()
{
    char s1[50],s2[50];
    gets(s1);
    gets(s2);
    short int len_s1,len_s2;
    len_s1=length(s1);
    len_s2=length(s2);
    short int i,j=0;
    for(i=len_s2;i<len_s1+len_s2;i++)
    {
        s2[i]=s1[j];
        j++;
    }
    s2[i]='\0';
    puts(s2);
    return 0;
}
int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
