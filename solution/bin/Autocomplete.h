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
    ListaOrdenada<Termo> autocompleteList;
    static int binarySearch(ListaOrdenada<Termo> autocompleteList, string word);

public:
    Autocomplete(string filename,int size);
    ~Autocomplete();
    void getList(ListaOrdenada<Termo> autocompleteList,int start,int size);
    void getListTest(int start,string word);
    int BinarySearchTest(string word);

};

Autocomplete::Autocomplete(string filename,int size){
    this->filename=filename;
    this->size=size;
    this->autocompleteList = FileService::readFile(filename);

    //ListaOrdenada<Termo> autocompleteList = FileService::readFile(filename);
    //getList(autocompleteList,size);
    /*string wordTarget="";

    cout<<"Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):"<<endl;
    cin>>wordTarget;

    if(wordTarget=="sair"){
        break;
    }

    int start = binarySearch(autocompleteList,wordTarget);
    ListaOrdenada<Termo> outputList = FileService::readFile(filename);
    getList(outputList,start,size);
    */  
    
    
}

Autocomplete::~Autocomplete(){
    delete &autocompleteList;
}

/*void Autocomplete::getList(ListaOrdenada<Termo> autocompleteList,int start,int size){
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
}*/
/*
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
}*/

void Autocomplete::getListTest(int start,string word){
    ListaOrdenada<Termo> tempList;

    int end = start + this->size;
    for(int i=start; i<end; i++){
        Termo temp(word,0);
        if(Termo::compareByPrefix(this->autocompleteList[i],temp,word.size())==0){
            tempList.insert(this->autocompleteList[i]);
        }
        
    }
    tempList.sortByWeight();
    for(int x = 0;x<tempList.getSize();x++){
        cout<<tempList[x].getWeight()<<"-"<<tempList[x].getWord()<<endl;
    }
    
}

int Autocomplete::BinarySearchTest(string word)
{
    Termo target(word,0);
    int left = 0;
    int right = this->autocompleteList.getSize()-1;
    while(left<=right){
        int middle = left + (right-left)/2;
        Termo current = this->autocompleteList[middle];
        if(Termo::compareByPrefix(current,target,word.size())== 0){
            for(int i=middle; i>=0; i--){
                //find the first element that is different from the target
                if(Termo::compareByPrefix(this->autocompleteList[i],target,word.size())!=0){
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