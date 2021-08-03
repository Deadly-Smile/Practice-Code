#include<stdio.h>
int main()
{
    int num,count,factorial=1;
    scanf("%d",&num);
    for(count=1;count<=num;count++)
    {
        factorial*=count;
    }
    printf("\nThe factorial %d is : %d",num,factorial);
    return 0;
}
