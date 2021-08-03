#include<stdio.h>
int main()
{
    int a,i=0,num,j=1,c;
    scanf("%d",&num);
    printf(" %d",i);
    printf(" %d",j);
    for(a=1;a<=num-2;a++)
    {
        if(a%2==1){
            i+=j;
            printf(" %d",i);
        }
        i=i;
        if(a%2==0)
        {
            j+=i;
            printf(" %d",j);
        }
        j=j;
    }


    return 0;
}
