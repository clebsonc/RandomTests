#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stack>

class TelephoneWords{
    private:
        // initialized with default constructor
        std::array<std::string, 10> letters;

        void initialize_stack(std::stack<std::string> * & s1, int n);

    public:
        TelephoneWords();

        char get_char_key(int n, int p);

        void print_letters();

        std::stack<std::string> * get_words(int number);

        std::vector<int> transform_to_array(int number);

        void combine(std::stack<std::string> * & s2, std::string str, int i);

};
