#include<stdio.h>
void main()
{
    int count_1;
    printf("Size of matrix :");
    scanf("%d",&count_1);

    int matrix_1[count_1][count_1];
    int loop_count_1,loop_count_2,mul;

    printf("The value to scaler multiply the matrix :");
    scanf("%d",&mul);

    printf("The matrix :\n");

    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            printf("Element -[%d][%d] : ",loop_count_1+1,loop_count_2+1);
            scanf("%d",&matrix_1[loop_count_1][loop_count_2]);
        }
    }

    printf("The new matrix :\n");
    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            printf("%d  ",matrix_1[loop_count_1][loop_count_2]*mul);
        }
        printf("\n");
    }
}
