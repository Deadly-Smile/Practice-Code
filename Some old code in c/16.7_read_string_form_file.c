#include<stdio.h>
int main()
{
    FILE *fp=NULL;
    fp=fopen("The_new_file.txt","r");
    if(fp==NULL)
    {
        printf("Error");
        goto end;
    }
    char string[50];
    fscanf(fp,"%[^\n]s",string);
    puts(string);
    fclose(fp);
    end:
    return 0;
}
