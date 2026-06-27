#ifndef MAZEGEN_H
#define MAZEGEN_H

#include "dynamic.h"
#include "stackp.h"

class mazegen
{
public:
    mazegen();
    void mazegrid(int rinp, int cinp);
    void generate();
    void printmaze();
    void printPath(int sr, int sc, int er, int ec);
    void generatemultipath();

    cell* getCell(int r, int c) const { return &((*grid)(r, c)); }

    dynamic* getGrid() const { return grid; }
    int getRows() const { return row; }
    int getCols() const { return col; }

    ~mazegen();

private:
    void dfs(int rcall, int ccall);

    dynamic* grid;
    stackp s;
    int row;
    int col;
};

#endif