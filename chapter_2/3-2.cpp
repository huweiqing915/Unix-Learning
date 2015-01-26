#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		perror("create error");
	}

	if(write(fd, buf1, 10) != 10)
	{
		perror("buff1 write error");
	}

	if(lseek(fd, 16000, SEEK_SET) == -1)
	{
		perror("lseek error");
	}

	if(write(fd, buf2, 10) != 10)
	{
		perror("buf2 write error");
	}

	return 0;
}
