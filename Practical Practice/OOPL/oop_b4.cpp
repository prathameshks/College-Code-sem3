/*
Write a C++ program that creates an output file, writes information to it,
closes the file, open it again as an input file and read the information from
the file.*/

#include <fstream>
#include <iostream>
using namespace std;

void write() {
    ofstream file("sample.txt");
    string data;
    int n;
    cout << "Enter number of lines to write:";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter data:";
        getline(cin, data);
        file << data<<endl;
    }
}

void read() {
    ifstream file("sample.txt");
    string data;
    while (getline(file,data))
    {
        cout<<data<<endl;
    }
    
}

int main() {
    write();
    read();
    return 0;
}