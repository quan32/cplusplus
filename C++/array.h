#ifndef array_h
#define array_h

#include<iostream>
#include<string>

using namespace std;

enum PARAM {
    INCREMENT = 1,
    DECREMENT = -1,
};

enum ALERT_STATE {
    UNKNOWN                 = 1,
    
    ERROR_INVALID_INDEX     = 10,
    ERROR_MEMORY_MALLOC     = 11,
    
    
    INFOR_EMPTY_ARRAY       = 20,
    INFOR_FOUNDED           = 21,
    INFOR_UNFOUNDED         = 22,
};

struct ArrayData {
    int                 value;
    int                 position;
    struct ArrayData    *next;
    
    ArrayData(int value, int position);
};

class Alert {
private:
    ALERT_STATE state;
    string      message;
public:
    Alert();
    void set(ALERT_STATE alert_state, const string alert_message="");
    bool isFounded();
    void alert();
    ALERT_STATE getState();
};

class ArrayInterface {
protected:
    int     size;
    Alert   *alert;
    
public:
    virtual bool isEmpty() = 0;
    virtual int getSize()  = 0;
    virtual void updateSize(PARAM value)  = 0;
    virtual void addElement(int value)    = 0;
    virtual ArrayData * getElement(int position) = 0;
    virtual void removeElement(int position)     = 0;
    virtual void print()   = 0;
};

#endif