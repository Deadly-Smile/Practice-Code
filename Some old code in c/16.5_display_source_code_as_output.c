#include <stdio.h>
int main() {
    FILE *flp;
    int c;
    flp = fopen(__FILE__,"r");
    while(c!=EOF)
    {
        c = getc(flp);
        printf("%c",c);
    }
    fclose(flp);
    return 0;
}
