#include<stdio.h>
int main()
{
    int N,R,value,loop_1,mul_n=1,mul_r=1,mul_nr=1;
    scanf("%d",&N);
    scanf("%d",&R);
    if(N>R)
    {
        for(loop_1=1;loop_1<=N;loop_1++)
        {
            mul_n*=loop_1;
        }
        for(loop_1=1;loop_1<=R;loop_1++)
        {
            mul_r*=loop_1;
        }
        for(loop_1=1;loop_1<=N-R;loop_1++)
        {
            mul_nr*=loop_1;
        }
        value=(mul_n/(mul_nr*mul_r));
        printf("\n%d",value);
    }
    if(N==R)
    {
        printf("\n1");
    }
    if(N<R)
    {
        printf("First number should be large");
    }
    return 0;
}
