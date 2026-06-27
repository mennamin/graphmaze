#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "cell.h"

class dynamic
{
private:
    cell** data;
    int rows;
    int cols;

public:
    dynamic(int totalRows, int totalCols);
    ~dynamic();

    cell& operator()(int row, int col);

    int getRows();
    int getCols();
};

#endif