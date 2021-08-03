#include<stdio.h>
int main()
{
    int num,remain;
    scanf("%d",&num);
    while(num>0)
    {
        remain=num%10;
        num/=10;
        printf("%d",remain);
    }

    return 0;
}
