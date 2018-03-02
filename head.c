/*
Author: Tenzing Rabgyal
Course: CS-GY 6223 Spring 2018
Instructor: Kamen Yotov
Assignment: HW1 Part 2 & 3
*/

#include "types.h"
#include "stat.h"
#include "user.h"

char buf[2048];

void head(int fd, int numLines)
{
	int i, n; //n indicates number of bytes read (zero indicates EOF) and the file position is advanced by this number.
	int l = 0;

	n = read(fd,buf,sizeof(buf)); //read is a system call. Read bytes from an open file into buf.

	while ((n > 0) && (l < numLines)) //n = 0 indicates EOF. If l = numLines, we have completed printing the last line on the screen.
	{
		for (i = 0;l < numLines; i++)
		{
			if (buf[i] == '\n')
			{
				printf(1, "\n");
				l++; //Increment l by 1 
			}
			else
			{
				printf(1,"%c",buf[i]);
			}
		}

	}
	if (n < 0) //-1 is returned by the read system call if there is an error.
	{
		printf(1, "Error: Cannot read [This is inside the head function] \n");
		exit(); //system call that terminates the current process
	}
}


int main(int argc, char *argv[]) //argc is arguement count (Ex. "echo hi" are two arguements). argv is arguement vector.
{
	int fd;

	// No arguement is passed
	if (argc == 1)
	{
                head(0, 10); //fd = 0, the number of lines to read from the standard input is 10.
                exit();     // SYSTEM CALL
	}

	//Either the filename is given, or the number of lines is specified
	else if (argc == 2)
	{
		char secondArg[256];
		strcpy(secondArg, argv[1]); //Copy the string from argv[1] into the array

		if (argv[1][0] == '-') //If the first array index holds '-', it means the the second arg represents the number of lines
		{
			char *ptr = secondArg; //Point to the first index of the array Arg, which holds '-'
			ptr += 1; // Increment the pointer by a byte (sizeof char is 1 byte). ptr now points to the digit, not '-'
			int numLines = atoi(ptr); //atoi function will convert the STRING (not just one char) to an integer.

			head(0, numLines); //There is no file to read, so 0 indicates that it needs to read from standard input
			exit();
		}
		else //Else, we know that the second arguement (argv[1]) is a filename
		{
			if((fd = open(argv[1], 0)) < 0) //fd should never be a negative number. So this is just a checker
			{
				printf(1, "Error: cannot open %s\n", argv[1]);
				exit();
			}
			head(fd, 10); //If the number of lines is not specified, the default is 10 lines
			close(fd);
		}
	}

	//Both the number of lines and the file name is specified
	else if (argc == 3)
	{
		char secondArg[256];
		strcpy(secondArg, argv[1]);
		
		if (argv[1][0] == '-')
		{
			char *ptr = secondArg;
			ptr += 1;
			int numLines = atoi(ptr);

			if((fd = open(argv[2], 0)) < 0) //fd should never be a negative number.
			{
				printf(1, "Error: cannot open %s\n", argv[2]);
				exit();
			}
			head(fd,numLines);
			close(fd);
		}
		else
		{
			printf(1, "Error: The second arguement does not represent a number.\n");
			exit();
		}
	}
	//The number of arguements from the command line is greater than 3
	else
	{
		printf(1,"Error: The number of arguements is invalid\n");
	}

	exit(); //system call
}
