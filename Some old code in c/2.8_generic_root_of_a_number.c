#include<stdio.h>
int main()
{
    int num,sum=0,rem;
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10; //getting number one by one
        num/=10;
        sum+=rem;
    }
    while(sum>=10) //if addition of digit is two digit number
    {
        rem=sum%10;
        sum/=10;
        sum+=rem;
    }
    printf("\ngeneric root of number is : %d",sum);

    return 0;
}
