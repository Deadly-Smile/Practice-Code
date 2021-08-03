#include<stdio.h>
int main()
{
    int num,loop_con,remain,num_1;
    scanf("%d",&num);
    printf("The prime factor of %d : ",num);
    for(loop_con=2;loop_con<=num;loop_con++)
    {
        remain=num%loop_con;
        if(remain==0)
        {
            num_1=num/loop_con;
            num=num_1;
            printf("%d ",loop_con);
            loop_con=1;
        }
        if(num==loop_con)
        {
            if(loop_con==1)
            {
                break;
            }
           printf("%d",loop_con);
        }
    }
    return 0;
}
