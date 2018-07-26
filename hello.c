#include <stdio.h>
#include <sys/wait.h>

#define WEXITSTATUS1(status)   (((status) & 0xff00) >> 8)


int main()
{
	short n = 256;
	short s = n >> 8;

	short n2 = 0x100;

	int status = 256; // 0x100
	int res = status & 0xff00;

	printf("%d & 0xff00 = %d\n", status, res);
	printf("exited, status=%d\n", WEXITSTATUS1(status)); // 1
	printf("status=%d\n", status);
	printf("%d\n", n2 >> 8); // 1
	printf("%d\n", s); // 1

	printf("%d\n", sizeof(int));
	return 0;
}
