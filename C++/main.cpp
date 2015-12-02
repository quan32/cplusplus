#include "simple_array.h"

int main(int argc, char * argv[]) {
    
    SimpleArray *array = new SimpleArray();
    int i = 0;
    
    for (i=0; i<10; i++) {
        array->addElement(2*i);
    }
    
    array->removeElement(2);
    array->removeElement(9);
    
    array->print();
    
    return 0;
}





