#include <stdio.h>
#include <string.h>
// from http://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc/
// http://www.thegeekstuff.com/2013/06/buffer-overflow/
int main(void)
{
    char buff[9];
    int pass = 0;

    printf("Dummy password function to test stack protection\n \
	to test, run ./smash and enter a string.\n \
	* string 'commotion' should return 'Match. Root privileges given...'\n \
	* a string less than 9 characters should return 'No match'\n \
	* Without stack protection, a string greater than 10 characters should return 'No match. Root privileges given...'\n \
	* With stack protection, a string greater than 10 characters should return an error and abort\n\n");
	

    printf("\n Enter a string: \n");
    gets(buff);

    if(strcmp(buff, "commotion"))
    {
        printf ("\n No match \n");
    }
    else
    {
        printf ("\n Match \n");
        pass = 1;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("Root privileges given to the user \n");
    }

    return 0;
}
