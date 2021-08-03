#include<stdio.h>
int main()
{
    int count;

    printf("Size of array :");
    scanf("%d",&count);

    int array[count];
    int loop_count,loop_count_1;

    for(loop_count=0;loop_count<count;loop_count++)
    {
        scanf("%d",&array[loop_count]);
    }


    for(loop_count=0;loop_count<count;loop_count++)
    {
        for(loop_count_1=0;loop_count_1<count;loop_count_1++)
        {
            if(array[loop_count]==array[loop_count_1])
            {

                if(loop_count!=loop_count_1){
                array[loop_count_1]=-2147483645;
                }
            }
        }
    }
    for(loop_count=0;loop_count<count;loop_count++)
    {
        if(array[loop_count]>-2147483645)
        {
            printf("%d ",array[loop_count]);
        }
    }
    return 0;
}
