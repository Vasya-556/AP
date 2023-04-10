#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

string Erase(string str);
void InFile(string& str);
string FromFile(char* fname);


int main(){
    char fname[] = "t1.txt";
    string s=FromFile(fname);
	s=Erase(s);
	InFile(s);
    return 0;
}

string Erase(string str){
    string new_str;
    bool in_brackets = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            in_brackets = true;
        }
        else if (str[i] == ')') {
            if (in_brackets) {
                in_brackets = false;
            }
            else {
                return "Eror";
            }
        }
        else if (!in_brackets) {
            new_str += str[i];
        }
    }
    return new_str;
}

void InFile(string& str)
{
	ofstream f("t2.txt");
	f << str;
	f.close();
}

string FromFile(char* fname)
{
	ifstream fin(fname);
	string s;
	getline(fin, s);
	fin.close();
	return s;
}