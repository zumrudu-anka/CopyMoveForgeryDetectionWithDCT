#pragma once

ref class Blocks
{
private:
	int row, column;
	int *diagonalorder;
public:
	void SetDiagonalOrder(int *thresholded_diago_array, int r, int c);
	int *GetDiagonalOrder();
	int GetRow();
	int GetColumn();
};

