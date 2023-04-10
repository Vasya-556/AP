#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem *link;
    Info info;
};
void enqueue(Elem* &first, Elem* &last, Info value);
Info dequeue(Elem* &first, Elem* &last);
void Print(Elem* first);

int main(){
    int n;
    cout << "Enter N: "; cin >> n;
    Elem *first = NULL,
        *last = NULL;

    for (int i = 1; i < n; i++)
    {
        enqueue(first, last, i * 2);
        enqueue(first, last, i * 3);
        enqueue(first, last, i * 5);
    }

    Print(first);
    

    return 0;
}

void enqueue(Elem* &first, Elem* &last, Info value)
{
    Elem *tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = NULL; // 3
    if (last != NULL)
        last->link = tmp; // 4
    last = tmp; // 5
    if (first == NULL)
        first = tmp; // 6
}

Info dequeue(Elem* &first, Elem* &last)
{
    Elem *tmp = first->link; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    return value; // 6
}

void Print(Elem* first)
{
	while (first!=NULL)
	{
        cout << first->info << endl;
		first = first->link;
	}
	cout << endl;

}