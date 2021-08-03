#include<stdio.h>
int main()
{
    int loop_count_1,loop_count_2,num,count=1;
    scanf("%d",&num);
    for(loop_count_1=1;loop_count_1<=num;loop_count_1++)
    {
        for(loop_count_2=1;loop_count_2<=loop_count_1;loop_count_2++)
        {
            printf("%d ",count);
            count++;
        }
        printf("\n");
    }
    return 0;
}
