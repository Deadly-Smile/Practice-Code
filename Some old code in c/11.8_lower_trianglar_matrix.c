#include<stdio.h>
void main()
{
    int count;
    printf("Enter the size of matrix :");
    scanf("%d",&count);                     // ensuring the size of matrix
    int matrix[count][count];

    int loop_count_1,loop_count_2; // declaring loop control variables

    printf("\nGive the values of matrix :\n");
    for(loop_count_1=0;loop_count_1<count;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count;loop_count_2++)  // taking values of matrix
        {
            scanf("%d",&matrix[loop_count_1][loop_count_2]);
        }
    }

    printf("\nThe matrix :\n");
    for(loop_count_1=0;loop_count_1<count;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count;loop_count_2++)  // printing the matrix
        {
            printf("%d  ",matrix[loop_count_1][loop_count_2]);
        }
        printf("\n");
    }
    printf("\nThe new matrix :\n");
    for(loop_count_1=0;loop_count_1<count;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<count;loop_count_2++)
        {
            if(loop_count_1>loop_count_2)           // Setting zero in lower triangular matrix
            {
                matrix[loop_count_1][loop_count_2]=0;
            }
            printf("%d  ",matrix[loop_count_1][loop_count_2]);
        }
        printf("\n");
    }
}
