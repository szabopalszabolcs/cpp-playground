#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void printOddOrEven(int number)
{
	if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	else
	{
		printf("ODD\n");
	}
}

int main(int argc, char *argv[])
{
	int number = -13;

	// What is this program expected to do?
	// - Shows whether an argument is an ODD or EVEN number.
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  02_odd_even.exe 1		=> Output: ODD
	//		  02_odd_even.exe 2		=> Output: EVEN
	//		  02_odd_even.exe 		=> Output: No program arguments found.
	//		  02_odd_even.exe ABC   => Undefined output (do whatever).
	//		

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
		getchar();
		return 0;
	}
	
	// Get the first argument
	string argumentAsString = argv[1];
	
	// try to convert string to int
	try
	{
		string::size_type str;
		int argumentAsInteger = stoi(argumentAsString,&str);
		// if conversion succeded it is checking that there is no leftover characters in the initial argument
		if ( argumentAsString.substr(str).length() == 0) { 
			printOddOrEven(argumentAsInteger);
			getchar();
			return 0;
		}
		else
		{
			printf("NAN\n");
			getchar();
			return 0;
		}
	}
	// if the conversion isn't succesfull
	catch (exception ex)
	{
		printf("NAN\n");
		getchar();
		return 0;
	}

}