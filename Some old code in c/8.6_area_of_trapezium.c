#include<stdio.h>
int main()
{
    float base_1,base_2,height,area;
    printf("The first base :");
    scanf("%f",&base_1);
    printf("The second base :");
    scanf("%f",&base_2);
    printf("The height :");
    scanf("%f",&height);
    area=(base_1+base_2)*.5*height;
    printf("\nThe area of trapezium is : %.4f ",area);
    return 0;
}
