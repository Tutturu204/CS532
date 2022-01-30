README

HW_1
Student Surin Mikhail
CS 532

How to compile:
gcc <filename>.c -o <filename.exe>


How to execute:
./<filename.exe>

add comand line arguments:
./<filename.exe> <first_string> <second_string>...

example:
./test.exe s "s" This
both s and "s" works
space is a separator between words

read from file:
program reads line by line from a file in current directory with name "file.txt"
SO PLEASE RENAME TESTING FILE :)

Limits:
max line length = 255 char (line = all chars berore "\n")


THE MAIN IDEA:
command line agruments stored in the dynamic array;
read from a file line by line in a while loop;
	store current line in a temp array;
	check for each character in current line: 
		if sequence of char that starts from current char is equal to any sequence of chars in the cmd arg array;
		if find the equality store it in num_of_occurrences array;
print num_of_occurences array;

functions:

void print_array(int num[], **labels, int size)
	prints the final results.
	num -> number of patterns 
	labels -> cmd arg strings

	<label> : <num> -> "is" : 5

int compare_strings(char test [] , char buf [], int index, int size)
	compare 2 strings -> test and buff
	test -> array of char represents current cmd arg (command line argument)
	buf -> array of chars represent current line 
	index -> represents current index of line 
	size -> represents the length of a line

	it compares char by char;

	return 1 if find sequence; 0 otherwise

void fill_array (int array [], int size)

	fill the given array with special size with zeros
	needs for counting the patterns
	array= [0]*size (python analog)