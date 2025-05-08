#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_LINE_LENGTH = 1024;

int countWordsInLine(const char* line) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; line[i]; ++i) {
        if (isalnum(line[i])) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

void expandLinesArray(char**& lines, int& capacity) {
    int newCapacity = capacity * 2;
    char** newLines = new char*[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        newLines[i] = lines[i];
    }

    delete[] lines;
    lines = newLines;
    capacity = newCapacity;
}

int main() {
    char filename[256];
    cout << "Enter the name of the text file: ";
    cin.getline(filename, 256);

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file \"" << filename << "\".\n";
        return 1;
    }

    int capacity = 10;
    int lineCount = 0, wordCount = 0, charCount = 0;

    char** lines = new char*[capacity];

    char buffer[MAX_LINE_LENGTH];

    while (file.getline(buffer, MAX_LINE_LENGTH)) {
        int len = strlen(buffer);
        charCount += len;
        wordCount += countWordsInLine(buffer);

        if (lineCount == capacity) {
            expandLinesArray(lines, capacity);
        }

        lines[lineCount] = new char[len + 1];
        strcpy(lines[lineCount], buffer);
        lineCount++;
    }

    charCount += lineCount;

    cout << "\nFile Statistics:\n";
    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters (incl. spaces/punctuation): " << charCount << endl;

    for (int i = 0; i < lineCount; ++i) {
        delete[] lines[i];
    }
    delete[] lines;
    file.close();

    return 0;
}
