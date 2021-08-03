#include<stdio.h>
int main()
{
    float hand_1,hand_2,area;
    printf("The first hand :");
    scanf("%f",&hand_1);
    printf("The second hand :");
    scanf("%f",&hand_2);
    area=(hand_1*hand_2)/2;
    printf("\nThe area of rhombus is : %.4f ",area);
    return 0;
}
