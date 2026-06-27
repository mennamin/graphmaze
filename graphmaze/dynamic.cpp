#include "dynamic.h"

dynamic::dynamic(int totalRows, int totalCols)
{
    rows = totalRows;
    cols = totalCols;

    data = new cell * [rows];

    for (int row = 0; row < rows; row++)
    {
        data[row] = new cell[cols];
    }
}


dynamic::~dynamic()
{
    for (int row = 0; row < rows; row++)
    {
        delete[] data[row];
    }
    delete[] data;
}


cell& dynamic::operator()(int row, int col)
{
    return data[row][col];
}


int dynamic::getRows()
{
    return rows;
}

int dynamic::getCols()
{
    return cols;
}