#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2)
	{
		printf("error input!\n");
		return 0;
	}
	if((dp = opendir(argv[1])) == NULL)
	{
		printf("can not open %s\n", argv[1]);
		return 0;
	}
	while((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);

	return 0;
}
