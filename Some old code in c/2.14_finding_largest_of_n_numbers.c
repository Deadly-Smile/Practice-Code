#include<stdio.h>
int main()
{
    int num,loop_control,num_1,num_2;
    printf("input number of numbers :");
    scanf("%d",&num);
    scanf("%d",&num_1);
    for(loop_control=1;loop_control<num;loop_control++)
    {
        scanf("%d",&num_2);
        if(num_2>=num_1)
        {
            num_1=num_2;
        }
    }
    printf("\nthe largest number is : %d",num_1);

    return 0;
}
