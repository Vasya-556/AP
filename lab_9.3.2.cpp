#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Inhabitant
{
    string prizv;
    string Initial;
    short nomer;
    bool nomerType;
    string strNomerType;
};


void Create(Inhabitant *p,const int N, float& count1, int& count2);
void print(Inhabitant *p,const int N);
void Remove(Inhabitant *p, int& N, int index);
void Change(Inhabitant *p, int index, float& count1, int& count2);
void Find(Inhabitant *p, const int N, string Prizv);
void SaveToFile(Inhabitant *p, const int N, const char *filename); 
void LoadFromFile(Inhabitant *&p, int &N, const char *filename); 

int main(){
    int N;
    float count1 = 5;
    int count2 = 0;
    int index;
    string Prizv;
    char filename[100]; 
    do
    {
        cout << "Enter the number of inhabitans"<< endl;
        cin >> N;
        
        if (N>25){
            cout << "we don't have enough seats" << endl << endl;
        }

    } while (N>25);
    Inhabitant *p = new Inhabitant[N];
    
    short menuItem;
    do
    {
        cout << endl << endl << endl;
        cout << "[1] - create list" << endl;
        cout << "[2] - remove data" << endl;
        cout << "[3] - change data" << endl;
        cout << "[4] - print data" << endl;
        cout << "[5] - find" << endl;
        cout << "[6] - save to file" << endl;
        cout << "[7] - load from file" << endl;
        cout << "[0] - exit" << endl;
        cout << "Enter data:" << endl;
        cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            count1 = 5;
            count2 = 0;
            Create(p,N,count1,count2);
            break;

        case 2:
            do
            {
                cout << "Enter the No of inhabitant which you want to remove" << endl;
                cin >> index;
                index --;
                if (index > N)
                    cout << "we dont have this inhabitant" << endl << endl;
            } while (index > N);
            
            Remove(p,N,index);
            break;

        case 3:
            do
            {
                cout << "Enter the No of inhabitant which you want to change" << endl;
                cin >> index;
                index --;
                if (index > N)
                    cout << "we dont have this inhabitant" << endl << endl;
            } while (index > N);
            
            Change(p,index, count1, count2);
            break;
        
        case 4:
            print(p,N);
            break;

        case 5:
            cout << "Enter prizv are you looking for" << endl;
            cin >> Prizv;
            Find(p,N,Prizv);
            break;
            
        case 6:
        
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи  
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок   
            cout << "Введіть ім'я файлу: "; 
            cin.getline(filename, 99);  
            SaveToFile(p, N, filename); 
            break;
        
        case 7:
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи  
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок   
            cout << "Введіть ім'я файлу: ";
            cin.getline(filename, 99);  
            LoadFromFile(p, N, filename); 
            break;
        
        case 0:
            break;
        
        default:
            cout << "Eror data" << endl;
        }
    } while ( menuItem != 0);

    return 0;
}

void Create(Inhabitant *p,const int N, float& count1, int& count2){
    short choose;
    // i - is; s - single; r - room; d - don`t  ; e - exist; d - double
    bool ISDRE = false;
    bool IDDRE = false;
    for (int i=0; i < N; i++){
        cout << endl << "Inhabitant No " << i + 1 << ":" << endl << endl;
        
        cin.get();
        cin.sync();
        cout << "Prizv: " << endl;
        getline(cin, p[i].prizv);
        cout << "Initial: " << endl;
        getline(cin, p[i].Initial);
        cout << endl;
        if (count1 == 25)
            IDDRE = true;
        if (count2 == 5)
            ISDRE = true;
        do
        {
            cout << " [1] - single room" << endl;
            cout << " [2] - double room" << endl << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                if (ISDRE)
                {
                    cout << "We don't have enough seats"<< endl;
                }
                else
                {
                    p[i].nomerType = false;
                    choose = 0;
                }
                break;
            
            case 2:
                p[i].nomerType = true;
                choose = 0;
                break;
            
            default:
                cout << "plase choose" << endl << endl;
            }
        } while (choose != 0);
        if (p[i].nomerType){
            //double
            count1 += 0.5;
            p[i].nomer = ceil(count1);
            p[i].strNomerType = "double";
        }
        else{
            //single
            count2 += 1;
            p[i].nomer = count2;
            p[i].strNomerType = "single";
        }
    }
}

void print(Inhabitant *p, const int N){
    cout << "=================================================="<< endl;
    cout << "| No  |   prizv.   | Initial | nomer | nomerType |" << endl; 
    cout << "--------------------------------------------------"<< endl;
    for(int i=0; i<N;i++){
        cout << "| " << setw(3) << right << i+1 << " ";
        cout << "| " << setw(11) << left << p[i].prizv
        << "| "<< setw(8) << left << p[i].Initial << "| " 
        << setw(5) << right << p[i].nomer << " "
        << "| " << setw(10) << left <<  p[i].strNomerType  << "|"<< endl;
    }
    cout << "=================================================="<< endl;
}

void Remove(Inhabitant *p, int& N, int index){
    for (int i = index; i < N - 1; i++)
    {
        p[i] = p[i+1];
    }
    N --;
}

void Change(Inhabitant *p, int index, float& count1, int& count2){
    short choose;
    bool ISDRE = false;
    bool IDDRE = false;
    cin.get();
    cin.sync();
    cout << "Prizv: " << endl;
    getline(cin, p[index].prizv);
    cout << "Initial: " << endl;
    getline(cin, p[index].Initial);
    cout << endl;
    if (count1 == 25)
            IDDRE = true;
        if (count2 == 5)
            ISDRE = true;
        do
        {
            cout << " [1] - single room" << endl;
            cout << " [2] - double room" << endl << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                if (ISDRE)
                {
                    cout << "We don't have enough seats"<< endl;
                }
                else
                {
                    p[index].nomerType = false;
                    choose = 0;
                }
                break;
            
            case 2:
                p[index].nomerType = true;
                choose = 0;
                break;
            
            default:
                cout << "plase choose" << endl << endl;
            }
        } while (choose != 0);
        if (p[index].nomerType){
            //double
            count1 += 0.5;
            p[index].nomer = ceil(count1);
            p[index].strNomerType = "double";
        }
        else{
            //single
            count2 += 1;
            p[index].nomer = count2;
            p[index].strNomerType = "single";
        }
}

void Find(Inhabitant *p, const int N, string Prizv){
    short count = 0;
    short a = 0;
    short b = 0;
    string initial;
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        if (p[i].prizv == Prizv){
            count ++;
            a = i + 1;
        }
        if (i == N-1){
            if (count == 0){
                cout << "Not find" << endl;
            }
            if (count == 1){
                cout << "found the right inhabitant in the room No: " << a << endl;
            }
            if (count > 1){
                cout << "we have more than one people are you search" << endl;
                cout << "please enter the initial of searching people" << endl;
                cin >> initial;
                for (int j = 0; j < N; j ++){
                    if (p[j].prizv == Prizv && p[j].Initial == initial){
                        b = j + 1;
                    }
                }
                cout << "found the right inhabitant in the room No: " << b << endl;
            }
        }
    }
}

void SaveToFile(Inhabitant *p, const int N, const char *filename)
{ 
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису  
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів 
    for (int i=0; i<N; i++)  
        fout.write((char*)&p[i], sizeof(Inhabitant)); // записали елементи масиву 
    fout.close(); // закрили файл
}

void LoadFromFile(Inhabitant *&p, int &N, const char *filename) 
{ 
    delete [] p; // знищили попередні дані  
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування  
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів  
    p = new Inhabitant[N]; // створили динамічний масив 
    for (int i=0; i<N; i++)  
    fin.read((char*)&p[i], sizeof(Inhabitant)); // прочитали елементи масиву 
    fin.close(); // закрили файл 
}