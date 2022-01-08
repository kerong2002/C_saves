#include <iostream>
#include <stdio.h>
#include <string>
#define gccVersion 14

using namespace std;

int main() {
    string filePath;
    string sysCommit_answer;
    string sysCommit_test;
//call answer code
    sysCommit_answer
        .append("g++ ")
        .append("-std=c++17 ")
        .append("./work_17_answer_code.cpp ")
        .append("-o ./out.exe");
    cout << sysCommit_answer<< endl;

    system(sysCommit_answer.c_str());

    sysCommit_answer = "";
    sysCommit_answer.append("type ")
        .append("\"./input.txt\" ")
        .append("| ")
        .append("\"./out.exe\"")
        .append("> ")
        .append("\"./answer_output.txt\"");
    system(sysCommit_answer.c_str());


//call classmates code
    sysCommit_test
        .append("\ng++ ")
        .append("-std=c++17 ")
        .append("./classmate_code.cpp ")
        .append("-o ./out.exe");

    cout << sysCommit_test<< endl;

    system(sysCommit_test.c_str());

    sysCommit_test = "";
    sysCommit_test.append("type ")
        .append("\"./input.txt\" ")
        .append("| ")
        .append("\"./out.exe\"")
        .append("> ")
        .append("\"./classmates_output.txt\"");
    system(sysCommit_test.c_str());

}
