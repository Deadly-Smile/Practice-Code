#include<stdio.h>
void main()
{
    int loop_count,max_value=-2147483645,count,min_value=2147483645;
    printf("Size of array :");
    scanf("%d",&count);
    int array[count];
    for(loop_count=0;loop_count<count;loop_count++)
    {
        scanf("%d",&array[loop_count]);
        if(min_value>array[loop_count])
        {
            min_value=array[loop_count];
        }
        if(max_value<array[loop_count])
        {
            max_value=array[loop_count];
        }

    }
    printf("The largest value is %d\nThe smallest value is : %d",max_value,min_value);
}
