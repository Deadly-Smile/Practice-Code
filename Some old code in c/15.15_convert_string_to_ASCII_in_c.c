#include<stdio.h>
int main()
{
    char string[50];
    int i;
    gets(string);
    for(i=0;string[i]!='\0';i++)
    {
        printf("%d ",string[i]);
    }
    return 0;
}
