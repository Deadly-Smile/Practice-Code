#include<stdio.h>
#include<math.h>
int main()
{
    int num_1,num_2,count=0,remain,sum_1=0,sum_2=0;
    scanf("%d",&num_1);
    scanf("%d",&num_2);
    while(num_1>0)
    {
        remain=num_1%10;
        num_1/=10;
        remain*=(float)pow(2,count);
        sum_1+=remain;
        count++;
    }
    count=0;
    while(num_2>0)
    {
        remain=num_2%10;
        num_2/=10;
        remain*=(float)pow(2,count);
        sum_2+=remain;
        count++;
    }
    sum_1=sum_1*sum_2;
    sum_2=0;
    count=0;
    while(sum_1>0)
    {
        remain=sum_1%2;
        sum_1/=2;
        remain*=(float)pow(10,count);
        sum_2+=remain;
        count++;
    }
    printf("\nThe result :%d",sum_2);

    return 0;
}
