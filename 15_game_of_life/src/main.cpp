#include <iostream>
#include <string>
#include <vector>
#include "Matrix.cpp"

Matrix play(Matrix matrix);
int menuSelect(std::vector<std::string> menuString);
int selectInt(int min, int max,std::string question);
void pressKey(std::string text);

int main()
{
	int key;
	bool ok=true;
	std::vector<std::string> mainMenu = { "Initialize matrix", "Check my matrix", "Set a line", "Set a cell", "Set a pattern", "Play the game of life", "Quit" };
	std::vector<std::string> patternMenu = { "Block", "Boat", "Blinker", "Beacon", "Pulsar", "Pentadecathlon", "Glider", "Back to main menu" };
	Matrix matrix(20,20);
	key = menuSelect(mainMenu);
	do
	{
		switch (key)
		{
		case 1:
		{
			int h = selectInt(20, 40, "Please introduce the number of lines of the matrix ");
			int w = selectInt(20, 40, "Please introduce the number of columns of the matrix ");
			matrix.init(h, w);
			key = menuSelect(mainMenu);
			break;
		}
		case 2:
		{
			matrix.print();
			pressKey("Press Enter ");
			key = menuSelect(mainMenu);
			break;
		}
		case 3:
		{
			int row = selectInt(1, matrix.getSizeY(), "Please introduce the row you want to edit ");
			std::string rowString;
			std::cout << "Please introduce the row as a string" << std::endl 
				<< "'0'- dead cell, any other character - living cell" << std::endl;
			std::cin >> rowString;
			matrix.setLine(row - 1, rowString);
			key = menuSelect(mainMenu);
			break;
		}
		case 4:
		{
			int row = selectInt(1, matrix.getSizeY(), "Please introduce the row number of the cell you want to edit ");
			int column = selectInt(1, matrix.getSizeY(), "Please introduce the column number of the cell you want to edit ");
			std::string cell;
			std::cout << "Please introduce the cells new value" << std::endl
				<< "'0'- dead cell, any other character - living cell" << std::endl;
			std::cin >> cell;
			matrix.setCellXY(row-1,column-1,cell.at(0));
			key = menuSelect(mainMenu);
			break;
		}
		case 5:
		{
			key = menuSelect(patternMenu);
			if (key == 8)
			{
				key = menuSelect(mainMenu);
				break;
			}
			int row = selectInt(1, matrix.getSizeY(), "Please introduce the row number of the upper left cell of the pattern ");
			int column = selectInt(1, matrix.getSizeY(), "Please introduce the column number of the upper left cell of the pattern ");
			switch (key)
			{
			case 1:
			{
				matrix.insertPattern(row-1, column-1, Matrix::BLOCK);
				break;
			}
			case 2:
			{
				matrix.insertPattern(row-1, column-1, Matrix::BOAT);
				break;
			}
			case 3:
			{
				matrix.insertPattern(row-1, column-1, Matrix::BLINKER);
				break;
			}
			case 4:
			{
				matrix.insertPattern(row-1, column-1, Matrix::BEACON);
				break;
			}
			case 5:
			{
				matrix.insertPattern(row-1, column-1, Matrix::PULSAR);
				break;
			}
			case 6:
			{
				matrix.insertPattern(row-1, column-1, Matrix::PENTADECATHLON);
				break;
			}
			case 7:
			{
				matrix.insertPattern(row-1, column-1, Matrix::GLIDER);
				break;
			}
			}
		}
		case 6:
		{
			matrix=play(matrix);
			key = menuSelect(mainMenu);
			break;
		}
		case 7:
		{
			return 0;
			break;
		}
		}
	} while (true);
}

Matrix play(Matrix matrix)
{
	char key = ' ';
	int step = 0;
	std::cin.clear();
	fflush(stdin);
	do
	{
		matrix.print();
		std::cout << "Step nr. " << step << std::endl << "Press any key to continue or q to quit ";
		key = getchar();
		if (key != 'q' && key != 'Q')
		{
			step++;
			system("CLS");
			matrix.step();
		}
	} while (key != 'q' && key != 'Q');
	return matrix;
}

int menuSelect(std::vector<std::string> menuString)
{
	std::string in;
	int key;
	bool ok = false;
	int size = menuString.size();
	do
	{
		std::cin.clear();
		fflush(stdin);
		system("CLS");
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ". " << menuString[i].c_str() << std::endl;
		}
		std::cin >> key;
		if (key > 0 && key <= sizeof(menuString))
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
	} while (!ok);
	return key;
}

int selectInt(int min, int max,std::string question)
{
	int key;
	do
	{
		std::cin.clear();
		fflush(stdin);
		system("CLS");
		std::cout << question << "(" << min << "-" << max << ") ";
		std::cin >> key;
		if (key >= min&&key <= max) return key;
	} while (true);
}

void pressKey(std::string text)
{
	std::cout << text;
	std::cin.clear();
	fflush(stdin);
	getchar();
}
