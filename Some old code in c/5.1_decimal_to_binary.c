#include<stdio.h>
#include<math.h>
int main()
{
    int num,count=0;
    long long int sum=0,remaider;
    scanf("%d",&num);
    while(num>0)
    {
        remaider = num % 2;
        num/=2;
        remaider*=(float)pow(10,count);
        sum+=(long long int)remaider;
        count++;
    }
    printf("\n%lli",sum);
    return 0;
}
