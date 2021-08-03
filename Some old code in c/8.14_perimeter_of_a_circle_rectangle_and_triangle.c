#include<stdio.h>
int main()
{
    float radius_of_circle,perimeter_of_circle;
    printf("Radius :");
    scanf("%f",&radius_of_circle);
    perimeter_of_circle=2*3.1416*radius_of_circle;
    printf("\nThe perimeter of circle :%.4f",perimeter_of_circle);
    float length_of_rectangle,width_of_rectangle,perimeter_of_rectangle;
    printf("\nlength of rectangle :");
    scanf("%f",&length_of_rectangle);
    printf("width of rectangle :");
    scanf("%f",&width_of_rectangle);
    perimeter_of_rectangle=2*length_of_rectangle*width_of_rectangle;
    printf("\nThe perimeter of rectangle :%.4f",perimeter_of_rectangle);
    float hand_1,hand_2,hand_3,perimeter_of_triangle;
    printf("\nThe first hand :");
    scanf("%f",&hand_1);
    printf("The second hand :");
    scanf("%f",&hand_2);
    printf("The third hand :");
    scanf("%f",&hand_3);
    perimeter_of_triangle=hand_1+hand_2+hand_3;
    printf("\nThe perimeter of triangle :%.4f",perimeter_of_triangle);
    return 0;
}
