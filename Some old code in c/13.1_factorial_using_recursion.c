#include<stdio.h>
int fac_recursion(int a);
int main()
{
    int num,result=1;
    scanf("%d",&num);
    result=fac_recursion(num);
    printf("%d",result);
    return 0;
}

int fac_recursion(int num)
{
    int result=1;
    if(num>0)
    {
        result=num*fac_recursion(num-1);
    }
    return result;
}
