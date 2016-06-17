//
// Created by clebson on 08/06/16.
//

#ifndef STRINGS_SENTENCE_HPP
#define STRINGS_SENTENCE_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>


class Sentence {
public:
    static char findFirstNonRepeatedCharacter(std::string sentence);

    static std::string removeCharacters(std::string sentence, std::string remove);

    static std::string reverseWords(std::string sentence);

    static int stringToInteger(std::string vetor);

    static std::string integerToString(int value);

    static std::stack<std::string> * find_all_permutation(std::string string);

    static std::stack<std::string> * do_perm(std::stack<std::string> * stack, char c);

    static std::list<std::string> find_combinations_considering_order(std::string str);

};


#endif //STRINGS_SENTENCE_HPP
