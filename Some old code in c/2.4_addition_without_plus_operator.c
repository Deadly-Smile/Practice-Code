#include<stdio.h>
int main()
{
    int num_1,num_2,difference,multi,addition;
    //taking input
    scanf("%d",&num_1);
    scanf("%d",&num_2);
    if(num_1>=num_2)
    {
        difference=num_1-num_2;
        multi=num_1*2;
        addition=multi-difference;
    }
    if(num_2>num_1)
    {
        difference=num_1-num_2;
        multi=num_1*2;
        addition=multi-difference;
    }
    printf("\nThe addition of two number is %d",addition);

    return 0;
}
