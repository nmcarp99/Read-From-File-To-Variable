#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::vector <int> getInts(std::string filename) {
    char tempStr[100];
    std::vector< int > str;
    std::ifstream in(filename, std::ios::in);

    while (in.getline(tempStr, 100)) { //read characters from the file into str array
        str.push_back(int(std::stoi(tempStr)));
    }

    return str;

}
std::vector <std::string> getStrings(std::string filename) {
    char tempStr[100];
    std::vector< std::string > str;
    std::ifstream in(filename, std::ios::in);

    while (in.getline(tempStr, 100)) {
        str.push_back(tempStr);
    }

    return str;
}
int writeInts(std::string filename, std::vector< int > values, int numVals, bool append = false) {
    std::fstream file;
    if (!append) {
        file.open(filename, std::fstream::trunc | std::fstream::out);
    }
    else {
        file.open(filename, std::fstream::app | std::fstream::out);
        file << std::endl;
    }

    for (int i = 0; i < numVals; i++) {
        file << values[i];
        if (i != numVals - 1) {
            file << std::endl;
        }
    }

    file.close();

    return 0;
}
int writeStrings(std::string filename, std::vector< std::string > values, int numVals, bool append = false) {
    std::fstream file;
    if (!append) {
        file.open(filename, std::fstream::trunc | std::fstream::out);
    }
    else {
        file.open(filename, std::fstream::app | std::fstream::out);
        file << std::endl;
    }

    for (int i = 0; i < numVals; i++) {
        file << values[i];
        if (i != numVals - 1) {
            file << std::endl;
        }
    }

    file.close();

    return 0;
}
int replaceLinestrings(std::string filename, std::string value, int replaceLine, int numVals) {
    std::vector< std::string > currentFile = getStrings(filename);
    std::fstream file(filename, std::fstream::out | std::fstream::trunc);
    for (int i = 0; i < numVals; i++) {
        if (i != replaceLine) {
            file << currentFile[i];
        }
        else {
            file << value;
        }
        if (i != numVals - 1) {
            file << std::endl;
        }
    }

    file.close();

    return 0;
}
int replaceLineInts(std::string filename, int value, int replaceLine, int numVals) {
    std::vector< std::string > currentFile = getStrings(filename);
    std::fstream file(filename, std::fstream::out | std::fstream::trunc);
    for (int i = 0; i < numVals; i++) {
        if (i != replaceLine) {
            file << currentFile[i];
        }
        else {
            file << value;
        }
        if (i != numVals - 1) {
            file << std::endl;
        }
    }

    file.close();

    return 0;
}
std::string appData() {
    char* userVal;
    size_t len;
    errno_t appdataErr;
    std::string result;
    _dupenv_s(&userVal, &len, "APPDATA");
    for (int i = 0; userVal[i]; i++) {
        result += userVal[i];
    }
    result += "\\";
    free(userVal);
    return result;
}