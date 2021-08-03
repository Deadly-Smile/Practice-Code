#include<stdio.h>
#include<math.h>
int main()
{
    int num,sum=0,count=0,remain;
    scanf("%x",&num);
    while(num>0)
    {
        remain=num%8;
        num/=8;
        remain*=(float)pow(10,count);
        sum+=remain;
        count++;
    }
    printf("The octal form : %d",sum);
    return 0;
}

