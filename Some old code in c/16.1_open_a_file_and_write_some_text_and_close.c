#include<stdio.h>
int main()
{
    FILE *flp;
    char string[50];
    flp=fopen("new_file.txt","w");
    if(flp==NULL)
    {
        printf("ERROR!!!");
        goto end;
    }
    gets(string);
    fprintf(flp,"%s",string);
    fclose(flp);
    end:
    return 0;
}
