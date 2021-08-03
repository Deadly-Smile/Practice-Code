#include<stdio.h>
int length(char string[]);
int compare(char s1[],char s2[]);
int main()
{
    char s1[50],s2[50];
    int len_s1,len_s2,flag;
    gets(s1);
    len_s1=length(s1);
    gets(s2);
    len_s2=length(s2);
    if(len_s1!=len_s2)
    {
        printf("The strings are not same");
        goto end;
    }
    else{
        flag=compare(s1,s2);
        if(flag==0)
        {
            printf("The strings are same");
        }
        else{
            printf("The strings are not same");
        }
    }
    end:
    return 0;
}
int compare(char s1[],char s2[])
{
    int i,flag=0;
    for(i=0;s1[i]!='\0';i++)
    {
        if(s1[i]==s2[i])
        {
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    return flag;
}
int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
