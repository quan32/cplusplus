#include "simple_array.h"

/***
 * SimpleArray class's implementation
 *
 */
SimpleArray::SimpleArray() {
    size    = 0;
    header  = NULL;
    tail    = NULL;
    alert   = new Alert();
}
bool SimpleArray::isEmpty() {
    return (size >0) ? false : true;
}
int SimpleArray::getSize() {
    return size;
}
void SimpleArray::updateSize(PARAM value) {
    size    += value;
}
ArrayData * SimpleArray::getElement(int position) {
    ArrayData *ptr = NULL;
    
    ptr     = header;
    while (ptr != NULL) {
        if (ptr->position == position) {
            alert->set(INFOR_FOUNDED);
            return ptr;
        }
    }
    
    alert->set(INFOR_UNFOUNDED);
    return NULL;
}

void SimpleArray::addElement(int value) {
    ArrayData *node = new ArrayData(value, size);
    if (node == NULL) {
        alert->set(ERROR_MEMORY_MALLOC);
        alert->alert();
    }
    
    if (header != NULL) {
        tail->next = node;
        tail       = node;
    } else {
        header = tail = node;
    }
    
    updateSize(INCREMENT);
}

void SimpleArray::removeElement(int position) {
    
    ArrayData *ptr = NULL, *tmp=NULL;
    
    alert->set(UNKNOWN);
    ptr = header;
    
    if (header->position == position) {
        alert->set(INFOR_FOUNDED);
        ptr     = header;
        header  = header->next;
    } else {
        while (ptr != NULL) {
            tmp = ptr;
            ptr = ptr->next;
            if (ptr != NULL && ptr->position == position) {
                alert->set(INFOR_FOUNDED);
                break;
            }
        }
        
        if (alert->isFounded()) {
            tmp->next = tmp->next->next;
        } else {
            alert->set(ERROR_INVALID_INDEX, to_string(position));
            alert->alert();
        }
    }
    
    delete ptr;
}

void SimpleArray::print() {
    ArrayData *ptr  = header;
    
    if (size == 0) {
        alert->set(INFOR_EMPTY_ARRAY);
        return;
    }
    
    ptr = header;
    while (ptr != NULL) {
        cout << "Array[" << ptr->position << "]=" << ptr->value << endl;
        ptr    = ptr->next;
    }
}