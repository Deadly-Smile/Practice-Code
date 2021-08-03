#include<stdio.h>
int main()
{
    int num,sum=0,remain,backup;
    scanf("%d",&num);
    backup=num;
    while(backup>0)     //getting each digit from number
    {
        remain=backup%10;
        backup/=10;
        remain=remain*remain*remain;
        sum+=remain;
    }
    if(num==sum)
    {
        printf("Armstrong number");
    }
    else{
        printf("Not a armstrong number");
    }
    return 0;
}
