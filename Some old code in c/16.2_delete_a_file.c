#include<stdio.h>
int main()
{
    int i;
    i=remove("the_file.txt");
    printf("%d\n",i);
    if(i==0)
    {
        printf("file is deleted");
    }
    else{
        printf("file is not deleted");
    }
    return 0;
}
