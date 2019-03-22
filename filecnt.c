//Jason Garza jcg170530

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ftw.h>
#include "version.h"

static double version = 1.2;

int fCount, dCount, bCount;

int process(const char *fpath, const struct stat * sb, int typeflag)
{
	if(S_ISREG(sb->st_mode)) //if file is regular file (not link)
	{
		if(access(fpath, R_OK) == 0) //if you have read access to file
		{
			//increment file count, add size in bytes to byte count
			fCount++;
			bCount += sb->st_size;
		}
	}
	else if(S_ISDIR(sb->st_mode)) //if file is directory, increment directory count
	{
		dCount++;
	}
	return 0; //return 0 so it continues
}

int main(int argc, char * argv[])
{
	displayVersion(version);
	fCount = bCount = 0;
	dCount = -1; //directory entered in command is counted, don't count that one

	ftw(argv[1], process, 20); //recursively go through directory

	if(dCount == -1) //if directory entered doesn't exist
	{
		dCount = 0;
	}
	
	//display output
	printf("The total number of directories in directory %s is: %d\n", argv[1], dCount); 
	printf("The total number of files in directory %s  is: %d\n", argv[1], fCount);
	printf("The total number bytes occupied by all files in directory %s is: %d\n", argv[1], bCount);
}
