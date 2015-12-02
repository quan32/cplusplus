#include <iostream>

using namespace std;

template <typename T>
void swap(T const&, T const&);
template <typename T>
void print(T const&, T const&);





template <typename T>
void swap(T const& a, T const& b) {
    T tmp = 0;
    
    tmp = a;
    a   = b;
    b   = tmp;
}

template <typename T>
void print(T const& a, T const& b) {
    cout << "a=" << a << " - b=" << b << endl;
}

template <class K, class V>
class Data {
private:
    K key;
    V value;
    
public:
    Data(K key, V value);
    void setValue(K key, V value);
    void print();
};

template <class K, class V>
Data<K,V>::Data(K key, V value) {
    this->key     = key;
    this->value   = value;
}

template <class K, class V>
void Data<K,V>::setValue(K key, V value) {
    this->key     = key;
    this->value   = value;
    
    cout << key << ":" << value << endl;
}

template <class K, class V>
void Data<K,V>::print() {
    cout << key << ":" << value << endl;
}

int main(int argc, char * argv[]) {
    
    Data<int, int> *data = new Data<int,int>(1,2);
//    data.setValue(1, 1);
    
    data->print();
    
    return 0;
}



