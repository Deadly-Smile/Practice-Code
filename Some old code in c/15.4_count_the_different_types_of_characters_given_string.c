#include<stdio.h>
int length(char string[]);
void initial(int array[50][2],int len_str);
void check(char string[],int array[50][2],int len_str);
void print(char string[],char second[],int array[50][2],int len_str);

int main()
{
    char string[50];
    gets(string);
    int len_str;
    len_str=length(string);
    char second[len_str+1];
    for(int i=0;i<=len_str;i++)
    {
        second[i]='0';
        if(i==len_str)
        {
            second[i]='\0';
        }
    }
    int array[len_str][2];
    initial(array,len_str);
    check(string,array,len_str);
    print(string,second,array,len_str);
    return 0;
}
int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}

void initial(int array[50][2],int len_str)
{
    for(;len_str>=0;len_str--)
    {
        array[len_str][0]=0;
    }
}

void check(char string[],int array[50][2],int len_str)
{
    int i,j;
    for(i=0;i<len_str;i++)
    {
        array[i][1]=string[i];
        for(j=0;j<len_str;j++)
        {
            if(string[i]==string[j])
            {
                array[j][0]++;
            }
        }
    }
}

void print(char string[],char second[],int array[50][2],int len_str)
{
    int i;
    for(i=0;i<len_str;i++)
    {
        for(int j=0;j<len_str;j++)
        {
            if(second[j]==array[i][1])
            {
                goto end;
            }
        }
        printf("character %c appears number of times : %d\n",array[i][1],array[i][0]);
        second[i]=array[i][1];
        end :
            continue;
    }
}
