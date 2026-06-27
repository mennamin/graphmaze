#include "stackp.h"

stackp::stackp()
{
    data = nullptr;
    capacity = 0;
    topIndex = -1;
}
void stackp::reset(int newCapacity)
{
    delete[] data;
    capacity = newCapacity;
    data = new pos[capacity];
    topIndex = -1;
}


stackp::stackp(int cap)
{
    capacity = cap;
    data = new pos[capacity];
    topIndex = -1;  
}


stackp::~stackp()
{
    delete[] data;
}


void stackp::push(int r, int c)
{
    if (topIndex < capacity - 1)   
    {
        topIndex++;
        data[topIndex].r = r;
        data[topIndex].c = c;
    }
}


void stackp::pop()
{
    if (topIndex >= 0)
        topIndex--;
}


pos stackp::top()
{
    if (topIndex >= 0)
        return data[topIndex];
    else
        return { -1, -1 };
}

bool stackp::empty()
{
    return topIndex == -1;
}