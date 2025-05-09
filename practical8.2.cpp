#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

void countWordFrequency(const string& input) {
    map<string, int> wordCount;
    string word;
    stringstream ss(input);
    while (ss >> word) {

        for (char& c : word) {
            c = tolower(c);
        }

        wordCount[word]++;
    }

    cout << "\nWord Frequency Distribution:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);

    countWordFrequency(input);

    return 0;
}
