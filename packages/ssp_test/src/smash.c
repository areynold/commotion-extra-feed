#include <stdio.h>
#include <string.h>

/*
 / Basic test of gcc stack protector functions.
 / Contains both a dangerous function (gets)
 / allowing function foo to be targeted 
 / and an off-by-one error between the default password and the buffer length.
 /
 / Resources: 
 / from http://jvns.ca/blog/2013/10/28/day-17-buffer-overflows/
 / from http://www.thegeekstuff.com/2013/02/stack-smashing-attacks-gcc/
 / http://www.thegeekstuff.com/2013/06/buffer-overflow/
 / http://www.linuxfromscratch.org/hints/downloads/files/ssp.txt
 / http://multimedia.cx/eggs/heroic-defender-of-the-stack/
*/
char password[] = "meat";

void foo(void) {
	printf("Stack smashed! You should not see this: %s\n", password);
	fflush(stdout);
}


int main(int argc, char *argv[]) {
	// off-by-1 error will cause stack overflow using default password
	// stack-protector-all or -strong should catch this
	char buf[4];

	printf("Here is the address of foo: %p\nPassword is %s.\nRe-enter password: ", foo, password);
	fflush(stdout);

	// gets does not properly check array length
	// allows function foo to be targeted for attack
	gets(buf);

	printf("You entered: %s\n", buf);
	fflush(stdout);

	return 0;
}
