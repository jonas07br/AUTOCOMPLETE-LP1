#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <fstream>
#include <string>
#include <functional>   
#include <algorithm>    

#include "Termo.h"
#include "Lista.h"
#include "ListaOrdenada.h"
#include "FileService.h"

using namespace std;

class Autocomplete{

private:
    string filename="";
    int size;
    static int binarySearch(ListaOrdenada<Termo> autocompleteList, string word);

public:
    Autocomplete(string filename,int size);
    ~Autocomplete();
    void getList(ListaOrdenada<Termo> autocompleteList,int start,int size);

};

Autocomplete::Autocomplete(string filename,int size){
    this->filename=filename;
    this->size=size;

    ListaOrdenada<Termo> autocompleteList = FileService::readFile(filename);
    //getList(autocompleteList,size);
    string wordTarget="";

    cout<<"Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):"<<endl;
    cin>>wordTarget;

    /*if(wordTarget=="sair"){
        break;
    }*/

    int start = binarySearch(autocompleteList,wordTarget);
    ListaOrdenada<Termo> outputList = FileService::readFile(filename);
    getList(outputList,start,size);
        
    
    
}

Autocomplete::~Autocomplete(){
    
}

void Autocomplete::getList(ListaOrdenada<Termo> autocompleteList,int start,int size){
    int end = start+size;
    ListaOrdenada<Termo> resultList;
    for(int i=start; i<end; i++){
        resultList.insert(autocompleteList[i]);
        if(i==autocompleteList.getSize()-1){
            break;
        }
    }
    resultList.sortByWeight();
    for(int i=0; i<resultList.getSize(); i++){
        cout<<resultList[i].getWeight()<<"-"<<resultList[i].getWord()<<endl;
    }
}

int Autocomplete::binarySearch(ListaOrdenada<Termo> autocompleteList, string word){
    Termo target(word,0);
    int left = 0;
    int right = autocompleteList.getSize()-1;
    while(left<=right){
        int middle = left + (right-left)/2;
        Termo current = autocompleteList[middle];
        if(Termo::compareByPrefix(current,target,word.size())== 0){
            for(int i=middle; i>=0; i--){
                //find the first element that is different from the target
                if(Termo::compareByPrefix(autocompleteList[i],target,word.size())!=0){
                    return i+1;
                }
            }
            return middle;
        }
        if(Termo::compareByPrefix(current,target,word.size()) < 0){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return -1;
}

#endif