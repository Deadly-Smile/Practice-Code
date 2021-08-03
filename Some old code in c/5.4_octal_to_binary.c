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
    count=0;
    num=0;
    while(sum>0)
    {
        remaind=sum%2;
        sum/=2;
        for(loop_count=1;loop_count<=count;loop_count++)
        {
            mul*=10;
        }
        num+=remaind*mul;
        mul=1;
        count++;
    }
    printf("\nThe binary form is : %d",num);
    return 0;
}
