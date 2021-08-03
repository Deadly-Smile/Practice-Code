#include<stdio.h>
int main()
{
    float hand,area,volume;
    printf("The length of each hand :");
    scanf("%f",&hand);
    area=6*hand*hand;
    volume=hand*hand*hand;
    printf("\nThe surface area of cube is : %.4f ",area);
    printf("\nThe volume of cube is : %.4f ",volume);
    return 0;
}
