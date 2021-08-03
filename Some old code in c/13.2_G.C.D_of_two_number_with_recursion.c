#include<stdio.h>
int gcd(int a,int b,int c);
int main()
{
    int num_1,num_2,result=1,backup;
    scanf("%d%d",&num_1,&num_2);
    backup=num_1;
    result=gcd(num_1,num_2,backup);
    printf("The gcd : %d",result);
    return 0;
}

int gcd(int num_1,int num_2,int backup)
{
    if(backup>0)
    {
        if( num_1%backup==0 && num_2%backup==0 )
        {
            return backup;
        }
        else{
            gcd(num_1,num_2,backup-1);
        }
    }
    else{
        return 1;
    }
}
