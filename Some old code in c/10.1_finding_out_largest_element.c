#include<stdio.h>
void main()
{
    int loop_count,max_value,count;
    printf("Size of array :");
    scanf("%d",&count);
    int array[count];
    for(loop_count=0;loop_count<count;loop_count++)
    {
        scanf("%d",&array[loop_count]);
    }
    max_value=array[0];
    for(loop_count=0;loop_count<count;loop_count++)
    {
        if(max_value<array[loop_count])
        {
            max_value=array[loop_count];
        }
    }
    printf("The max value is %d",max_value);
}
