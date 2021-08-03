#include<stdio.h>
int adder(int a,int b,int c);
int main()
{
    int num,sum=0,add=0,remain;
    scanf("%d",&num);
    sum=adder(num,add,remain);
    printf("Sum of digits is : %d",sum);
    return 0;
}

int adder(int num,int add,int remain)
{
    if(num>0)
    {
        remain=num%10;
        num/=10;
        add=remain+adder(num,add,remain);
    }
    return add;
}
