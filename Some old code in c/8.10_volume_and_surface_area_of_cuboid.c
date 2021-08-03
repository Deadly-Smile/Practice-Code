#include<stdio.h>
int main()
{
    float hand_1,hand_2,hand_3,area,volume;
    printf("The first hand :");
    scanf("%f",&hand_1);
    printf("The second hand :");
    scanf("%f",&hand_2);
    printf("The third hand :");
    scanf("%f",&hand_3);
    area=((2*hand_1*hand_2)+(2*hand_1*hand_3)+(2*hand_2*hand_3));
    volume=hand_1*hand_2*hand_3;
    printf("\nThe surface area of cuboid is : %.4f ",area);
    printf("\nThe volume of cuboid is : %.4f ",volume);
    return 0;
}

