#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include <iostream>
#include <algorithm>
#include <functional>
#include "Lista.h"

using namespace std;
template <typename T>
class ListaOrdenada: public Lista<T>{
    public:
            bool sort(function<bool( T &,  T &)> func_compara);
        

    
    private:
};

template <typename T>
bool ListaOrdenada<T>::sort(function<bool( T &, T &)> func_compara)
{
    for(int i=0; i<this->getSize(); i++){
        for(int j=i+1; j<this->getSize(); j++){
            if(func_compara(this->operator[](i), this->operator[](j))){
                T temp = this->operator[](i);
                this->operator[](i) = this->operator[](j);
                this->operator[](j) = temp;
            }
        }
    }
    return true;
}

#endif

