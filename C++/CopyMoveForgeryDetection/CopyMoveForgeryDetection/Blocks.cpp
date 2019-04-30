#include "Blocks.h"

void Blocks::SetDiagonalOrder(int *thresholded_diago_array, int r, int c)
{
	diagonalorder = new int[15];
	for (int i = 0; i < 15; i++)
	{
		diagonalorder[i] = thresholded_diago_array[i];
		row = r;
		column = c;
	}
	
}

int* Blocks::GetDiagonalOrder()
{
	return this->diagonalorder;
}

int Blocks::GetRow()
{
	return this->row;
}
int Blocks::GetColumn()
{
	return this->column;
}