#include<stdio.h>
void main()
{
    int matrix[3][3],sub_matrix[4];
    int substitude[9];
    float lol;
    int sum=0,mul,useless,count_for_s_m=0;

    int loop_count_1,loop_count_2,loop_count; // declaring loop control variables

    printf("Give the values of matrix :\n");
    for(loop_count_1=0;loop_count_1<3;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<3;loop_count_2++)  // taking values of matrix
        {
            scanf("%d",&matrix[loop_count_1][loop_count_2]);
        }
    }

    printf("\nThe matrix :\n");
    for(loop_count_1=0;loop_count_1<3;loop_count_1++)
    {
        for(loop_count_2=0;loop_count_2<3;loop_count_2++)  // printing the matrix
        {
            printf("%d  ",matrix[loop_count_1][loop_count_2]);
        }
        printf("\n");
    }

    for(loop_count=0;loop_count<3;loop_count++)
    {
        for(loop_count_1=0;loop_count_1<3;loop_count_1++)
        {
            for(loop_count_2=0;loop_count_2<3;loop_count_2++)
            {
                if(loop_count_1==0 || loop_count_2==loop_count)
                {
                    continue;
                }
                else {
                sub_matrix[count_for_s_m]=matrix[loop_count_1][loop_count_2];  // finding values to multiply and subtract
                count_for_s_m++;
                }
            }
        }
        if(loop_count==1)
        {
            mul=( (sub_matrix[2]*sub_matrix[1]) - (sub_matrix[0]*sub_matrix[3]) );
        }
        else{
        mul=( (sub_matrix[0]*sub_matrix[3]) - (sub_matrix[2]*sub_matrix[1]) );
        }
        useless =(int) matrix[0][loop_count];
        useless*=mul;
        sum+= useless;
        count_for_s_m=0;
    }
    useless=0;
    count_for_s_m=0;
    if(sum==0)
    {
        printf("\nThe matrix can not be inversed !");
    }
    else{
        for(int loop_count_3=0;loop_count_3<3;loop_count_3++)
        {
            for(loop_count_1=0;loop_count_1<3;loop_count_1++)
            {
                for(loop_count_2=0;loop_count_2<3;loop_count_2++)
                {
                    for(loop_count=0;loop_count<3;loop_count++)
                    {
                        if(loop_count_2==loop_count_3||loop_count==loop_count_1)
                        {
                            continue;
                        }
                        else{
                            sub_matrix[count_for_s_m]=matrix[loop_count_2][loop_count];  // finding values to multiply and subtract
                            count_for_s_m++;
                        }
                    }
                }
                if(useless%2==1)
                {
                    mul=( (sub_matrix[2]*sub_matrix[1]) - (sub_matrix[0]*sub_matrix[3]) );
                }
                else{
                    mul=( (sub_matrix[0]*sub_matrix[3]) - (sub_matrix[2]*sub_matrix[1]) );
                }
                substitude[useless]=mul;
                count_for_s_m=0;
                useless++;
            }
        }
        printf("\nThe inversed matrix :\n");
        for(loop_count=0;loop_count<9;loop_count++)
        {
            if(loop_count==3||loop_count==6)
            {
                printf("\n");
            }
            lol=(float)substitude[loop_count]/sum;
            printf("%f  ",lol);
        }
    }
}

