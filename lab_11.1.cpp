#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print(char* filename);
void create(char* filename);
void overwrite(char* filename1, char* filename2);

int main(){
    char filename1[50];
    char filename2[50];
    cout << "Enter first filename" << endl;
    cin.getline(filename1, 50);
    cout << "Enter second filename" << endl;
    cin.getline(filename2, 50);
    cout << endl << endl;
    create(filename1);
    cout << endl << endl;
    overwrite(filename1, filename2);
    cout << endl << endl;
    print(filename2);

    return 0;
}

void print(char* filename){
    ifstream fin(filename, ios::binary);
    char symbol;
    cout << "content: " << endl;
    while (fin.get(symbol))
    {
        cout << symbol << ' ';
    }

    cout << endl;
    fin.close();
}

void create(char* filename){
    ofstream fout(filename, ios::binary);
    cout << "Enter data \npress 'q' to quit: " << endl;
    char symbol;
    while (cin.get(symbol) && symbol!= 'q') {
        fout.put(symbol);
    }
    
    fout.close();
}

void overwrite(char* filename1, char* filename2){
    ifstream f1(filename1, ios::binary);
    ofstream f2(filename2, ios::binary);
    string data;
    int pos = 0;
    
    while(f1 >> data){
        if(data != "g" && data != "e" && data != "o" && data != "m" && data != "t" && data != "r" && data != "y"){
            f2 << data;
        }
    }

    f1.close();
    f2.close();
}