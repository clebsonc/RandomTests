//
// Created by clebson on 08/06/16.
//

#ifndef STRINGS_SENTENCE_HPP
#define STRINGS_SENTENCE_HPP

#include <iostream>
#include <string>



class Sentence {
private:
    std::string sentence;

public:
    Sentence();
    Sentence(std::string s);

    char findFirstNonRepeatedCharacter();

    static std::string removeCharacters(std::string sentence, std::string remove);

    std::string getSentence();

    void setSentence(std::string s);

    static std::string reverseWords(std::string sentence);

    static int stringToInteger(std::string vetor);
};


#endif //STRINGS_SENTENCE_HPP
