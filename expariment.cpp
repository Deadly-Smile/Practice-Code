#include<stdio.h>

int main ()
{
       int i,j,m,n,a[100][100],b[100][100];
       printf("enter the row and columns of a matrix:\n");
       scanf("%d%d",&m,&n);
       printf("enter the element of a matrix:\n");
       for(i=0;i<m;i++)
       {
              for(j=0;j<n;j++)
              {
                     scanf("%d",&a[i][j]);
              }
       }
       printf("enter a matrix:\n");
         for(i=0;i<m;i++)
       {
              for(j=0;j<n;j++)
              {
                     printf("%d\t",a[i][j]);
              }
              printf("\n");

       }  for(i=0;i<m;i++)
       {
              for(j=0;j<n;j++)
              {
          b[j][i]=a[i][j];
              }
              }
     printf("transpose matrix:\n");

       for(i=0;i<m;i++)
       {
              for(j=0;j<n;j++)
              {
                    printf("%d\t",b[i][j]);
              }
              printf("\n");
       }

       return 0;
}