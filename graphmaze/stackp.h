#pragma once
#ifndef STACK_H
#define STACK_H

#include "pos.h"

class stackp
{
private:
    pos* data;       
    int topIndex;    
    int capacity;  

public:
    stackp();
    stackp(int cap);  
    ~stackp();
    void reset(int newCapacity);
    void push(int r, int c); 
    void pop();               
    pos top();               
    bool empty();            
};

#endif