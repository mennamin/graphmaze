#include "mazegen.h"
#include "dynamic.h"
#include "cell.h"
  
#include <iostream>

using namespace std;

int main()
{

    cout << "Enter The Maze Length: ";
    int x;
    int y;
    if (!(cin >> x) || x <= 0) {
        cerr << "Enter a positive integer\n";
        return 1;
    }
    cout << "Enter The Maze Width: ";
    if (!(cin >> y) || y <= 0) {
        cerr << "Enter a positive integer\n";
        return 1;
    }

    mazegen m;
    m.mazegrid(x, y);
    m.generate();
    m.printmaze();

    dynamic d(x, y);
    for (int r = 0; r < x; ++r)
        for (int c = 0; c < x; ++c)
            d(r, c) = *m.getCell(r, c);

   

    return 0;
}


































