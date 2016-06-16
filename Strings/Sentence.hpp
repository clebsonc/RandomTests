//
// Created by clebson on 08/06/16.
//

#ifndef STRINGS_SENTENCE_HPP
#define STRINGS_SENTENCE_HPP

#include <iostream>
#include <string>
#include <stack>



class Sentence {
public:
    static char findFirstNonRepeatedCharacter(std::string sentence);

    static std::string removeCharacters(std::string sentence, std::string remove);

    static std::string reverseWords(std::string sentence);

    static int stringToInteger(std::string vetor);

    static std::string integerToString(int value);

    static std::stack<std::string> * find_all_permutation(std::string string);

    static std::stack<std::string> * do_perm(std::stack<std::string> * stack, char c);
};


#endif //STRINGS_SENTENCE_HPP
