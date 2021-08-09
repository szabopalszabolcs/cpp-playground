#include <vector>
#include <iostream>

class Matrix
{
private:
	size_t lines;
	size_t columns;
	std::vector<std::vector<int>> data;
	
public:
	enum patterns { BLOCK, BOAT, BLINKER, BEACON, PULSAR, PENTADECATHLON, GLIDER };

	Matrix()
	{
		lines = 0;
		columns = 0;
	}

	Matrix(size_t numLinesX, size_t numColumnsY)
	{
		lines = numLinesX;
		columns = numColumnsY;
		for (size_t i = 0; i < lines; i++)
		{
			data.push_back(std::vector<int>());
			for (size_t j = 0; j < columns; j++)
			{
				data.at(i).push_back(0);
			}
		}
	}

	void init(size_t numLinesX, size_t numColumnsY)
	{
		lines = numLinesX;
		columns = numColumnsY;
		for (size_t i = 0; i < lines; i++)
		{
			data.push_back(std::vector<int>());
			for (size_t j = 0; j < columns; j++)
			{
				data.at(i).push_back(0);
			}
		}
	}

	void setLine(size_t line_number, std::string line_data)
	{
		int in;
		if (line_number<0 || line_number > lines)
		{
			return;
		}
		for (size_t i = 0; i < columns && i < line_data.length(); i++)
		{
			if (line_data.at(i) == '0')
			{
				in = 0;
			}
			else
			{
				in = 1;
			}
			data.at(line_number).at(i) = in;
		}
	}

	int getCellXY(size_t x, size_t y)
	{
		if (x < 0 || x >= lines || y < 0 || y >= columns)
		{
			return NULL;
		}
		return data.at(x).at(y);
	}

	void setCellXY(size_t x, size_t y, int cell_content)
	{
		if (x < 0 || x >= lines || y < 0 || y >= columns)
		{
			return;
		}
		data.at(x).at(y) = cell_content;
	}

	size_t getSizeX()
	{
		return lines;
	}

	size_t getSizeY()
	{
		return columns;
	}

	Matrix Pattern(patterns pattern)
	{
		switch (pattern)
		{
		case BLOCK:
		{
			Matrix pat(4, 4);
			pat.setLine(0, "0000");
			pat.setLine(1, "0110");
			pat.setLine(2, "0110");
			pat.setLine(3, "0000");
			return pat;
			break;
		}
		case BEACON:
		{
			Matrix pat(6, 6);
			pat.setLine(0, "000000");
			pat.setLine(1, "011000");
			pat.setLine(2, "010000");
			pat.setLine(3, "000010");
			pat.setLine(4, "000110");
			pat.setLine(5, "000000");
			return pat;
			break;
		}
		case BLINKER:
		{
			Matrix pat(5, 5);
			pat.setLine(0, "00000");
			pat.setLine(1, "00000");
			pat.setLine(2, "01110");
			pat.setLine(3, "00000");
			pat.setLine(4, "00000");
			return pat;
			break;
		}
		case BOAT:
		{
			Matrix pat(5, 5);
			pat.setLine(0, "00000");
			pat.setLine(1, "01100");
			pat.setLine(2, "01010");
			pat.setLine(3, "00100");
			pat.setLine(4, "00000");
			return pat;
			break;
		}
		case GLIDER:
		{
			Matrix pat(5, 5);
			pat.setLine(0, "00000");
			pat.setLine(1, "00100");
			pat.setLine(2, "00010");
			pat.setLine(3, "01110");
			pat.setLine(4, "00000");
			return pat;
			break;
		}
		case PENTADECATHLON:
		{
			Matrix pat(9, 16);
			pat.setLine(0, "0000000000000000");
			pat.setLine(1, "0000000000000000");
			pat.setLine(2, "0000000000000000");
			pat.setLine(3, "0000010000100000");
			pat.setLine(4, "0001101111011000");
			pat.setLine(5, "0000010000100000");
			pat.setLine(6, "0000000000000000");
			pat.setLine(7, "0000000000000000");
			pat.setLine(8, "0000000000000000");
			return pat;
			break;
		}
		case PULSAR:
		{
			Matrix pat(15, 15);
			pat.setLine(0, "000010000010000");
			pat.setLine(1, "000010000010000");
			pat.setLine(2, "000011000110000");
			pat.setLine(3, "000000000000000");
			pat.setLine(4, "111001101100111");
			pat.setLine(5, "001010101010100");
			pat.setLine(6, "000011000110000");
			pat.setLine(7, "000000000000000");
			pat.setLine(8, "000011000110000");
			pat.setLine(9, "001010101010100");
			pat.setLine(10, "111001101100111");
			pat.setLine(11, "000000000000000");
			pat.setLine(12, "000011000110000");
			pat.setLine(13, "000010000010000");
			pat.setLine(14, "000010000010000");
			return pat;
			break;
		}
		default:
		{
			Matrix pat(0, 0);
			return pat;
		}
		}
	}
	
	void insertPattern(size_t posX, size_t posY, patterns pattern)
	{
		Matrix patt = Pattern(pattern);
		size_t patternSizeX = patt.getSizeX();
		size_t patternSizeY = patt.getSizeY();
		if (posX + patternSizeX <= lines && posY + patternSizeY <= columns)
			for (size_t i = 0; i < patternSizeX; i++)
			{
				for (size_t j = 0; j < patternSizeY; j++)
				{
					data.at(posX + i).at(posY + j) = patt.getCellXY(i, j);
				}
			}

	}

	void step()
	{
		Matrix newMatrix(lines,columns);
		
		int neighbours;

		for (size_t i = 0; i < lines; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				neighbours = nrOfNeighbours(i, j);

				if (this->getCellXY(i, j) != 0)
				{
					if ((neighbours < 2) || (neighbours > 3))
					{
						newMatrix.setCellXY(i, j, 0);
					}
					else
					{
						newMatrix.setCellXY(i, j, 1);
					}
				}
				else
				{
					if (neighbours == 3)
					{
						newMatrix.setCellXY(i, j, 1);
					}
					else
					{
						newMatrix.setCellXY(i, j, 0);
					}
				}
			}
		}
		for (size_t i = 0; i < lines; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				this->data.at(i).at(j) = newMatrix.data.at(i).at(j);
			}
		}
	}

	int nrOfNeighbours(int x, int y)
	{
		int nr = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (!(j == 0 && i == 0))
				{
					if ((x + i) >= 0 && (x + i) < lines && (y + j) >= 0 && (y + j) < columns)
					{
						if (this->getCellXY( x + i , y + j ) != 0)
						{
							nr++;
						}
					}
				}

			}
		}
		return nr;
	}

	void print()
	{
		char ch = '.';
		std::cout << std::endl;
		system("CLS");
		for (size_t i = 0; i < lines; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				if (data.at(i).at(j) == 0)
				{
					ch = '.';
				}
				else
				{
					ch = 'X';
				}
				std::cout << ch << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

};