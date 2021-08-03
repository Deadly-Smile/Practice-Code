#include<stdio.h>
int main()
{
    int rem,num,sum=0,count=0,mul=1,loop_count;
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10; //getting bit one by one
        num/=10; //removing bit from right-side
        //power - ing*
        for(loop_count=1;loop_count<=count;loop_count++)
        {
            mul*=2;
        }
        sum+=rem*mul;
        count++;
        mul=1;
    }
    printf("\n%d",sum);
    return 0;
}
