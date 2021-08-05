#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;
	std::vector<std::vector<char>> data;
	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
public:
	Matrix(size_t numColumnsX, size_t numLinesY)
		// TODO: add functionality
	{
		column_count = numColumnsX;
		line_count = numLinesY;

		//initialising data with " " for each field

		for (size_t i = 0; i < column_count; i++)
		{
			data.push_back(std::vector<char>());
			for (size_t j = 0; j < line_count; j++)
			{
				data.at(i).push_back(' ');
			}
		}
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& line_data)
	{
		if (line_number<0 || line_number>=line_count)
		{
			return;
		}
		for (size_t i = 0; i < column_count && i < line_data.length(); i++)
		{
			data.at(i).at(line_number) = line_data.at(i);
		}
	}

	//OPTIONAL
	char getCellXY(size_t x, size_t y)
	{
		if (x < 0 || x >= column_count || y < 0 || y >= line_count)
		{
			return NULL;
		}
		return data.at(x).at(y);
	}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		if (x < 0 || x >= column_count || y < 0 || y >= line_count)
		{
			return;
		}
		data.at(x).at(y) = cell_content;
	}

	void print()
	{
		std::cout << std::endl;
		for (size_t i = 0; i < line_count; i++)
		{
			for (size_t j = 0; j < column_count; j++)
			{
				std::cout << data.at(j).at(i);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	
	getchar();
	
	return 0;
}