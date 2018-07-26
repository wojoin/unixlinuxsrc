/** ------------------------------------------------------------
	A program that uses SIGCHLD to notify the parent that
	a child has exited is
	sol08.9.c.
	This solution shows how a program can perform other tasks while
	a child process runs.  A parent does not have to stop
	activity to wait for a child.

 ** ------------------------------------------------------------
 **
 **
 *   A version of waitdemo2.c that uses SIGCHLD to notify the parent
 *   when a child is done.  
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

#define DELAY 5
void child(int delay);
void parent(int childpid);
void getchildstatus(int sig);


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
	sleep(delay);
	printf("child done. about to exit\n");
	exit(42); // setting exit code, parent process can obtain this value from parameter status with wait(&status)
}

void parent(int childpid)
{
	signal(SIGCLD, getchildstatus); // 设置信号处理函数

	while(1)
	{
		printf("waiting for %d...\n", childpid);
		sleep(1);
	}
}

void getchildstatus(int sig)
{
	int waitret;
	int child_status;
	int high8,low7,bit7;

	waitret = wait(&child_status);
	printf("done waiting for child. Wait return: %d\n", waitret);

	// print child exit status
	high8 = child_status >> 8; // WEXITSTATUS(child_status)
	low7 = child_status & 0x7F; // WCOREDUMP(child_status)
	bit7 = child_status & 0x80; // WTERMSIG(child_status)
	printf("status: exit = %d, sig = %d, core = %d\n", high8, low7, bit7);

	exit(0); //parent退出
}