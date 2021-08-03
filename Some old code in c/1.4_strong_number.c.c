#include<stdio.h>
int  main()
    {
    int num,loop_control,rem,sum=0,mul=1,res;
    scanf("%d",&num);
    res=num;
    while(num>0)
    {
        rem = num % 10;
        num /= 10;
        for(loop_control=1; loop_control<=rem; loop_control ++)
        {
            mul*=loop_control;
        }
       sum+=mul;
       mul=1;
    }
    if(sum==res)
    {
        printf("strong");
    }
    else
    {
    printf("not strong");
    }

    return 0;
}
