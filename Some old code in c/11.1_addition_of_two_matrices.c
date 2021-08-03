#include<stdio.h>
void main()
{
    int count_1;
    printf("Size of matrix :");
    scanf("%d",&count_1);

    int array_1[count_1][count_1],array_2[count_1][count_1];
    int loop_count_1,loop_count_2;

    printf("The first matrix :\n");

    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            printf("Element -[%d],[%d] : ",loop_count_1+1,loop_count_2+1);
            scanf("%d",&array_1[loop_count_1][loop_count_2]);
        }
    }

    printf("The next matrix :\n");

    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            printf("Element -[%d],[%d] : ",loop_count_1+1,loop_count_2+1);
            scanf("%d",&array_2[loop_count_1][loop_count_2]);
        }
    }

    printf("Addition of two matrix :\n");
    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            printf("%d ",array_1[loop_count_1][loop_count_2]+array_2[loop_count_1][loop_count_2]);
        }
        printf("\n");
    }

}
