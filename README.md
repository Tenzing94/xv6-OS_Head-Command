# xv6 "Implementing a HEAD Command"
### Assignment
#### Part 1
> Write a program that prints the first 10 lines of its input. If a filename is provided on the
command line (i.e., _head FILE_ ) then head should open it, read and print the first 10 lines, and
then close it. If no filename is provided, head should read from standard input. 
#### Part 2
> The traditional UNIX head utility can print out a configurable number of lines from the start of a
file. Implement this behavior in your version of _head_ . The number of lines to be printed should
be specified via a command line argument as _head -NUM FILE_ , for example _head -3 MYFILE_ to
print the first 3 lines of the file MYFILE. If the number of lines is not given (i.e., if the first argument does not start with - ), the number of lines to be printed should default to 10 as in the previous part.
