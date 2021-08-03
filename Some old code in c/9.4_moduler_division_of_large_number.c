#include<stdio.h>
int main()
{
    long long int num,moduler;
    printf("The number to module :");
    scanf("%lli",&num);
    printf("The moduler :");
    scanf("%lli",&moduler);
    num=num%moduler;
    printf("%lli",num);
    return 0;
}
