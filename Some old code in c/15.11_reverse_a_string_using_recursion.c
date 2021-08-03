#include<stdio.h>
int length(char string[]);
void reverse(char string[],short int len_str );
int main()
{
    char string[50];
    gets(string);
    short int len_str;
    len_str=length(string);
    len_str--;
    reverse(string,len_str);
    return 0;
}
void reverse(char string[],short int len_str )
{
    if(len_str>=0)
    {
        printf("%c",string[len_str]);
        len_str--;
        reverse(string,len_str);
    }
}
int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
