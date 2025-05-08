#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void toLowerCase(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}

bool areEqualIgnoreCase(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower(*s1) != tolower(*s2)) return false;
        s1++; s2++;
    }
    return *s1 == '\0' && *s2 == '\0';
}

struct WordEntry {
    char* word;
    int count;
};

void addWord(WordEntry*& words, int& size, int& capacity, const char* newWord) {
    for (int i = 0; i < size; ++i) {
        if (areEqualIgnoreCase(words[i].word, newWord)) {
            words[i].count++;
            return;
        }
    }

    if (size == capacity) {
        capacity *= 2;
        WordEntry* temp = new WordEntry[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = words[i];
        }
        delete[] words;
        words = temp;
    }

    words[size].word = new char[strlen(newWord) + 1];
    strcpy(words[size].word, newWord);
    words[size].count = 1;
    size++;
}

int main() {
    const int MAX_LEN = 1000;
    char paragraph[MAX_LEN];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_LEN);

    int capacity = 10;
    int size = 0;
    WordEntry* wordList = new WordEntry[capacity];


    const char* delimiters = " ,.!?;:\n\t\r\"()[]{}";
    char* token = strtok(paragraph, delimiters);

    while (token != nullptr) {
        toLowerCase(token);
        addWord(wordList, size, capacity, token);
        token = strtok(nullptr, delimiters);
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; ++i) {
        cout << wordList[i].word << ": " << wordList[i].count << endl;
    }

    for (int i = 0; i < size; ++i) {
        delete[] wordList[i].word;
    }
    delete[] wordList;

    return 0;
}

