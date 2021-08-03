#include<stdio.h>
int main()
{
    int num,backup,count=0;
    scanf("%d",&num);
    backup=num;
    while(backup>0)
    {
        backup/=10;
        count++;
    }
    int array[count-1];
    backup=count-1;
    count=0;
    while(num>0)
    {
        array[count]=num%10;
        num/=10;
        count++;
    }
    printf("\n");
    for(count=backup;count>=0;count--)
    {
        printf("%d ",array[count]);
    }
    return 0;
}
