#include <iostream>
#include <fstream>
#include <string>
#include "ListaOrdenada.h"
#include "FileService.h"
#include "Termo.h"
#include "Autocomplete.h"

using namespace std;



int main(){
    cout<<"--------------------------------------"<<endl;
    cout<<"Projeto Final: Recurso de autocompletar"<<endl;
    cout<<"--------------------------------------"<<endl;
    string entrada;
    int size;
    cin>>entrada>>size;
    Autocomplete autocompleter(entrada,size);
      
    
    



    return 0;
}