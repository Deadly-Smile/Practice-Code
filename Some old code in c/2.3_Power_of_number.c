#include<stdio.h>
#include<math.h>
int main()
{
    int loop_c,power=1,num,num_1;
    float useless,float_value;
    scanf("%d",&num);
    for(loop_c=2 ; loop_c <= (num/2) ; loop_c ++)
    {
        useless=(float)1/loop_c;
        float_value=(float)pow(num,useless);

        num_1=float_value;
        float_value-=(float)num_1;
        if(float_value<=0.0000)
        {
            power*=loop_c;
            num=num_1;
            loop_c=1;
        }
    }
    printf("\n%d ^ %d ",num,power);
return 0;
}
