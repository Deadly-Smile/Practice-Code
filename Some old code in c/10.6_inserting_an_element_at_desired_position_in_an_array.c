#include<stdio.h>
int main()
{
    int count_1,count_2;
    printf("size of array :");
    scanf("%d",&count_1);
    int array[count_1+1];
    int loop_count_1;

    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        printf("Element - %d :",loop_count_1+1);
        scanf("%d",&array[loop_count_1]);
    }

    printf("Input the position where to insert :");
    scanf("%d",&count_2);
    printf("Number to insert :");
    int extra_1,extra_2;
    scanf("%d",&extra_1);

    for(loop_count_1=count_2-1;loop_count_1<=count_1;loop_count_1++)
    {
        extra_2=array[loop_count_1];
        array[loop_count_1]=extra_1;
        extra_1=extra_2;

    }

    printf("\nThe new list is : ");
    for(loop_count_1=0;loop_count_1<=count_1;loop_count_1++)
    {
        printf("%d ",array[loop_count_1]);
    }

    return 0;
}
