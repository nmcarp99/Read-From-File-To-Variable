#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

vector <int> getInts(string filename) {
    char tempStr[100];
    std::vector< int > str;
    ifstream in(filename, ios::in);

    while (in.getline(tempStr, 100)) { //read characters from the file into str array
        str.push_back(int(stoi(tempStr)));
    }

    return str;

}
vector <string> getStrings(string filename) {
    char tempStr[100];
    std::vector< string > str;
    ifstream in(filename, ios::in);

    while (in.getline(tempStr, 100)) {
        str.push_back(tempStr);
    }

    return str;
}
int writeInts(string filename, vector< int > values, int numVals, bool append = false) {
    fstream file;
    if (!append) {
        file.open(filename, fstream::trunc | fstream::out);
    }
    else {
        file.open(filename, fstream::app | fstream::out);
        file << endl;
    }

    for (int i = 0; i < numVals; i++) {
        file << values[i];
        if (i != numVals - 1) {
            file << endl;
        }
    }

    file.close();

    return 0;
}
int writeStrings(string filename, vector< string > values, int numVals, bool append = false) {
    fstream file;
    if (!append) {
        file.open(filename, fstream::trunc | fstream::out);
    }
    else {
        file.open(filename, fstream::app | fstream::out);
        file << endl;
    }

    for (int i = 0; i < numVals; i++) {
        file << values[i];
        if (i != numVals - 1) {
            file << endl;
        }
    }

    file.close();

    return 0;
}