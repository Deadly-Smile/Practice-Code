#include<stdio.h>
void input_and_output(int array[],int count,int a);
void swap(int *num_1,int *num_2);

int main()
{
    int array_1[50],array_2[50];
    short int count,i,flag=0;

    printf("The number of elements in each array :");
    scanf("%d",&count); // taking the number of elements

    printf("Enter the elements of first array :");
    input_and_output(array_1,count,flag);
    printf("Enter the elements of second array :"); // taking the elements of arrays
    input_and_output(array_2,count,flag);

    flag++;
    for(i=0;i<count;i++)
    {
        swap(&array_1[i],&array_2[i]); // swapping the elements of arrays
    }

    printf("\nElements of first array :");
    input_and_output(array_1,count,flag);
    printf("\nElements of second array :"); // printing the new arrays
    input_and_output(array_2,count,flag);

    return 0;
}
void swap(int *num_1,int *num_2)
{
    *num_1=*num_1+*num_2;
    *num_2=*num_1-*num_2; // swapping
    *num_1=*num_1-*num_2;
}
void input_and_output(int array[],int count,int a)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(a==0)
        {
            scanf("%d",&array[i]); // taking input
        }
        else{
            printf("%d ",array[i]); // printing output
        }
    }
}
