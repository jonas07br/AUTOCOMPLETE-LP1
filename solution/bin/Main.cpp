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
    cout<<"Informe o nome do arquivo a ser lido e a quantidade de sugestoes desejadas:"<<endl;
    string entrada;
    int size;
    cin>>entrada>>size;
    Autocomplete autocompleter(entrada,size);
    
    string target;
    if(autocompleter.isOpen()){
        while(true){
        
            cout<<"Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):"<<endl;
            cin>>target;
            
            if(target=="sair"){
                break;
            }
            
            int start = autocompleter.BinarySearch(target);
            if(start==-1){
                cout<<"Termo nao encontrado"<<endl;
                continue;
            }
            else{
                autocompleter.getList(start,target);

            }
        }
    }
    
    cout<<"----------------FIM-------------------"<<endl;
    
    



    return 0;
}