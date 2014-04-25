#include <stdio.h>
#include <string.h>
// from http://jvns.ca/blog/2013/10/28/day-17-buffer-overflows/
// from http://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc/
// http://www.thegeekstuff.com/2013/06/buffer-overflow/
// http://www.linuxfromscratch.org/hints/downloads/files/ssp.txt
// http://multimedia.cx/eggs/heroic-defender-of-the-stack/
char password[] = "meat";

void foo(void) {
  printf("Stack smashed! You should not see this: %s\n", password);
  fflush(stdout);
}


int main(int argc, char *argv[]) {
  char buf[4];

  printf("Here is the address of foo: %p\nEnter a string: ", foo);
  fflush(stdout);

  gets(buf);

  printf("You entered: %s\n", buf);
  fflush(stdout);

  return 0;
}
