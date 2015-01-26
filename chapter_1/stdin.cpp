#include <unistd.h>
#include <stdio.h>

int main()
{
	int n;
	char buf[1024];
	while((n = read(STDIN_FILENO, buf, 1024)) > 0)
	{
		if(write(STDOUT_FILENO, buf, n) != n)
		{
			printf("write error\n");
		}
	}
	if(n < 0)
	{
		printf("read error");
	}
	return 0;
}
