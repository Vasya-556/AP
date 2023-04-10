#include <iostream>
#include <string>

using namespace std;

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

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Result: " << Erase(str) << endl;
    return 0;
}