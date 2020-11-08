#ifndef DYNAMICINTARRAY_H
#define DYNAMICINTARRAY_H
#include <iostream>
#include <string>

class DynamicIntArray {
    unsigned int size = 0;
public:
    DynamicIntArray();
    ~DynamicIntArray();
    unsigned int length() const;
    void pushBack(int value);
    int popBack();
};

#endif