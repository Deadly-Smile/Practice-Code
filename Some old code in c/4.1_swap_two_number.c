#include<stdio.h>
int main()
{
    int num_1,num_2;
    printf("Enter first number :");
    scanf("%d",&num_1);
    printf("\nEnter second number :");
    scanf("%d",&num_2);

    num_1=num_1-num_2;
    num_2=num_2+num_1;
    num_1=num_2-num_1;

    printf("\nThe second number is :%d",num_1);
    printf("\n\nThe first number is :%d",num_2);

    return 0;
}
