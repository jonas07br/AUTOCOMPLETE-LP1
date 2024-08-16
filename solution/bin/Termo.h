#ifndef TERMO_H
#define TERMO_H
#include <iostream>
using namespace std;

class Termo{
    private:
        string word;
        long weight;
    public:
        Termo();
        Termo(string word, long weight);
        string getWord();
        long getWeight();
        void setword(string word);
        void setweight(long weight);
        bool operator<(Termo T2);
        static int compareByWeight(Termo t1,Termo t2);
        static int compareByPrefix(Termo t1,Termo t2,int prefixSize);
};
Termo::Termo(){
    word = "";
    weight = 0;
}
Termo::Termo(string word, long weight){
    this->word = word;
    this->weight = weight;
}
string Termo::getWord(){
    return word;
}
long Termo::getWeight(){
    return weight;
}
void Termo::setword(string word){
    this->word = word;
}
void Termo::setweight(long weight){
    this->weight = weight;
}

bool Termo::operator<(Termo t2)
{
    string p1 = this->getWord();
    string p2 = t2.getWord();
    
    size_t p1size = (p1.size()>0)?p1.size():0;
    size_t p2size = (p2.size()>0)?p2.size():0;
    int minSize = min(p1size, p2size);
    
    for(int i=0; i<minSize; i++){
        if(p1[i] < p2[i]){
            return false;
        }
        else if(p1[i] > p2[i]){
            return true;
        }
    }
    return false;
    
    
    
}
int Termo::compareByWeight(Termo t1, Termo t2)
{
    if(t1.getWeight() < t2.getWeight()){
        return -1;
    }
    else if(t1.getWeight() > t2.getWeight()){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}
int Termo::compareByPrefix(Termo t1, Termo t2, int prefixSize)
{
    for(int x=0;x<=prefixSize;x++){
        if(t1.getWord()[x] < t2.getWord()[x]){
            return -1;
        }
        else if(t1.getWord()[x] > t2.getWord()[x]){
            return 1;
        } 
    }
    return 0;
    
}
#endif