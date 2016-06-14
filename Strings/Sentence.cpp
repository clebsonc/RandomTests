//
// Created by clebson on 08/06/16.
//

#include "Sentence.hpp"
#include <unordered_map>
#include <unordered_set>
#include <cmath>

char Sentence::findFirstNonRepeatedCharacter(std::string sentence) {
    std::unordered_map<char, int> umap;
    int first = 0;  // index of the first non repeated word

    for(int i = 0; sentence[i]!='\0'; i++){
        std::unordered_map<char, int>::const_iterator got = umap.find(sentence[i]);
        if(got != umap.end()){
            umap.at(sentence[i]) = sentence[i] + 1;
            if(sentence[first] == sentence[i]){
                do{
                    first++;
                    if(first > i){
                        umap.emplace(sentence[first], 1);
                        i=first;
                    }
                }while(umap.at(sentence[first]) != 1 );
            }
        } else{
            umap.emplace(sentence[i], 1);
        }
    }
    return sentence[first];
}

std::string Sentence::removeCharacters(std::string sentence, std::string remove) {
    std::unordered_set<char> schar;
    for(char c : remove){
        schar.emplace(c);
    }
    int i = 0, j=0;
    for(i=0; i < sentence.size(); i++){
        remove.size();
        std::unordered_set<char>::const_iterator found = schar.find(sentence[i]);
        if(found == schar.end()){
            sentence[j] = sentence[i];
            j++;
        }
    }
    //sentence[j] = '\0';
    sentence.resize(j);
    return sentence;
}

std::string Sentence::reverseWords(std::string sentence){
    std::string buffer = sentence;
    int k = 0;
    unsigned long int i = sentence.size()-1;
    unsigned long int j;
    while(i>=0){
        if(sentence[i]==' ' || i == 0){
            j = i == 0 ? 0 : i+1;
            while(sentence[j]!= '\0' && sentence[j]!= ' '){
                buffer[k] = sentence[j];
                k++;
                j++;
            }
            if(i!=0){
                buffer[k] = ' ';
                k++;
            } else {
                buffer[k] = '\0';
            }
        }
        if(i==0)
            break;
        i--;
    }
    return buffer;
}

int Sentence::stringToInteger(std::string vetor){
    int value = 0;
    for(unsigned long int i = vetor.size()-1; i>=0; i--){
        int pot = (int) pow(10, (vetor.size()-i-1));
        if(i>0){
            value += (vetor[i]-'0') * pot;
        } else if (vetor[i] == '-'){
            // i == 0 and is a negative number
            return -value;
        } else {
            return value + (vetor[i]-'0') * pot;
        }
    }
}


std::string Sentence::integerToString(int value) {
    std::string buffer;
    buffer.reserve(10);
    bool negative = value < 0;
    if(negative) {
        buffer.push_back('-');
        value = -value;
    }
    std::cout << "buffer: " << buffer << std::endl;
    int mod = 0;
    do{
        mod = value % 10;
        value = value / 10;
        buffer.push_back('0' + mod);
    }while(value != 0);
    int i = negative ? 1 : 0;
    int j = buffer.size() - 1;
    char c;
    for(i, j; i<j; i++, j--){
        c = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = c;
    }
    return buffer;
}