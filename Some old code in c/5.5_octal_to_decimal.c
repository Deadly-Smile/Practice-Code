#include<stdio.h>
int main()
{
    int loop_count,count=0,num,sum=0,mul=1,remaind;
    scanf("%d",&num);
    while(num>0)
    {
        remaind=num%10;
        num/=10;
        for(loop_count=1;loop_count<=count;loop_count++)
        {
            mul*=8;
        }
        remaind=remaind*mul;
        sum+=remaind;
        mul=1;
        count++;
    }
    printf("\nThe decimal value : %d",sum);
    return 0;
}
