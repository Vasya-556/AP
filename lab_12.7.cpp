#include <iostream>

using namespace std;

using namespace std;
typedef float Info;
struct Elem
{
    Elem *link;
    Info info;
};
void enqueue(Elem* &first, Elem* &last, Info value);
Info dequeue(Elem* &first, Elem* &last);
void print(Elem* first);
void build(Elem* &first, Elem* &last, Elem* first1, Elem* last1, Elem* first2, Elem* last2);
void addFirst(Elem* &first, Elem* &last, Info value);
bool isLastElement(Elem* last);
void deleteLast(Elem* &first, Elem* &last);

int main(){
    Elem *first = NULL,
        *last = NULL,
        *first1 = NULL,
        *last1 = NULL,
        *first2 = NULL,
        *last2 = NULL;
    
    int arr1[5] = {1,2,3,4,5};
    float arr2[5] = {1.5,2.5,3.5,4.5,5.5};

    for (int i = 0; i < 5; i++)
    {
        enqueue(first1,last1,arr1[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        enqueue(first2,last2,arr2[i]);
    }

    cout << "before:" << endl;
    
    print(first1);
    print(first2);

    build(first,last,first1,last1,first2,last2);
    if(isLastElement(last)){
    }
    else
    {
        addFirst(first,last,last->info);
        deleteLast(first,last);
    }
    cout << "after:" << endl;

    print(first1);
    print(first2);

    cout << "main:" << endl;

    print(first);

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

void print(Elem* first)
{
	while (first != NULL)
	{
		cout << first->info << "\t";
		first = first->link;
	}
	cout << endl;

}

void build(Elem* &first, Elem* &last, Elem* first1, Elem* last1, Elem* first2, Elem* last2){
    for (int i = 0; i < 5; i++)
    {
        enqueue(first,last,first1->info);
        enqueue(first,last,first2->info);
        dequeue(first1,last1);
        dequeue(first2,last2);
    }
}

void addFirst(Elem* &first, Elem* &last, Info value)
{
    Elem *tmp = new Elem;
    tmp->info = value;
    tmp->link = first;
    first = tmp;
    if (last == NULL)
        last = tmp;
}

bool isLastElement(Elem* last) {
    if (last != NULL) {
        if (typeid(last->info) == typeid(float)) {
            return false;
        } else if (typeid(last->info) == typeid(int)) {
            return true;
        }
    }
    return false;
}

void deleteLast(Elem* &first, Elem* &last)
{
    if (first == NULL) // якщо список пустий
        return;
    if (first == last) // якщо список містить лише один елемент
    {
        delete first;
        first = NULL;
        last = NULL;
        return;
    }
    Elem *prev = NULL;
    Elem *current = first;
    while (current->link != NULL) // перебігаємо список до його кінця
    {
        prev = current;
        current = current->link;
    }
    delete current; // видаляємо останній елемент
    prev->link = NULL; // робимо попередній елемент новим останнім елементом
    last = prev;
}
