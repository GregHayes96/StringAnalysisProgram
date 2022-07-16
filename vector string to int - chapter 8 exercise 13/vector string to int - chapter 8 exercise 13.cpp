//this programme takes a vector containing strings and finds the largerst string, the shortest, the lexigraphically first and last word in the string.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print_int(vector<int>& ints) {
    for (int i = 0; i < ints.size(); i++)
        cout << ints[i] << "\t";
    cout << endl;
}

vector<int> string_to_int(vector<string> a) {
    vector<int> size_of_string{};
    for (int i = 0; i < a.size(); ++i) {
       string temp = a[i];
       int len = temp.size();
       size_of_string.push_back(len);
    }
    return size_of_string;
}

void most_characters(vector<int>& length, vector<string>& largest_word) {
    int largest = 0;
    int index = 0;
    for (int i = 0; i < length.size(); ++i) {
        if (length[i] > largest) {
            largest = length[i];
            index = i;
        }
    }
    cout << "Largest word: " << largest_word[index] << " - length: " << largest << endl;
}

void least_characters(vector<int>& length,vector<string>& smallest_word) {
    int smallest = 100;
    int index = 0;
    for (int i = 0; i < length.size(); ++i) {
        if (length[i] < smallest) {
            smallest = length[i];
            index = i;
        }
    }
    
    cout << "Smallest word: " << smallest_word[index] << " - length: " << smallest << endl;
}

void lexigraphically_first(vector<string>& words) {
    vector<char> lex;
    for (int i = 0; i < words.size(); ++i) {
        string temp = words[i];
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
    cout << "Lexigraphically first word is: " << words[index] << endl;
}


//will find the alphabettically first word in the vector of strings and print it out
void lexigraphically_last(vector<string>& words) {
    vector<char> lex;
    for (int i = 0; i < words.size(); ++i) {    //converts the strings first letter into a vector containing char and keeps it in the same order
        string temp = words[i];
        lex.push_back(temp[0]);
    }
    int last = 96; //value smaller than a as a char
    int index = 0;
    for (int i = 0; i < lex.size(); ++i) {
        if (lex[i] > last) {
            last = lex[i];
            index = i;
        }
    }
    cout << "Lexigraphically last word is: " << words[index] << endl;
}


int main()
{

    try {
        vector<string> some_words{ "zulu","more", "word","longer","small", "bigger" };

        vector<int> size_of_string = string_to_int(some_words);

        print_int(size_of_string);

        least_characters(size_of_string, some_words);

        most_characters(size_of_string, some_words);

        lexigraphically_first(some_words);

        lexigraphically_last(some_words);
    }
    catch (const char* txtException) {
        cerr << "Exception: " << txtException << endl;
    }
}
