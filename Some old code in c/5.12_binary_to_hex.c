#include<stdio.h>
#include<math.h>
int main()
{
    int rem,num,sum=0,loop_count,count=0,proxy;
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10; //getting bit one by one
        num/=10; //removing bit from right-side
        rem*=(float)pow(2,count);
        count++;
        sum+=rem;
    }
    count=0;
    proxy=sum;
    while(sum>0) //finding the number of hex digits
    {
        sum/=16;
        count++;
    }
    sum=proxy;
    char hex_value[count];
    for(loop_count=0;sum>0;loop_count++) //getting hex digits
    {
        hex_value[loop_count]=sum%16;
        sum/=16;
        if(hex_value[loop_count]==10)
        {
            hex_value[loop_count]='A';
        }
        else if(hex_value[loop_count]==11)
        {
            hex_value[loop_count]='B';
        }
        else if(hex_value[loop_count]==12)
        {
            hex_value[loop_count]='C';
        }
        else if(hex_value[loop_count]==13)
        {
            hex_value[loop_count]='D';
        }
        else if(hex_value[loop_count]==14)
        {
            hex_value[loop_count]='E';
        }
        else if(hex_value[loop_count]==15)
        {
            hex_value[loop_count]='F';
        }
    }
    for(proxy=loop_count-1;proxy>=0;proxy--) //printing hex value
    {
        switch(hex_value[proxy])
        {
            case 'A' : {
                        printf("%c",hex_value[proxy]);
                        break;
                       }

            case 'B' : {
                        printf("%c",hex_value[proxy]);
                        break;
                       }
            case 'C' : {
                        printf("%c",hex_value[proxy]);
                        break;
                       }
            case 'D' : {
                        printf("%c",hex_value[proxy]);
                        break;
                       }
            case 'E' :{
                        printf("%c",hex_value[proxy]);
                        break;
                       }
            case 'F' :{
                        printf("%c",hex_value[proxy]);
                        break;
                       }
            default  : {
                        printf("%d",hex_value[proxy]);
                        break;
                       }
            }
    }
    return 0;
}

