#include<stdio.h>
int main()
{
    int num_1,num_2,i,count=0;
    scanf("%d",&num_1);
    scanf("%d",&num_2);
    printf("The subtract of two number is :");
    if(num_1>num_2)
    {
        for(i=num_2+1;i<=num_1;i++)
        {
            count++;
        }
    }
    if(num_2>num_1)
    {
        for(i=num_1+1;i<=num_2;i++)
        {
            count++;
        }
        printf("minus");
    }
    printf("%d",count);

    return 0;
}
