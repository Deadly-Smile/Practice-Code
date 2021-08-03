#include<stdio.h>
void reverser(int a);


int main()
{
    int num;
    scanf("%d",&num);
    reverser(num);
    return 0;
}


void reverser(int num)
{
    int remain;
    if(num>0)
    {
        remain=num%10;
        num/=10;
        printf("%d",remain);
        reverser(num);
    }
}
