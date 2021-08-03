#include<stdio.h>
#include<math.h>
int main()
{
    short unsigned int count=0,num_int,frac_remain;
    long long int sum=0,remain;
    double num_fraction;
    scanf("%lf",&num_fraction);
    num_int=num_fraction;
    num_fraction-=num_int;
    while(num_int>0)
    {
        remain = num_int % 2;
        num_int/=2;
        remain*=(float)pow(10,count);
        sum+=(long long int)remain;
        count++;
    }
    count=1;
    printf("\n%lli.",sum);
    while(count>0)
    {
       count=num_fraction*1000;
       frac_remain=num_fraction*2;
       num_fraction*=2;
       num_fraction=num_fraction-frac_remain;
       printf("%hu",frac_remain);
    }


    return 0;
}

