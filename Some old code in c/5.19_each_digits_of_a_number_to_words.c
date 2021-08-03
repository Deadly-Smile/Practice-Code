#include<stdio.h>
#include<math.h>
int  main()
{
    int num,remain,sum,loop_count=0;
    char c;
    scanf("%d",&num);
    sum=num;
    while(sum>0)
    {
        sum/=10;
        loop_count++;
    }
    sum=0;
    for(loop_count-=1;loop_count>=0;loop_count--)
    {
        remain=num%10;
        num/=10;
        remain*=(float)pow(10,loop_count);
        sum+=remain;
    }
    printf("\n");
    while(sum>0)
    {
        remain=sum%10;
        sum/=10;
        if(remain==0)
        {
            printf("zero ");
        }
        if(remain==1)
        {
            printf("one ");
        }
        if(remain==2)
        {
            printf("two ");
        }
        if(remain==3)
        {
            printf("three ");
        }
        if(remain==4)
        {
            printf("four ");
        }
        if(remain==5)
        {
            printf("five ");
        }
        if(remain==6)
        {
            printf("six ");
        }
        if(remain==7)
        {
            printf("seven ");
        }
        if(remain==8)
        {
            printf("eight ");
        }
        if(remain==9)
        {
            printf("nine ");
        }
    }
    return 0;
}
