#include<stdio.h>
int main()
{
    int num,loop_count,sum=0;
    scanf("%d",&num);
    printf("\nThe sum of series :");
    for(loop_count=1;loop_count<=num;loop_count++)
    {
        sum+=loop_count;
        printf("%d + ",loop_count);
    }
    printf("is %d",sum);

    return 0;
}
