#include<stdio.h>
#include<math.h>
int main()
{
    int num,loop_count,sum=0;
    scanf("%d",&num);
    printf("\nThe sum of series :");
    for(loop_count=1;loop_count<=num;loop_count++)
    {
        sum+=(float)pow(loop_count,2);
        printf("%d^2 + ",loop_count);
    }
    printf("  is %d",sum);
    return 0;
}
