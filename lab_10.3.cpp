#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <ctime>

using namespace std;

struct Inhabitant
{
    string prizv;
    string Initial;
    short nomer;
    bool nomerType;
    string strNomerType;
};

void Create();
void Print();
void Add();
void Remove();
void Find();
void Change();
Inhabitant Parse(string str);
Inhabitant* AddData(Inhabitant* arr, short& N, Inhabitant obj);
void SaveToFile(Inhabitant* arr, short N, string filename);

int main(){
    short menuItem;
    do
    {   
        cout << endl << endl << endl;
        cout << "[1] - Create" << endl;
        cout << "[2] - Print" << endl;
        cout << "[3] - Add" << endl;
        cout << "[4] - Remove" << endl;
        cout << "[5] - Find" << endl;
        cout << "[6] - Change" << endl;
        cout << "[0] - Exit" << endl << endl;
        cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create();
            break;
        
        case 2:
            Print();
            break;
        
        case 3:
            Add();
            break;
        
        case 4:
            Remove();
            break;

        case 5:
            Find();
            break;
        
        case 6:
            Change();
            break;

        case 0:
            break;
                
        default:
            cout << "Eror data" << endl;
        }        
    } while (menuItem != 0);

    return 0;
}

void Create(){
    short N = 0;
    short choose;
    float count1 = 5;
    short count2 = 0;
    string filename;
    // i - is; s - single; r - room; d - don`t  ; e - exist; d - double
    bool ISDRE = false;
    bool IDDRE = false;
    cout << "Enter filename: " << endl;
    cin >> filename;
    cout << endl;
    do
    {
        cout << "Enter count:" << endl;
        cin >> N;

        if (N>25)
            cout << "Enter less then 25" << endl;
    } while (N>25);

    ofstream fout(filename);
    
    for (size_t i = 0; i < N; i++){
        Inhabitant in;
        cout << endl << "Inhabitans No: " << i+1 << endl << endl;
        cout << "Prizv:" << endl; 
        cin >> in.prizv;
        cout << "Initial:" << endl; 
        cin >> in.Initial;
        if (count1 == 25)
            IDDRE = true;
        if (count2 == 5)
            ISDRE = true;
        do
        {
            cout << endl;
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
                    in.nomerType = false;
                    choose = 0;
                }
                break;
            
            case 2:
                in.nomerType = true;
                choose = 0;
                break;
            
            default:
                cout << "plase choose" << endl << endl;
            }
        } while (choose != 0);

        if (in.nomerType){
            //double
            count1 += 0.5;
            in.nomer = ceil(count1);
            in.strNomerType = "double";
        }
        else{
            //single
            count2 += 1;
            in.nomer = count2;
            in.strNomerType = "single";
        }
        fout << in.prizv + "%" << in.Initial + "%" << to_string(in.nomer) + "%" << in.strNomerType + "%" << endl;
    }
    fout.close();
}

void Print(){
    string filename;
    string str;
    short i = 0;
    cout << "Enter filename" << endl;
    cin >> filename;
	ifstream fin(filename);
    cout << "=================================================="<< endl;
    cout << "| No  |   prizv.   | Initial | nomer | nomerType |" << endl; 
    cout << "--------------------------------------------------"<< endl;
    while (getline(fin, str))
	{
        Inhabitant in = Parse(str);
        cout << "| " << setw(3) << right << i+1 << " ";
        cout << "| " << setw(11) << left << in.prizv
        << "| "<< setw(8) << left << in.Initial << "| " 
        << setw(5) << right << in.nomer << " "
        << "| " << setw(10) << left <<  in.strNomerType  << "|"<< endl;
		i++;
	}
    cout << "=================================================="<< endl;
}

void Add(){
    string filename;
    short a;
    short choose;
    cout << "Enter filename" << endl;
    cin >> filename;
    ofstream fout(filename, ios::app);
    Inhabitant in;
    cout << endl ;
    cout << "Prizv:" << endl; 
    cin >> in.prizv;
    cout << "Initial:" << endl; 
    cin >> in.Initial;
    do
    {
        cout << endl;
        cout << " [1] - single room" << endl;
        cout << " [2] - double room" << endl << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            do
            {
                cout << "chose room beetwen 1-5" << endl;
                cin >> in.nomer;
                in.strNomerType = "single";
            } while ( a > 5 && a < 0);
            choose = 0;
            break;
        
        case 2:
            do
            {
                cout << "chose room beetwen 5-25" << endl;
                cin >> in.nomer;
                in.strNomerType = "double";
            } while ( a > 25 && a < 6);
            choose = 0;
            break;
        
        default:
            cout << "plase choose" << endl << endl;
        }
    } while (choose != 0);
    

        
    fout << in.prizv + "%" << in.Initial + "%" << to_string(in.nomer) + "%" << in.strNomerType + "%" << endl;

    fout.close();
}

void Remove(){
    string filename;
    short index;
    string str;
    short N = 0;
    bool moved = false;
    cout << "Enter filename" << endl;
    cin >> filename;
    cout << "Enter the No of inhabitant which you want to remove" << endl;
    cin >> index;
    ifstream fin;
	fin.open(filename);
    Inhabitant* in = new Inhabitant[0];
    while (getline(fin, str))
	{
		in = AddData(in, N, Parse(str));
	}
    Inhabitant* nin = new Inhabitant[N];

    for (size_t i = 0; i < N - 1; i++){
        if (i == index - 1)
            moved = true;
        if (moved)
            nin[i] = in[i+1];
        else 
            nin[i] = in[i];
    }
    --N;
    SaveToFile(nin,N,filename);
}

void SaveToFile(Inhabitant* arr, short N, string filename){
    ofstream fout(filename);
	for (size_t i = 0; i < N; i++)
	{
        Inhabitant in = arr[i];
        fout << in.prizv + "%" << in.Initial + "%" << to_string(in.nomer) + "%" << in.strNomerType + "%" << endl;
    }
	fout.close();
}

void Find(){
    string filename;
    string Prizv;
    string initial;
    string str;
    string str2;
    
    short count = 0;
    short count2 = 0;
    short a = 0;
    short b = 0;
    short i = 0;
    short j = 0;
    
    cout << "Enter filename" << endl;
    cin >> filename;
    ifstream fin(filename);
    ifstream fin2(filename);
    cout << "Enter prizv are you looking for" << endl;
    cin >> Prizv;
    
    Inhabitant in;
    while (getline(fin, str))
    {
        Inhabitant tmp;
        tmp = Parse(str);
        if (tmp.prizv == Prizv)
        {
            count ++;
            in = tmp;
            a = i + 1;
        }
        i++;
    }
    
    if (count == 0){
        cout << "Not find" << endl;
    }

    if (count == 1){
        cout << "found the right inhabitant in the room No: " << a << endl;
    }

    if (count > 1){
        cout << "we have more than one people are you search" << endl << endl;
        cout << "please enter the initial of searching people" << endl;
        cin >> initial;
        while (getline(fin2, str2))
        {
            Inhabitant tmp;
            tmp = Parse(str2);
            if (tmp.Initial == initial)
            {
                count2 ++;
                in = tmp;
                b = j + 1;
            }
            j++;
        }

        if (count2 == 0){
            cout << "we don't have this man" << endl;
        }

        if (count2 == 1){
            cout << "found the right inhabitant in the room No: " << b << endl;
        }
                    
        
        if (count2 > 1){
            cout << "sorry can't found this man, not enough information" << endl;
        }
    }
}

void Change(){
    string filename;
    string str;
    short N = 0;
    short index = 0;
    short choose;
    short a;
    Inhabitant* arr = new Inhabitant[0];
    
    cout << "Enter filename" << endl;
    cin >> filename;
    cout << "Enter the No of inhabitant which you want to remove" << endl;
    cin >> index;
    ifstream fin(filename);
    while (getline(fin, str))
	{
		arr = AddData(arr, N, Parse(str));
	}
    fin.close();
    if (index < N){
        Inhabitant in;
        cout << "Prizv:" << endl; 
        cin >> in.prizv;
        cout << "Initial:" << endl; 
        cin >> in.Initial;
        do
        {
            cout << endl;
            cout << " [1] - single room" << endl;
            cout << " [2] - double room" << endl << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                do
                {
                    cout << "chose room beetwen 1-5" << endl;
                    cin >> in.nomer;
                    in.strNomerType = "single";
                } while ( a > 5 && a < 0);
                choose = 0;
                break;
            
            case 2:
                do
                {
                    cout << "chose room beetwen 5-25" << endl;
                    cin >> in.nomer;
                    in.strNomerType = "double";
                } while ( a > 25 && a < 6);
                choose = 0;
                break;
            
            default:
                cout << "plase choose" << endl << endl;
            }
        } while (choose != 0);
       
        arr[index] = in;
    }
    else{
        cout << "we don't have this inhabitant" << endl;
    }
    SaveToFile(arr, N, filename);
}

Inhabitant Parse(string str){
    Inhabitant in;
    in.prizv = str.substr(0, str.find_first_of("%"));
    str.erase(0, str.find_first_of("%") + 1);
    in.Initial = str.substr(0, str.find_first_of("%"));
    str.erase(0, str.find_first_of("%") + 1);
    string s = str.substr(0, str.find_first_of("%"));
    in.nomer = atoi(s.c_str());
    str.erase(0, str.find_first_of("%") + 1);
    in.strNomerType = str.substr(0, str.find_first_of("%"));
    str.erase(0, str.find_first_of("%") + 1);
    return in;
}

Inhabitant* AddData(Inhabitant* arr, short& N, Inhabitant obj){
    Inhabitant* arr2 = new Inhabitant[N+1];
    for (size_t i = 0; i < N; i++)
	{
		arr2[i] = arr[i];
	}
    arr2[N] = obj;
	N++;
    return arr2;
}