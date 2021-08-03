#include<stdio.h>
int main()
{
    int i,j;
    int loop_1,loop_2;
    int mul=1,sum=0;


    int row1,col1,row2,col2;
    printf("Enter the formate of first matrix :");
    scanf("%d %d",&row1,&col1);                 //     taking forms of matrices from user
    printf("Enter the formate of second matrix :");
    scanf("%d %d",&row,&col2);



    if(col1!=row2 )
    {
        printf("Matrices can not be multiplyed !!!!");    //     cheaking if matrices can be multiplyed or not
    }
    else{

    int matrix1[row1][col1],matrix2[row2][col2],matrix3[row1][col2];

    printf("Enter the values of first matrix :\n ");

    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)  //   taking input of first matrix from user
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("\nThe first matrix :\n");
     for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)  //   printing first matrix
        {
            printf("%d  ",matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Enter the values of second matrix :\n ");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)    //   taking input of second matrix from user
        {
            scanf("%d",&matrix2[i][j]);
        }
    }

    printf("\nThe second matrix :\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)   //   printing second matrix
        {
            printf("%d  ",matrix2[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<row1;i++)   //   proscces
    {
        for(j=0;j<col2;j++)
        {
            for(loop_1=0;loop_1<col1;loop_1++)
            {
                for(loop_2=0;loop_2<2;loop_2++)
                {
                    if(loop_2%2==0)
                    {
                    mul*=matrix1[i][loop_1];
                    }
                    else{
                        mul*=matrix2[loop_1][j];
                    }
                }

                sum+=mul;
                mul=1;
            }
            matrix3[i][j]=sum;
            sum=0;
        }
    }


    printf("\nThe result :\n");
    for(i=0;i<col2;i++)
    {
        for(j=0;j<row1;j++)  //   printing the result matrix
        {
            printf("%d  ",matrix3[i][j]);
        }
        printf("\n");
    }
    }


    return 0;
}
