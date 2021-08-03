#include<stdio.h>
#include<math.h>
int main()
{
    int num,sum=0,remain,count=0;
    scanf("%x",&num);
    while(num>0)
    {
        remain=num%2;
        num/=2;
        remain*=(float)pow(10,count);
        sum+=remain;
        count++;
    }
    printf("The number is : %d",sum);
    return 0;
}
