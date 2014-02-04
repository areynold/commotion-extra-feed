#include <stdio.h>
#include <string.h>
// from http://jvns.ca/blog/2013/10/28/day-17-buffer-overflows/
// from http://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc/
// http://www.thegeekstuff.com/2013/06/buffer-overflow/
char password[] = "meat";

void foo(void) {
  printf("Stack smashed! You should not see this: %s\n", password);
  fflush(stdout);
}

int main(int argc, char *argv[]) {
  char buf[4];

  printf("Dummy password function to test stack protection\n \
        to test, run ./smash and enter a string.\n \
        * string 'commotion' should return 'Match. Root privileges given...'\n \
        * a string less than 9 characters should return 'No match'\n \
        * Without stack protection, a string greater than 10 characters should return 'No match. Root privileges given...'\n \
        * With stack protection, a string greater than 10 characters should return an error and abort\n\n");


  printf("Here is the address of foo: %p\nEnter a string: ", foo);
  fflush(stdout);

  gets(buf);

  printf("You entered: %s\n", buf);
  fflush(stdout);

  return 0;
}
