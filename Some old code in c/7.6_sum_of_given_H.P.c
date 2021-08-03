#include<stdio.h>
int main()
{
    int num,diff,loop_count,sum=0;
    printf("The number of term :");
    scanf("%d",&num);
    printf("The first number :");
    scanf("%d",&loop_count);
    printf("The difference of term :");
    scanf("%d",&diff);
    printf("\nThe sum of series :");
    for(;loop_count<=num*diff;loop_count+=diff)
    {
        printf("%d + ",loop_count);
        sum+=loop_count;
    }
    printf(" is %d",sum);
    return 0;
}
