#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

template <typename T>
class Lista{
private:
    T* lista;
    int size;
    int capacity;

    void resize() {
        capacity += 150;
        T* newList = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newList[i] = lista[i];
        }
        delete[] lista;
        lista = newList;
    }

public:
    Lista() : size(0), capacity(100) {
        lista = new T[capacity];
    }

    ~Lista() {
        delete[] lista;
    }

    void insert(const T& item) {
        if (size == capacity) {
            resize();
        }
        lista[size++] = item;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << lista[i] << " ";
        }
        cout << endl;
    }

    T& operator[](int indice) {
        if (indice < 0 || indice >= size) {
            throw out_of_range("Indice nao encontrado");
        }
        return lista[indice];
    }

    const T& operator[](int indice) const {
        if (indice < 0 || indice >= size) {
            throw out_of_range("Indice nao encontrado");
        }
        return lista[indice];
    }
};
#endif