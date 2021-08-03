#include<stdio.h>
void length_of_str(char string[],int *len_str);
int main()
{
    char string[50];
    gets(string);
    int len_str;
    length_of_str(string,&len_str);
    printf("%d",len_str);
    return 0;
}

void length_of_str(char string[],int *len_str)
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    *len_str=i;
}
