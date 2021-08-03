#include<stdio.h>
#include<math.h>
int main()
{
    int num_in,remain,count=0;
    double num_frac,sum=0.0000,mul=1.0000;
    scanf("%lf",&num_frac);
    num_in=(int)num_frac;
    num_frac-=(double)num_in;
    while(num_in>0)    //without fractional part
    {
        remain=num_in%10;
        num_in/=10;
        remain*=(float)pow(2,count);
        count++;
        sum+=remain;
    }
    count=-1;
    num_frac*=10;
    for(short int loop_count=1;loop_count<=6;loop_count++)  // fractional part
    {
        remain=num_frac;
        num_frac-=remain;
        num_frac*=10;
        mul=(double)remain*pow(2,count);
        count--;
        sum+=mul;
    }
    printf("\n%lf",sum);
    return 0;
}
