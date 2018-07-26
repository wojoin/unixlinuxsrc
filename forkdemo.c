#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int childpid, mypid;

	mypid = getpid();
	printf("Before: my pid is %d\n",mypid);
	childpid = fork();

	if(childpid > 0)
		printf("parent, mychild is %d\n", childpid);
	else if(childpid == 0)
		printf("child, my pid is %d\n",getpid());

	return 0;
}
