#include "mazegen.h"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

mazegen::mazegen()
{
    row = 0;
    col = 0;
    grid = nullptr;
}

void mazegen::mazegrid(int rinp, int cinp)
{
    delete grid;
    grid = nullptr;
    row = rinp;
    col = cinp;
    grid = new dynamic(rinp, cinp);
}

mazegen::~mazegen()
{
    delete grid;
    grid = nullptr;
}

void mazegen::dfs(int rcall, int ccall)
{
    static random_device rd;
    static mt19937 rng(rd());
    uniform_int_distribution<int> weightas(1, 10);

    s.push(rcall, ccall);

    while (!s.empty())
    {
        pos p = s.top();
        rcall = p.r;
        ccall = p.c;
        int nr, nc;

        (*grid)(rcall, ccall).visited = true;
        bool moved = false;

        int dir[4] = { 1, 2, 3, 4 };
        shuffle(dir, dir + 4, rng);

        for (int d : dir)
        {
            nr = rcall; nc = ccall;
            if (d == 1) nr = rcall - 1;
            else if (d == 2) nr = rcall + 1;
            else if (d == 3) nc = ccall + 1;
            else if (d == 4) nc = ccall - 1;

            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            if ((*grid)(nr, nc).visited) continue;

            int w = weightas(rng);
            moved = true;

            if (d == 1) { (*grid)(rcall, ccall).top = false; (*grid)(rcall, ccall).wtop = w; (*grid)(nr, nc).bottom = false; (*grid)(nr, nc).wbottom = w; }
            if (d == 2) { (*grid)(rcall, ccall).bottom = false; (*grid)(rcall, ccall).wbottom = w; (*grid)(nr, nc).top = false; (*grid)(nr, nc).wtop = w; }
            if (d == 3) { (*grid)(rcall, ccall).right = false; (*grid)(rcall, ccall).wright = w; (*grid)(nr, nc).left = false; (*grid)(nr, nc).wleft = w; }
            if (d == 4) { (*grid)(rcall, ccall).left = false; (*grid)(rcall, ccall).wleft = w; (*grid)(nr, nc).right = false; (*grid)(nr, nc).wright = w; }

            if (moved)
            {
                s.push(nr, nc);
                break;
            }
        }

        if (!moved) s.pop();
    }
}

void mazegen::generatemultipath()
{
    int numtimes = (row <= 70 || col <= 70) ? 1 : (row <= 100 || col <= 100) ? 2 : 3;

    for (int i = 0; i < numtimes; i++)
    {
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                (*grid)(r, c).visited = false;

        s.reset(row * col);
        dfs(0, 0);
    }
}

void mazegen::generate()
{
    s.reset(row * col);
    dfs(0, 0);
    generatemultipath();
    (*grid)(0, 0).left = false;
    (*grid)(row - 1, col - 1).right = false;
}

void mazegen::printmaze()
{
    for (int c = 0; c < col; c++) cout << ((*grid)(0, c).top ? "+---" : "+   ");
    cout << "+" << endl;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++) cout << ((*grid)(r, c).left ? "|" : " ") << "   ";
        cout << ((*grid)(r, col - 1).right ? "|" : " ") << endl;

        for (int c = 0; c < col; c++) cout << ((*grid)(r, c).bottom ? "+---" : "+   ");
        cout << "+" << endl;
    }
}

void mazegen::printPath(int sr, int sc, int er, int ec)
{
    // Print top border
    for (int c = 0; c < col; c++)
        cout << ((*grid)(0, c).top ? "+---" : "+   ");
    cout << "+" << endl;

    for (int r = 0; r < row; r++)
    {
        // Left walls + cell contents
        for (int c = 0; c < col; c++)
        {
            cout << ((*grid)(r, c).left ? "|" : " ");
            if (r == sr && c == sc)
                cout << " S ";
            else if (r == er && c == ec)
                cout << " E ";
            else if ((*grid)(r, c).path)
                cout << " . ";
            else
                cout << "   ";
        }
        // Right boundary
        cout << ((*grid)(r, col - 1).right ? "|" : " ") << endl;

        // Bottom walls
        for (int c = 0; c < col; c++)
            cout << ((*grid)(r, c).bottom ? "+---" : "+   ");
        cout << "+" << endl;
    }
}