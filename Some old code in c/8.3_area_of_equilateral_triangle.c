#include<stdio.h>
#include<math.h>
int main()
{
    float hand,area;
    printf("Length of hand :");
    scanf("%f",&hand);
    area=(float)pow(3,.5)/4;
    area*=(float)pow(hand,2);
    printf("\nThe area of equilateral triangle is : %.4f ",area);
    return 0;
}
