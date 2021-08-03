#include<stdio.h>
#include<math.h>
int main()
{
    int count_1=0,count_2=0;
    long long int num_1,num_2,divider,backup;
    double mul,proxy_num_1,proxy_num_2;
    scanf("%lli",&num_1);
    scanf("%lli",&num_2);
    backup=num_1;       //taking first number as scientific way
    while(backup>0)
    {
        backup/=10;
        count_1++;
    }
    divider=(double)pow(10,count_1-1);
    proxy_num_1=(double)num_1/divider;

    backup=num_2;     //taking second number as scientific way
    while(backup>0)
    {
        backup/=10;
        count_2++;
    }
    divider=(double)pow(10,count_2-1);
    proxy_num_2=(double)num_2/divider;

    mul=proxy_num_1*proxy_num_2;
    printf("The multiplication is : %lf X 10^%d",mul,count_1+count_2);

    return 0;
}
