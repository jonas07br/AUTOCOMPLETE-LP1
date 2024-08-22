#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <fstream>
#include <string>
#include <functional>   
#include <algorithm>    
#include <vector>

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
    //static int binarySearch(ListaOrdenada<Termo> autocompleteList, string word);

public:
    Autocomplete(string filename,int size);
    ~Autocomplete();
    //void getList(ListaOrdenada<Termo> autocompleteList,int start,int size);
    void getList(int start,string word);
    int BinarySearch(string word);
    void printLista();
    bool isOpen();

};

Autocomplete::Autocomplete(string filename,int size){
    this->filename=filename;
    this->size=size;
    this->autocompleteList = FileService::readFile(filename);
}

Autocomplete::~Autocomplete(){
    delete &autocompleteList;
}


void Autocomplete::getList(int start,string wordinput){
    
    this->autocompleteList.getList(start,this->size,wordinput);
    
    /* int end = start + this->size;
    Termo temp(wordinput,0);
    for(int i=start; i<end; i++){
        const string &word = this->autocompleteList[i].getWord();
        const long &weight = this->autocompleteList[i].getWeight();
        Termo current(word,weight);
        if(Termo::compareByPrefix(current,temp,wordinput.size())==0){
            //tempList.insert(this->autocompleteList[i]);
            cout<<current.getWeight()<<"-"<<current.getWord()<<endl;
        } 
        if(i==this->autocompleteList.getSize()-1){
            break;
        }
    } */
    
    /* tempList.sortByWeight();
    for(int x = 0;x<tempList.getSize();x++){
        cout<<tempList[x].getWeight()<<"-"<<tempList[x].getWord()<<endl;
    }  */

    
   
}

int Autocomplete::BinarySearch(string word)
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
void Autocomplete::printLista(){
    for(int i=0; i<autocompleteList.getSize(); i++){
        cout<<autocompleteList[i].getWeight()<<" - "<<autocompleteList[i].getWord()<<endl;
    }
}

bool Autocomplete::isOpen()
{
    if(this->autocompleteList.getSize()>0){
        return true;
    }
    return false;
    
}

#endif