#include<stdio.h>
int main()
{
    int flag=0,num,loop_count;
    scanf("%d",&num);
    for(loop_count=2;loop_count<=num/2;loop_count++)
    {
        if(num%loop_count==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("This is prime number");
    }
    else
    {
        printf("This is not a prime number");
    }
    return 0;
}
