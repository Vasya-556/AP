#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Print();
void Input();
void Overwrite();

int main(){
    short Menu;

    do
    {
        cout << endl << endl << endl;
        cout << "choose action:" << endl;
        cout << "[1] - print data" << endl;
        cout << "[2] - input data" << endl;
        cout << "[3] - overwrite data" << endl;
        cout << "[0] - exit" << endl << endl;
        cin >> Menu;
        cout << endl << endl << endl;
        switch (Menu)
        {
        case 1:
        Print();
            break;
        
        case 2:
        Input();
            break;
        
        case 3:
        Overwrite();
            break;
        
        case 0:
            break;
        
        default:
            cout << "Please choose" << endl;
            break;
        }
    } while (Menu != 0);

    return 0;
}

void Print(){
    string filename;
    string str;
    cout << "Enter filename to print data" << endl;
    cin >> filename;
    ifstream f(filename);
    while (getline(f,str))
    {
        cout << str << endl;
    }
    
    
    f.close();

}

void Input(){
    string str;
    string filename;
    cout << "Enter filename to input data" << endl;
    cin >> filename;
    cout << endl << "Enter data" << endl;
    cout << "type 'end' to end input" << endl; 
    
    ofstream fo (filename);
    
    do
    {
		getline(cin, str,'\n');
        if (str == "end")
            break;
        fo << str;
        fo << "\n";
    } while (str != "end");

    fo.close();
}

void Overwrite(){
    string filename1, filename2;
    string str, word;
    string currentWord, longestWord;
    int count = 0;
    cout << "Enter first filename" << endl;
    cin >> filename1;
    cout << "Enter second filename" << endl;
    cin >> filename2;
    
    fstream f1(filename1);
    ofstream f2(filename2);

    while (getline(f1,str))
    {
        if (count%2 != 0){
            count++;
            f2 << str;
            f2 << '\n';
            for(auto i : str){
                if (i == ' '){
                    if(currentWord.length() > longestWord.length()){
                        longestWord = currentWord;
                    }
                currentWord.clear();
                }
                else{
                    currentWord += i;
                }
            }
            
            if(currentWord.length() > longestWord.length()){
                longestWord = currentWord;
            }
            
        }

        else{
            count++;
            
            f2 << str + ' ' + longestWord;
            f2 << '\n';
            longestWord.clear();
        }
    }

    f1.close();
    f2.close();
}