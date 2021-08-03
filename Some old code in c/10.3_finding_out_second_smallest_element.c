#include<stdio.h>
void main()
{
    int count_1,count=0;
    printf("size of array :");
    scanf("%d",&count_1);
    int array[count_1];
    int loop_count_1,loop_count_2,min;
    for(loop_count_1=0;loop_count_1<count_1;loop_count_1++)
    {
        printf("Element - %d :",loop_count_1+1);
        scanf("%d",&array[loop_count_1]);
    }
    for(loop_count_1=0;loop_count_1<2;loop_count_1++)
    {
        min=2147483645;
        for(loop_count_2=0;loop_count_2<count_1;loop_count_2++)
        {
            if(array[loop_count_2]<min)
            {
                min=array[loop_count_2];
                count=loop_count_2;
            }
        }
            if(loop_count_1==1)
            {
                printf("The second min value is : %d",min);
            }
            array[count]=21474836;
    }
}
