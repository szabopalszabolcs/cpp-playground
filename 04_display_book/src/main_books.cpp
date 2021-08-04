#include <string.h>
#include <iostream>

// Define the maximum length for the name to use.
// Specify the length of characters in the content (Excluding the terminator).
#define MAX_NAME_LEN 25
#define MAX_TITLE_LEN 50
#define MAX_NR_OF_AUTHORS 10

struct Author
{
	char name[MAX_NAME_LEN + 1];

	void setName(char nameToSet[])
	{
		strncpy(name, nameToSet, MAX_NAME_LEN);
		name[MAX_NAME_LEN] = 0;
	}
	
	void print()
	{
		std::cout << name << std::endl;
	}
};

struct Book
{
	int id;
	char title[MAX_TITLE_LEN];
	int numAuthors;
	Author authors[MAX_NR_OF_AUTHORS];

	void addAuthor(Author author)
	{
		if (numAuthors >= MAX_NR_OF_AUTHORS)
		{
			std::cout << "You reached the maximum number of possible authors" << std::endl;
		}
		authors[numAuthors] = author;
		numAuthors++;
	}

	void print()
	{
		std::cout << "Book #" << id << std::endl;
		std::cout << "------" << std::endl;
		std::cout << this->title << std::endl;
		switch (numAuthors)
		{
		case 0:
			std::cout << "No Author" << std::endl;
			break;
		case 1:
			std::cout << "Author" << std::endl;
			std::cout << "------" << std::endl;
			authors[0].print();
			std::cout << std::endl;
			break;
		default:
			std::cout << "Authors" << std::endl;
			std::cout << "------" << std::endl;
			for (int i = 0; i < numAuthors;i++)
			{
				authors[i].print();
			}
			std::cout << std::endl;
		}
	}
};

void setBookName(Book& book, std::string name)
{
	strncpy(book.title, name.c_str(), MAX_TITLE_LEN);
}

int main()
{
	Book book1;
	Book book2;
	Book book3;
	Author author;

	// Load the data into books
	book1.id = 1;
	book1.numAuthors = 0;
	setBookName(book1,"The origin of truth (nu există, nu o căutați)");
	author.setName("Gusti");
	book1.addAuthor(author);

	book2.id = 2;
	book2.numAuthors = 0;
	setBookName(book2, "Arhanghelul Raul");
	author.setName("Ovidiu Eftimie");
	book2.addAuthor(author);

	book3.id = 3;
	book3.numAuthors = 0;
	setBookName(book3, "Factfulness");
	author.setName("Hans Rosling");
	book3.addAuthor(author);

	author.setName("Ola Rosling");
	book3.addAuthor(author);
	
	author.setName("Anna Rosling Ronnlund");
	book3.addAuthor(author);

	// Display the books
	book1.print();
	book2.print();
	book3.print();

	// Adding Book #4
	Book book4;

	book4.id = 4;
	book4.numAuthors = 0;
	setBookName(book4, "Clean Architecture: A Craftsman's Guide to Software Structure and Design");
	author.setName("Robert C. Martin");
	book4.addAuthor(author);

	// Display the new book
	book4.print();

	getchar();

	return 0;
}