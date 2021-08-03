#include<stdio.h>
int main()
{
    char s1[50],s2[50];
    short int i=0;
    char *p=NULL;
    p=s1;
    gets(s1);
    gets(s2);
    for(i=0;*p!='\0';i++)
    {
        p++;
    }
    *p=' ';
    i=0;
    while(*p!='\0')
    {
        *p=s2[i];
        i++;
        p++;
    }
    *p='\0';
    puts(s1);

    return 0;
}

