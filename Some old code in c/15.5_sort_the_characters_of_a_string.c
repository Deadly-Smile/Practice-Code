#include<stdio.h>
int length(char string[]);
void main()
{
    char string[50];
    gets(string);
    int len_str,loop_count_1,loop_count_2;
    len_str=length(string);
    char sort_string[len_str+1];
    short int min,count=0;
    for(loop_count_1=0;loop_count_1<len_str;loop_count_1++)
    {
        min=129;
        for(loop_count_2=0;loop_count_2<len_str;loop_count_2++)
        {
            if(min>string[loop_count_2])
            {
                min=string[loop_count_2];
                count=loop_count_2;
            }
        }
        sort_string[loop_count_1]=min;
        string[count]=127;
    }
    sort_string[len_str]='\0';
    puts(sort_string);
}

int length(char string[])
{
    short int i=0;
    for(i=0;string[i]!='\0';i++){}
    return i;
}
