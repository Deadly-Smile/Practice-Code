#include<stdio.h>
int main()
{
    float base,height,area;
    printf("The base :");
    scanf("%f",&base);
    printf("The height :");
    scanf("%f",&height);
    area=(base*height);
    printf("\nThe area of parallelogram is : %.4f ",area);
    return 0;
}
