#include<stdio.h>
void swap(int *num_1,int *num_2);
int main()
{
    int num_1,num_2;
    scanf("%d%d",&num_1,&num_2);
    swap(&num_1,&num_2);
    printf("First number :%d\nSecond number :%d",num_1,num_2);
    return 0;
}
void swap(int *num_1,int *num_2)
{
    *num_1=*num_1+*num_2;
    *num_2=*num_1-*num_2;
    *num_1=*num_1-*num_2;
}
