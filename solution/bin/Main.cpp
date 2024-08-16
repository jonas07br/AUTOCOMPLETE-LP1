#include <iostream>
#include <fstream>
#include <string>
#include "ListaOrdenada.h"
#include "FileService.h"
#include "Termo.h"

using namespace std;

bool compareInt(const int &a, const int &b)
{
    return a <= b; // Ordenacao crescente
}

int main(){
    cout<<"--------------------------------------"<<endl;
    cout<<"Projeto Final: Recurso de autocompletar"<<endl;
    cout<<"--------------------------------------"<<endl;
    ListaOrdenada<Termo> lista = FileService::readFile("fortune.txt");
    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    
    



    return 0;
}