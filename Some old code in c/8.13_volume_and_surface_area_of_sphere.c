#include<stdio.h>
int main()
{
    float radius,area,volume;
    printf("Radius :");
    scanf("%f",&radius);
    area=4*3.1416*radius*radius;
    volume=(4*3.1416*radius*radius*radius)/3;
    printf("\nThe surface area of sphere is : %.4f ",area);
    printf("\nThe volume of sphere is : %.4f ",volume);
    return 0;
}
