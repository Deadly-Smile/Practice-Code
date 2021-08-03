#include<stdio.h>
int main()
{
    float radius,height,length_of_slant,area,volume;
    printf("Radius :");
    scanf("%f",&radius);
    printf("height :");
    scanf("%f",&height);
    printf("length_of_slant :");
    scanf("%f",&length_of_slant);
    area=(3.1416*radius*(radius+length_of_slant));
    volume=(3.1416*radius*radius*height)/3;
    printf("\nThe surface area of cone is : %.4f ",area);
    printf("\nThe volume of cone is : %.4f ",volume);
    return 0;
}
