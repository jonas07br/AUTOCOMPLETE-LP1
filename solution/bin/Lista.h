#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Termo.h"
using namespace std;

template <typename T>
class Lista{
private:
    T* lista;
    int size;
    int capacity;

    void resize() {
        capacity += 200;
        T* newList = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newList[i] = lista[i];
        }
        delete[] lista;
        lista = newList;
    }

public:
    Lista(){
        this->size=0;
        this->capacity=0;
        this->lista = new T[capacity];
    }

    ~Lista() {
        delete[] lista;
    }

    void insert(const T& item) {
        if (this->size == this->capacity) {
            resize();
        }
        lista[size++] = item;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < this->size; ++i) {
            cout << lista[i] << endl;;
        }
    }

    T& operator[](int indice) {
        if (indice < 0 || indice >= size) {
            throw ("Indice nao encontrado");
        }
        return lista[indice];
    }
    //for const functions
    const T& operator[](int indice) const {
        if (indice < 0 || indice >= size) {
            throw ("Indice nao encontrado");
        }
        return lista[indice];
    }
};
#endif