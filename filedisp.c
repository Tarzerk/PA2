//Jason Garza jcg170530 changes

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	//if option entered is valid option, set search string to correct string
	char * search;
	if(strcmp(argv[1], "-d") == 0)
	{
		search = "directories";
	}
	else if(strcmp(argv[1], "-f") == 0)
	{
		search = "files";
	}
	else if(strcmp(argv[1], "-b") == 0)
	{
		search = "bytes";
	}
	else //if option entered is invalid, print error message and end program
	{
		printf("Error: option must be -d, -f, or -b\n");
		return 0;
	}

	char * line = NULL;
	size_t len = 0;

	while(getline(&line, &len, stdin) != -1) //go through each line of standard input
	{
		if(strstr(line, search)) //if search string is in current line, print the line and end program
		{
			printf("%s\n", line);
			return 0;
		}
	}
	
	//if search string not found in standard input, print error message
	printf("Error: word %s not found in input", search);

	return 0;
}
