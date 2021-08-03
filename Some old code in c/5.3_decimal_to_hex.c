#include<stdio.h>
int main()
{
    int num,proxy,count=0,loop_count;
    scanf("%d",&num);
    proxy=num;
    while(num>0) //finding the number of hex digits
    {
        num/=16;
        count++;
    }
    num=proxy;
    char hex_value[count];
    for(loop_count=0;num>0;loop_count++) //getting hex digits
    {
        hex_value[loop_count]=num%16;
        num/=16;
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
            case 'F' : {
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
