#include <iostream>

using namespace std;


class ArrayParameter {
public:
    enum PARAM {
        INCREMENT = 1,
        DECREMENT = -1,
    };
};

class ArrayData {
public:
    int         value;
    int         position;
    ArrayData   *next;
    
public:
    ArrayData(int val, int pos) {
        value       = val;
        position    = pos;
        next        = NULL;
    }
};


class AlertState {
public:
    enum ALERT_STATE {
        UNKNOWN                 = 1,
        
        ERROR_INVALID_INDEX     = 10,
        ERROR_MEMORY_MALLOC     = 11,
        
        
        INFOR_EMPTY_ARRAY       = 20,
        INFOR_FOUNDED           = 21,
        INFOR_UNFOUNDED         = 22,
    };
};

class Alert : public AlertState {
private:
    ALERT_STATE state;
    string      message;
    
public:
    Alert() {
        state   = UNKNOWN;
        message = "";
    }
    
    void set(ALERT_STATE alert_state, const string alert_message="") {
        state   = alert_state;
        message = alert_message;
    }
    
    bool isFounded() {
        return (state == INFOR_FOUNDED);
    }
    
    ALERT_STATE getState() {
        return state;
    }
    
    void alert() {
        switch (state) {
            case ERROR_INVALID_INDEX:
                cout << "INVALID_INDEX:" << message << endl;
                exit(-1);
                
            case ERROR_MEMORY_MALLOC:
                cout << "No more memory available" << endl;
                exit(-1);
                
            case INFOR_EMPTY_ARRAY:
                cout << "Empty Array" << endl;
                break;
                
            default:
                break;
        }
    }
    
};

class Array : public ArrayParameter, public AlertState {
private:
    int          size;
    Alert        * alert;
    ArrayData    * header;
    ArrayData    * tail;
    
public:
    Array() {
        size    = 0;
        header  = NULL;
        tail    = NULL;
        alert   = new Alert();
    }
    
    bool isEmpty() {
        return (size >0) ? false : true;
    }
    
    int getSize() {
        return size;
    }
    
    void updateSize(PARAM value) {
        size    += value;
    }
    
    ArrayData * getElement(int position) {
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
    
    void addElement(int value) {
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
    
    void removeElement(int position) {
        
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
    
    void print() {
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
};

int main(int argc, char * argv[]) {
    
    Array *array    = new Array();
    int             i=0;
    
    for (i=0; i<10; i++) {
        array->addElement(2*i);
    }
    
    array->removeElement(0);
    array->removeElement(80);
    
    array->print();
    
    return 0;
}





