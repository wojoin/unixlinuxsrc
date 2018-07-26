#include <unistd.h>
#include <stdio.h>

#define DELAY 2
void child(int delay);
void parent(int childpid);


int main(int argc, char const *argv[])
{
	
	int childpid;
	printf("before: mypid is %d\n", getpid());

	childpid = fork();

	if(childpid == 0)
		child(DELAY);
	else if(childpid > 0)
		parent(childpid);


	return 0;
}


void child(int delay)
{
	printf("child %d will sleep for %d seconds\n", getpid(), delay);
	sleep(2);
	printf("child done. about to exit\n");
	exit(17);
}

void parent(int childpid)
{
	int waitret;
	waitret = wait(NULL);
	printf("done waiting for %d. Wait return: %d\n", childpid, waitret);
}