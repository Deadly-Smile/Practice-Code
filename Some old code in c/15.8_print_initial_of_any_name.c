#include<stdio.h>
int main()
{
    char string[50];
    gets(string);
    short int i,j=0;
    if(string[0]!=' ')
    {
        printf("%c",string[0]);
    }
    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]==' ')
        {
            continue;
        }
        else{
            if(i>j)
            {
                printf("%c",string[i]);
            }
            j=i+1;
        }
    }

    return 0;
}
