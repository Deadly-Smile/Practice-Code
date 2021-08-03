#include<stdio.h>
#include<math.h>
int main()
{
    long long int num,power,backup,divider;
    int count=0;
    double proxy;
    printf("The number :");
    scanf("%lli",&num);
    printf("The power :");
    scanf("%lli",&power);

    backup=num;       //taking number as scientific way
    while(backup>0)
    {
        backup/=10;
        count++;
    }
    divider=(double)pow(10,count-1);
    proxy=(double)num/divider;
    proxy=(double)pow(proxy,power);
    printf("%lf X 10^%lli",proxy,count*power);
    return 0;
}

