#include<stdio.h>
int main()
{
    int value_a,value_b,value_c,variable;
    printf("Calculating the value of this equation : ax^2+bx+c");
    printf("\nInput the value of a:");
    scanf("%d",&value_a);
    printf("\nInput the value of b:");
    scanf("%d",&value_b);
    printf("\nInput the value of c:");
    scanf("%d",&value_c);
    printf("\nInput the value of x:");
    scanf("%d",&variable);
    variable=(value_a*(variable*variable))+(value_b*variable)+value_c;
    printf("\nThe value of equation : %d",variable);

    return 0;
}
