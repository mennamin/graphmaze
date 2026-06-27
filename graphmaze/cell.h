#pragma once
struct cell
{
    bool top = true;
    bool bottom = true;
    bool right = true;
    bool left = true;

    int wtop = 1;
    int wbottom = 1;
    int wright = 1;
    int wleft = 1;

    bool visited = false;
    bool path = false;

    int g = 0;
    int h = 0;
    int f = 0;

    bool open = false;
    bool closed = false;
    int weight = 1;
    int parentRow = -1;
    int parentCol = -1;
};