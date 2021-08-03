#include<stdio.h>
int getting_gcd(int a,int b);
int main()
{
    int num_1,num_2,gcd;
    scanf("%d%d",&num_1,&num_2);
    gcd=getting_gcd(num_1,num_2);
    printf("The G.C.D is : %d",gcd);
    return 0;
}

int getting_gcd(int num_1,int num_2)
{
    int loop_count,gcd=1,count=0;
    for(loop_count=2;loop_count<=num_1;loop_count++)
    {
        if(num_1%loop_count==0&&num_2%loop_count==0)
        {
           gcd=loop_count;
           count++;
           printf("\n%d",count);
        }
    }
    return gcd;
}

