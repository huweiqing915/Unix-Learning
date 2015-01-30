#include "apueerror.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0) /*first child*/
	{
		if ((pid = fork()) < 0)
		{
			err_sys("second fork error");
		}
		else if (pid > 0) /*parent from second fork == first child */
		{
			printf("first child exit\n");
			exit(0); 
		}
		sleep(3); /*this is the second child*/
		printf("second child, parent id = %d\n", getpid());
		exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid)
	{
		err_sys("waitpid error");
	}
	exit(0);
}
