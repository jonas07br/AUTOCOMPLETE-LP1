#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include "Termo.h"
#include "Lista.h"
#include "ListaOrdenada.h"

#define GREEN   "\033[32m" 
#define RED     "\033[31m"  
#define RESET   "\033[0m"

using namespace std;

bool compareTermo(const Termo& a, const Termo& b) {
    return a<b;
};

class FileService {
    public:
        static ListaOrdenada<Termo> readFile(const string& nomeArquivo) {
            ListaOrdenada<Termo> outputList;
            fstream arquivo;
            arquivo.open(nomeArquivo, ios::in);
            int totalLines = countLines(nomeArquivo);
            if(arquivo.is_open()){
                cout.flush();
                string linha;
                int qtd=0;
                cout <<GREEN<< "Lendo arquivo" <<RESET<< endl;
                while (getline(arquivo, linha)) {
                    showLoadingBar((qtd*100)/totalLines);
                    //SEPARATING THE WEIGHT FROM THE WORD
                    size_t tabPos = linha.find_first_of("\t");
                    string palavra = linha.substr(tabPos + 1);
                    string peso = linha.substr(0, tabPos);
                    peso.erase(0, peso.find_first_not_of(" "));

                    //CREATING THE TERMO OBJECT AND INSERTING IT INTO THE LIST
                    Termo termo(palavra, stol(peso));
                    //cout<<termo.getWord()<<" - "<<termo.getWeight()<<endl;
                    outputList.insert(termo);
                    
                    qtd++;
                }
                cout<<endl;
                cout<<GREEN<<"Arquivo lido com sucesso"<<RESET<<endl;
                cout<<"--------------------------------------"<<endl;

                outputList.sort(compareTermo);
                return outputList;
            }
            else{
                cout <<RED<< "Erro ao abrir o arquivo(Arquivo nao encontrado)" <<RESET<< endl;
                return outputList;
            }
        }

        static void showLoadingBar(int progress) {
            int barWidth = 100;
            cout << "[";
            int pos = barWidth * progress / 100;
            for (int i = 0; i <=barWidth; ++i) {
                if (i < pos) cout << "=";
                else if (i == pos) cout << ">";
                else cout << " ";
            }
            cout << "] " << progress << " %\r";
            cout.flush();
            
        }

        static int countLines(const string& nomeArquivo) {
            fstream arquivo;
            arquivo.open(nomeArquivo, ios::in);
            int lines = 0;
            string line;
            while (getline(arquivo, line)) {
                lines++;
            }
            return lines;
        }


};
#endif