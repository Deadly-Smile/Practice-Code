#include<stdio.h>
int main()
{
    int loop_count,num,value;
    scanf("%d",&num);
    for(loop_count=1;loop_count<=10;loop_count++)
    {
        value=loop_count*num;
        printf("\n%d x %d = %d",num,loop_count,value);
    }
    return 0;
}
