#include <iostream>

void printMessageFor(const char* name)
{
	std::cout << "Hello from [" << name << "]" << std::endl;
}

void printMessage()
{
	printMessageFor("Szabo Pal-Szabolcs");
}

int main()
{
	printMessage();
	getchar();
}

