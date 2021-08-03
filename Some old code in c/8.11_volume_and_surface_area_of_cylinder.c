#include<stdio.h>
int main()
{
    float radius,height,area,volume;
    printf("The radius :");
    scanf("%f",&radius);
    printf("The height :");
    scanf("%f",&height);
    area=(2*3.1416*radius*height)+(2*3.1416*radius*radius);
    volume=3.1416*radius*radius*height;
    printf("\nThe surface area of cylinder is : %.4f ",area);
    printf("\nThe volume of cylinder is : %.4f ",volume);
    return 0;
}
