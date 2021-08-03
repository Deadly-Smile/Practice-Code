#include<stdio.h>
int main()
{
    int num_1,num_2,loop_count,backup;
    scanf("%d",&num_1);
    scanf("%d",&num_2);
    if(num_2>num_1)
    {
        backup=num_1;
        num_1=num_2;
        num_2=backup;
    }
    backup=1;

    for(loop_count=2;loop_count<=num_2;loop_count++)
    {
        if(num_1%loop_count==0&&num_2%loop_count==0)
        {
            if(backup<loop_count)
            {
                backup=loop_count;
            }
        }
    }
    printf("H.C.F:%d",backup);
    return 0;
}
