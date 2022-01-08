#include <iostream>
#include <stdio.h>
#include <string>

#define gccVersion 17

using namespace std;

int main() {
    string filePath;
    string sysCommit;

    // cout << "file path:";
    // cin >> filePath;

    // g++ -Wall -std=c++17 ./test.cpp -o ./out.exe
    sysCommit
        .append("g++ ")
        // .append("\'" + filePath + "\' ")
        .append("-Wall ")
        .append("-std=c++17 ")
        .append("./test.cpp ")
        // .append("")
        .append("-o ./out.exe");

    cout << sysCommit << endl;

    system(sysCommit.c_str());

    // type "./input.txt" | ./out.exe > "./output.txt"
    sysCommit = "";
    sysCommit.append("type ")
        .append("\"./input.txt\" ")
        .append("| ")
        .append("\"./out.exe\"")
        .append("> ")
        .append("\"./output.txt\"");
    system(sysCommit.c_str());
    // sysCommit = "cat ./output.txt";
    // system(sysCommit.c_str());
}
