//this programme takes a vector containing strings and finds the largerst string, the shortest, the lexigraphically first and last word in the string.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//pre-condition function to check the vector has enough items in it for the function to run. can be altered with size required by argument entered
void size_check(const std::vector<string>& vec ,int size) {
    if (vec.size() < size) throw "Not enough items in string for function to run";
}

//pre-condition for the vectors containing integers. same as function above
void size_int(const std::vector<int>& num, int size) {
    if (num.size() < size);
}

void print_int(std::vector<int>& ints) {
    if (ints.size() < 1) throw "Nothing to print";  //pre-condition 
    for (int i = 0; i < ints.size(); i++)
        std::cout << ints[i] << "\t" << std::endl;
}

//takes the vector of strings and makes a vector of integers. each integer in the new vector is the length of characters in the string. 
//"word" becomes '4', also retains its index position in the vector
std::vector<int> string_to_int(std::vector<std::string> vec) {
    size_check(vec, 1);
    std::vector<int> size_of_string{};
    for (int i = 0; i < vec.size(); ++i) {,
        std::string temp { vec[i] };
        int len { temp.size() };
       size_of_string.push_back(len);
    }
    //post-condition : size of vectors must match
    if (vec.size() != size_of_string.size())throw "string to integer error in conversion";
    return size_of_string;
}

void most_characters(std::vector<int>& length, std::vector<std::string>& largest_word) {
    size_int(length, 2);
    size_check(largest_word, 2);
    int largest { 0 };
    int index { 0 };
    for (int i = 0; i < length.size(); ++i) {
        if (length[i] > largest) {
            largest = length[i];
            index = i;
        }
    }
    std::cout << "Largest word: " << largest_word[index] << " - length: " << largest << std::endl;
}

void least_characters(std::vector<int>& length,vector<std::string>& smallest_word) {
    size_int(length, 2);
    size_check(smallest_word, 2);

    int smallest = 100;
    int index = 0;
    for (int i = 0; i < length.size(); ++i) {
        if (length[i] < smallest) {
            smallest = length[i];
            index = i;
        }
    }
    
    std::cout << "Smallest word: " << smallest_word[index] << " - length: " << smallest << std::endl;
}

void lexigraphically_first(std::vector<std::string>& words) {
    //pre-condition : vector must have size of atleast 2
    size_check(words, 2);

    std::vector<char> lex;
    for (int i = 0; i < words.size(); ++i) {
        std::string temp = words[i];
        lex.push_back(temp[0]);
    }
    int first = 123; //value larger than z as a char
    int index = 0;
    for (int i = 0; i < lex.size(); ++i) {
        if (lex[i] < first) {
            first = lex[i];
            index = i;
        }
    }
    std::cout << "Lexigraphically first word is: " << words[index] << std::endl;
}


//will find the alphabettically first word in the vector of strings and print it out
void lexigraphically_last(std::vector<std::string>& words) {
    //pre-condition : vector must have size of atleast 1
    if (words.size() < 2) throw "Not enough words to compare";

    std::vector<char> lex;
    for (int i = 0; i < words.size(); ++i) {    //converts the strings first letter into a vector containing char and keeps it in the same order
        std::string temp{ words[i] };
        lex.push_back(temp[0]);
    }
    int last{ 96 }; //value smaller than 'a' as a char
    int index{ 0 };
    for (int i = 0; i < lex.size(); ++i) {
        if (lex[i] > last) {
            last = lex[i];
            index = i;
        }
    }
    std::cout << "Lexigraphically last word is: " << words[index] << std::endl;
}


int main()
{

    try {
        std::vector<std::string> some_words{ "zulu","more", "word","longer","small", "bigger" };

        std::vector<int> size_of_string{ string_to_int(some_words) };

        print_int(size_of_string);

        least_characters(size_of_string, some_words);

        most_characters(size_of_string, some_words);

        lexigraphically_first(some_words);

        lexigraphically_last(some_words);
    }
    catch (const char* txtException) {
        std::cerr << "Exception: " << txtException << std::endl;
    }
    catch (...) {
        std::cerr << "Exception: unknown error";
    }
}
