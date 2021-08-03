#include<stdio.h>
int main()
{
    long long int num,divider;
    double divided_value;
    printf("The number to divided :");
    scanf("%lli",&num);
    printf("The divider :");
    scanf("%lli",&divider);
    divided_value=(double)num/divider;
    printf("%lf",divided_value);
    return 0;
}

