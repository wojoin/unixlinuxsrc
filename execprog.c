#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *arglist[3];
	arglist[0] = "ls";
	arglist[1] = "-l";
	arglist[2] = 0;
	printf("*** about to exec ls -l ***\n");
	// search file,ls from the PATH environment variable
	execvp("ls", arglist);

	printf("*** ls -l is done. ***\n");

	return 0;
}
