#include<stdio.h>
int main()
{
    int a,i,num,sum=0;
    scanf("%d",&num);
    for(i=1;i<=num/2;i++)
    {
        if(num%i==0)
        {
            printf("\n%d",i);
            sum+=i;
        }
    }
    printf("\n%d",sum);
    if(num==sum){printf("\nThe number is perfect!!");}
    else{printf("\nThe number is not perfect!!");}
    return 0;
}
