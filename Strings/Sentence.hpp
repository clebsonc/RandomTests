//
// Created by clebson on 08/06/16.
//

#ifndef STRINGS_SENTENCE_HPP
#define STRINGS_SENTENCE_HPP

#include <iostream>
#include <string>



class Sentence {
public:
    Sentence();
    Sentence(std::string s);

    static char findFirstNonRepeatedCharacter(std::string sentence);

    static std::string removeCharacters(std::string sentence, std::string remove);

    static std::string reverseWords(std::string sentence);

    static int stringToInteger(std::string vetor);

    static std::string integerToString(int value);
};


#endif //STRINGS_SENTENCE_HPP
