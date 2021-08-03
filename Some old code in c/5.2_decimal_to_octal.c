#include<stdio.h>
int main()
{
    int count=0,num,sum=0,remaind,loop_count,mul=1;
    scanf("%d",&num);
    while(num>0)
    {
        remaind=num%8;
        num/=8;
        for(loop_count=1;loop_count<=count;loop_count++)
        {
            mul*=10;
        }
        sum+=remaind*mul;
        count++;
        mul=1;
    }
    printf("\nThe octal form : %d",sum);
    return 0;
}
