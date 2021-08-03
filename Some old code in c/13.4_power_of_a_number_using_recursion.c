#include<stdio.h>
#include<math.h>
int rooting(int num,int backup);

int main()
{
    int num,power,backup;
    float useless;
    scanf("%d",&num);
    backup=num;
    power=rooting(num,backup);
    useless=(float)1/power;
    num=(float)pow(num,useless);
    printf("The %d is : %d^%d",backup,num,power);
    return 0;
}

int rooting(int num,int backup)
{
    float fraction,useless;
    int cheaking;
    if(backup>0)
    {
        useless=(float)1/backup;
        fraction=(float)pow(num,useless);
        cheaking=fraction;
        if(fraction-cheaking<=0.0000)
        {
            return backup;
        }
        else{
            rooting(num,backup-1);
        }
    }
    else{
        return 0;
    }
}
