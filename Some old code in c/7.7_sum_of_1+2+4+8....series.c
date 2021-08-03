#include<stdio.h>
int main()
{
    int num,loop_count,sum=0,values_of_series=1;
    scanf("%d",&num);
    printf("The sum of ");
    for(loop_count=1;loop_count<=num;loop_count++)
    {
        printf(" %d +",values_of_series);
        values_of_series*=2;
        sum+=values_of_series;
    }
    printf("is :%d",sum);
    return 0;
}
