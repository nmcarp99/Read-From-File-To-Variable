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