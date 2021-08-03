#include<stdio.h>
int main()
{
    int num,loop_count,count=0,backup,loop_count_1,power=0;
    float mul=1.0000;
    scanf("%d",&num);
    for(loop_count=1;loop_count<=num;loop_count++)  //getting factorial value
    {
        mul*=loop_count;
        backup=mul;
        while(backup>0)  //finding the digits of factorial value
        {
            backup/=10;
            count++;
        }
        for(loop_count_1=1;loop_count_1<count;loop_count_1++)  // getting power of 10
        {
            mul/=10;
            power++;
        }
        count=0;
    }
    printf("\n%f X 10^%d",mul,power);
    return 0;
}
