#include <iostream>
#include <string>
using namespace std;

void Display(string word, int length)
{
    cout << "Longest Word: " << word << endl;
    cout << "Number of letters: " << length << endl;
}

int main()
{
    string sentence, word = "", longest = "";

    cout << "Enter a sentence: ";
    getline(cin, sentence);


    sentence = sentence + " ";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            word = word + sentence[i];
        }
        else
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }
            word = "";
        }
    }

    Display(longest, longest.length());

    return 0;
}
