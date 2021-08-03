#include<stdio.h>
int main()
{
    char string[50],c;
    short int i,flag=0;
    gets(string);
    printf("The character form to start printing :");
    scanf("%c",&c);
    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]==c)
        {
            flag=1;
        }
        if(flag>0)
        {
            printf("%c",string[i]);
        }
    }
    return 0;
}
