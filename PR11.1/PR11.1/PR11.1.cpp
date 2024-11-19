#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція, яка перевіряє наявність пари "no" або "on" в рядку
bool ContainsPair(const string& s) {
    return (s.find("no") != string::npos || s.find("on") != string::npos);
}

// Функція, яка замінює кожну пару "no" на "***"
string ReplaceNo(string& s) {
    size_t pos = 0;
    while ((pos = s.find("no", pos)) != string::npos) {
        s.replace(pos, 2, "***");
        pos += 3; // перемістити позицію на кінець заміни, щоб уникнути зациклення
    }
    return s;
}

// Основна функція
int main() {
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    string line;
    bool containsPair = false;

    cout << "File content with replacements:" << endl;
    while (getline(inputFile, line)) {
        if (ContainsPair(line)) {
            containsPair = true;
        }
        cout << ReplaceNo(line) << endl; // Виводимо замінену строку
    }

    inputFile.close();

    if (containsPair) {
        cout << "The file contains 'no' or 'on'." << endl;
    }
    else {
        cout << "The file does not contain 'no' or 'on'." << endl;
    }

    return 0;
}
