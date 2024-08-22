#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include <iostream>
#include <algorithm>
#include <functional>
#include "Lista.h"
#include "Termo.h"

int compareWeight(Termo t1,Termo t2){
    return Termo::compareByWeight(t1,t2);
}

int compareWord(Termo t1,Termo t2){
    return Termo::compareByPrefix(t1,t2,0);
}


using namespace std;
template <typename T>
class ListaOrdenada: public Lista<T>{
    public:
            bool sort(function<bool(const T &,const  T &)> func_compara);
            bool sortByWeight();
            bool sortByWord();
            void getList(int start,int size,string word);

    
    private:
};

template <typename T>
bool ListaOrdenada<T>::sort(function<bool(const T &,const T &)> func_compara){
    for(int i=0; i<this->getSize(); i++){
        for(int j=i+1; j<this->getSize(); j++){
            if(func_compara(this->operator[](i), this->operator[](j))){
                //T temp = this->operator[](i);
                T temp = std::move(this->operator[](i));
                this->operator[](i) = std::move(this->operator[](j));
                this->operator[](j) = std::move(temp);
                /* this->operator[](i) = this->operator[](j);
                this->operator[](j) = temp; */
            }
        }
    }
    return true;
}

template <typename T>
bool ListaOrdenada<T>::sortByWeight()
{
    for(int i = 0;i<this->getSize()-1;i++){
        for(int j=0;j<this->getSize()-1;j++){
            if(compareWeight(this->operator[](j),this->operator[](j+1)) == -1){
                T temp = this->operator[](j);
                this->operator[](j) = this->operator[](j+1);
                this->operator[](j+1) = temp;
            }
        }
        
    }
    
    return false;
}

template <typename T>
void ListaOrdenada<T>::getList(int start,int size, string wordInput)
{
    ListaOrdenada<Termo> outputList;
    Termo termo(wordInput,0);
    for(int i = start;i<size+start;i++){
        const string &word = this->operator[](i).getWord();
        const long &weight = this->operator[](i).getWeight();
        Termo current(word,weight);
        if(Termo::compareByPrefix(current,termo,wordInput.size()) == 0){
            outputList.insert(this->operator[](i));
        } 
        
    }
    outputList.sortByWeight();
    outputList.print();
    
    //return ListaOrdenada<Termo>();
}

#endif

