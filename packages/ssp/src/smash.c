#include <stdio.h>
#include <string.h>
// from http://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc/
// http://www.thegeekstuff.com/2013/06/buffer-overflow/
int main(void)
{
    int len = 0;
    char str[10] = {0};

    printf("\n Enter name \n");

    gets(str); // Used gets() to cause buffer overflow

    printf("\n len = [%d] \n", len);

    len  = strlen(str);
    printf("\n len of string entered is : [%d]\n", len);

    return 0;
}
