#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

template <typename T>
int compare(T const& x, T const& y) {
    string data_type = typeid(x).name();
    
    if (data_type.find("string") == string::npos) {
        return (x < y);
    }
    
    return x.compare(y);
}

template <typename T>
void swap(T& x, T& y) {
    T tmp;
    
    tmp = x;
    x   = y;
    y   = tmp;
}

template <typename T>
void sort(T*& data) {
    int size = sizeof(data);
    int i    = 0, j=0;
    T   t1,t2;
    
    for (i= 0; i<size-1; i++) {
        t1 = data[i];
        for (j=i+1; j<size; j++) {
            t2 = data[j];
            if (compate(t1,t2) == -1) {
                swap(t1,t2);
            }
        }
    }
}

template <typename T>
void print(T* const& data) {
    int size = sizeof(data);
    int i    = 0;
    
    for (i=0; i<size; i++) {
        cout << "Array[" << i << "]=" << data[i];
    }
}



int main(int argc, char * argv[]) {
    
    int data[10] = {9,8,7,6,5,4,3};
    
    print(data);
    return 0;
}



