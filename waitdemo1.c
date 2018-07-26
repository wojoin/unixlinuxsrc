#include <unistd.h>
#include <stdio.h>

#define DELAY 2
void child(int delay);
//void parent(int childpid);
void parent(int childpid1, int childpid2);


int main(int argc, char const *argv[])
{
	
	int childpid, newpid2;
	printf("before: mypid is %d\n", getpid());

	childpid = fork();

	if(childpid == 0)
		child(DELAY);
	
	newpid2 = fork();
	if(newpid2 == 0)
		child(DELAY);

	//parent(childpid);
	parent(childpid, newpid2);

	return 0;
}


void child(int delay)
{
	printf("child %d will sleep for %d seconds\n", getpid(), delay);
	sleep(2);
	printf("child done. about to exit\n");
	exit(17);
}

// void parent(int childpid)
// {
// 	int waitret;
// 	waitret = wait(NULL);
// 	printf("done waiting for %d. Wait return: %d\n", childpid, waitret);
// }

void parent(int childpid1, int childpid2)
{
	int waitret;
	printf("waiting for %d and %d\n", childpid1, childpid2);

	waitret = wait(NULL);
	printf("Wait returned: %d\n", waitret);

	waitret = wait(NULL);
	printf("Wait returned: %d\n", waitret);

}