#ifndef TERMO_H
#define TERMO_H
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Termo{
    private:
        string word;
        long weight;
    public:
        Termo();
        Termo(string word, long weight);
        const string& getWord() const;
        const long& getWeight()const;
        void setword(string word);
        void setweight(long weight);
        bool operator<(const Termo& T2)const;
        friend ostream& operator<<(ostream& os, const Termo& termo);
        static int compareByWeight(const Termo& t1,const Termo& t2);
        static int compareByPrefix(const Termo& t1,const Termo& t2,int prefixSize);
};
Termo::Termo(){
    word = "";
    weight = 0;
}
Termo::Termo(string word, long weight){
    this->word = word;
    this->weight = weight;
}

const string &Termo::getWord() const{
    return this->word;
}
const long &Termo::getWeight() const{
    return this->weight;
}

void Termo::setword(string word){
    this->word = word;
}
void Termo::setweight(long weight){
    this->weight = weight;
}

bool Termo::operator<(const Termo& t2)const{
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

ostream& operator<<(ostream& os, const Termo& termo){
    os << termo.getWeight() << " - " << termo.getWord();
    return os;
}

int Termo::compareByPrefix(const Termo &t1, const Termo &t2, int prefixSize){
    string word1="";
    string word2="";
    for(int x=0;x<prefixSize;x++){
            string word1 = t1.getWord();
            string word2 = t2.getWord();
            if(word1[x] < word2[x]){
                return -1;
            }
            else if(word1[x]> word2[x]){
                return 1;
            } 
    }
    return 0;
}

int Termo::compareByWeight(const Termo &t1, const Termo &t2){
    long p1=t1.getWeight();
    long p2=t2.getWeight();

    if(p1 < p2){
        return -1;
    }
    else if(p1 > p2){
        return 1;
    }
    else{
        return 0;
    }
    
}
/*int Termo::compareByPrefix(const Termo& t1,const Termo& t2, int prefixSize)const{
    for(int x=0;x<prefixSize;x++){
        if(t1.getWord()[x] < t2.getWord()[x]){
            return -1;
        }
        else if(t1.getWord()[x] > t2.getWord()[x]){
            return 1;
        } 
    }
    return 0;
    
}*/
#endif