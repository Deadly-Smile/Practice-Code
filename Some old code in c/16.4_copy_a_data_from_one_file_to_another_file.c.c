#include<stdio.h>
int main()
{
    char text[50];
    FILE *flp;
    FILE *file_2;
    flp=fopen("old_file.txt","r");
    if(flp==NULL)
    {
        printf("ERROR!!");
        goto end;
    }
    fgets (text,50,flp);
    fclose(flp);
    file_2=fopen("new_file.txt","w");
    if(file_2==NULL)
    {
        printf("ERROR_2!!");
        goto end;
    }
    fprintf(file_2,"%s",text);
    fclose(file_2);
    end:
    return 0;
}
