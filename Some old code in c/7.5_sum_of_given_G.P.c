#include<stdio.h>
int main()
{
    int num,ratio,loop_count,sum=0,count=1;
    printf("The number of term :");
    scanf("%d",&num);
    printf("The ratio of term :");
    scanf("%d",&ratio);
    printf("\nThe sum of series :");
    for(loop_count=1;count<=num;loop_count*=ratio)
    {
        printf("%d + ",loop_count);
        sum+=loop_count;
        count++;
    }
    printf(" is %d",sum);
    return 0;
}

