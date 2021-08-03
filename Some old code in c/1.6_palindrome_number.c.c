#include<stdio.h>
int main()
{
    int a,i=1,num,sum=0,digit_count=0,b,d,j,k=0;
    scanf("%d",&num);
    d=num;
    while(num>0)
    {
        num/=10;
        digit_count++;
    }
    num = d;
    for(a=0;a<digit_count;a++)
    {
        b=num%10;
        // this loop work as a power function
        for(j=a+1;j<digit_count;j++)
            {
                i = i*10;
            }
            k = b*i;
        sum+=k;
        num/=10;
        i = 1;
    }
    printf("\n%d",sum);

    // checking for palaindrom
    if(d==sum){printf("\npaldomic");}
    else{printf("\nnot paldomic");}
    return 0;
}
