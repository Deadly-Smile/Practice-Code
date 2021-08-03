#include<stdio.h>
int main()
{
    int num_1,num_2;
    scanf("%d%d",&num_1,&num_2);

    num_1=num_1-num_2;
    num_2=num_2+num_1;
    num_1=num_2-num_1;

    printf("The first number is :%d\nThe second number is :%d",num_1,num_2);

    return 0;
}
