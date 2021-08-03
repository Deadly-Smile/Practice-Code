#include<stdio.h>
int main()
{
    char string[50];
    FILE *fp;
    fp=fopen("The_file.txt","w");
    if(fp==NULL)
    {
        printf("ERROR");
        goto end;
    }
    gets(string);
    fprintf(fp,"%s",string);

    end:
    return 0;
}
