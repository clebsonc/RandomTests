#include "TelephoneWords.hpp"

TelephoneWords::TelephoneWords(){
    letters[0] = "0";
    char c = 'a';
    for(int i = 1; i < letters.size(); i++){
        std::string str;
        str.reserve(3);
        for(int j = 0; j < 3; j++){
            if(c >= 'a' && c<='z'){
                str.push_back(c);
                c++;
            }
        }
        letters[i] = str;
    }
}


char TelephoneWords::get_char_key(int n, int p){
    if(n < 0){
        std::string a = letters[0];
        if(p < 0){
            return a[0];
        } else if (p > a.size()-1){
            return a[a.size()-1];
        } else{
            return a[p];
        }
    } else if (n > letters.size()-1){
        std::string a = letters[letters.size()-1];
        if(p < 0){
            return a[0];
        } else if (p > a.size()-1){
            return a[a.size()-1];
        } else{
            return a[p];
        }
    } else {
        std::string a = letters[n];
        if(p < 0)
            return a[0];
        else if(p>a.size()-1)
            return a[a.size()-1];
        else
            return letters[n][p];
    }
}

void TelephoneWords::print_letters(){
    for(int i=0; i<letters.size(); i++){
        std::cout << i << " " << letters[i] << std::endl;
    }
}


std::vector<int> TelephoneWords::transform_to_array(int number){
    std::vector<int> array;
    while(number > 10) {
        array.push_back(number % 10);
        number = number / 10;
    }
    array.push_back(number);
    for(int i =0, j = array.size()-1; i!=j & i < j; i++, j--){
        int temp = array.at(i);
        array.at(i) = array.at(j);
        array.at(j) = temp;
    }
    return array;
}


void TelephoneWords::initialize_stack(std::stack<std::string> * & s1, int n){
    for(int i = 0; i < 3; i++){
        char c = get_char_key(n, i);
        std::string a;
        a.push_back(c);
        s1->push(a);
    }
}


void TelephoneWords::combine(std::stack<std::string> * & s2, std::string str, int i){
    try {
        if (s2 == nullptr)
            s2 = new std::stack<std::string>;
    }catch(std::bad_alloc ba){
        std::cout << "Error while allocating memory. " << ba.what() << std::endl;
        std::exit(1); // error while allocating memory
    }

    if(i==0){
        str.push_back(get_char_key(i, 0));  // the key 0 has only one char
        s2->push(str);
    } else{
        for(int j = 0 ; j < 3 ; j++){
            if(i == 9 && j == 2)
                break;
            std::string ns = str;
            ns.push_back(get_char_key(i, j));
            s2->push(ns);
        }
    }
}


std::stack<std::string> * TelephoneWords::get_words(int number){
    std::vector<int> an = this->transform_to_array(number);
    for(int i : an ){
        std::cout << "i  = " << i << std::endl;
    }
    try{
        std::stack<std::string> * s1 = new std::stack<std::string>,
                                * s2 = nullptr;
        initialize_stack(s1, an[0]);

        for(int i = 1; i< an.size(); i++){
            while(!s1->empty()){
                std::string str = s1->top();
                s1->pop();
                combine(s2, str, an.at(i));
            }
            delete s1;
            s1 = s2;
            s2 = nullptr;
        }
        return s1;
    } catch(std::bad_alloc ba){
        std::cout << "Error allocating memory: " << ba.what() << std::endl;
    }
}