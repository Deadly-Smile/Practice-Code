#include<stdio.h>
#include<math.h>
int main()
{
    float hand_1,hand_2,hand_3,half_para,area;
    printf("First hand :");
    scanf("%f",&hand_1);
    printf("Second hand :");
    scanf("%f",&hand_2);
    printf("Third hand :");
    scanf("%f",&hand_3);
    if( hand_3>hand_2+hand_1 || hand_2>hand_1+hand_3 )     // ensuring this is a triangle
    {
        printf("\nIt not a triangle !!");
    }
    else if(hand_1>hand_2+hand_3)
    {
        printf("\nIt not a triangle !!");
    }
    else      // if this is a triangle
    {
        half_para=(hand_1+hand_2+hand_3)/2;
        area=(half_para*(half_para-hand_1)*(half_para-hand_2)*(half_para-hand_3));
        area=(float)pow(area,.5);
        printf("\nThe area of triangle is : %.4f",area);
    }
    return 0;
}
