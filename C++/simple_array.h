#ifndef simple_array_h
#define simple_array_h

#include "array.h"

class SimpleArray : public ArrayInterface {
private:
    ArrayData    * header;
    ArrayData    * tail;
    
public:
    SimpleArray();
    
    bool isEmpty();
    virtual int getSize();
    void updateSize(PARAM value);
    void addElement(int value);
    ArrayData * getElement(int position);
    void removeElement(int position);
    void print();
};

#endif
