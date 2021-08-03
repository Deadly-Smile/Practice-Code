#include<stdio.h>
int main()
{
    int num_1,num_2,loop_count,backup,backup_1;
    scanf("%d",&num_1);
    scanf("%d",&num_2);
    if(num_2>num_1)
    {
        backup=num_1;
        num_1=num_2;
        num_2=backup;
    }
    backup=num_1*num_2;
    backup_1=backup;
    if(num_1%num_2==0)
    {
        backup/=num_2;
        printf("L.C.M. : %d",backup);
    }
    if(num_1%num_2>0)
    {
        for(loop_count=2;loop_count<=num_2/2;loop_count++)
        {
            if(num_1%loop_count==0&&num_2%loop_count==0)
            {
                backup=backup_1;
                backup/=loop_count;
            }
        }
        printf("L.C.M. : %d",backup);
    }
    return 0;
}
