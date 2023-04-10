#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef int Info;
struct Elem
{
    Elem *next,
    *prev;
    Info info;
};
void enqueue(Elem* &first, Elem* &last, Info value);
Info dequeue(Elem* &first, Elem* &last);
void ReadFromFile(Elem* &first, Elem* &last, char* fname);
void Print(Elem* L);
bool hasDuplicate(Elem* L, string &s);

int main(){
    Elem *first = NULL;
    Elem *last = NULL;
    string s;
    char fname[] = "data1.txt";
    ReadFromFile(first,last,fname);
    // Print(first);

    if(hasDuplicate(first, s)){
        cout << "exist" << endl;
        cout << s << endl;
    }
    else{
        cout << "not exist" << endl;
    }
    return 0;
}

void enqueue(Elem* &first, Elem* &last, Info value)
{
    Elem *tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}

Info dequeue(Elem* &first, Elem* &last)
{
    Elem *tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value; // 7
}

void ReadFromFile(Elem* &first, Elem* &last, char* fname){
	ifstream f(fname);
    int start = 0, end, value;
    string data;
    getline(f, data);
    while (data.find_first_of("0123456789", start) != -1) {
        start = data.find_first_of("0123456789", start);
        end = data.find_first_of(" ,.", start);
        value = stoi(data.substr(start, end - start));
        enqueue(first, last, value);
        start = end + 1;
    }
    last->next = first;
    first->prev = last;
}

void Print(Elem* L){
    if (L == NULL)
        return;
    Elem *first = L;
    do
    {
        cout << L->info << endl;
        L = L->next;
    } while (L!= first);
    
}

bool hasDuplicate(Elem* L, string &s) {
    bool result = false;
    Elem* first1 = L;
    Elem* first2 = L;
    Elem* current = L;
    int i = 0;
    while(L->next != first1){
        while (current->next != first2)
        {
            if (current->info == L->info){
                i++;
                if (i > 4){
                    s += to_string(current->info);
                    s += "\t";
                }
            }
            current = current->next;
        }
        current = L->next;
        L = L->next;
    }

    if(i > 4)
        result = true;

    return result;
}