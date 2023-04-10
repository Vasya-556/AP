#include <iostream>
#include <string>
#include <iomanip>
 // забезпечення відображення кирилиці
using namespace std;

enum Posada { ROBITNYK, INZHENER, SLUZHBOVETS };

string posadaStr[] = { "робітник", "інженер", "службовець" };

struct Pracivnyk{
    string prizv;
    unsigned rik_nar;
    Posada posada;
    union    {
        double taryf;
        int stavka;
    };
};

void Create(Pracivnyk *p, const int N);
void Print(Pracivnyk *p, const int N);

int main(){ // забезпечення відображення кирилиці:
    int N;
    cout << "Введіть N: "; 
    cin >> N;
    
    Pracivnyk *p = new Pracivnyk[N];
    
    Create(p, N);
    Print(p, N);

    return 0;
}

void Create(Pracivnyk *p, const int N){
    int posada;
    for (int i=0; i< N; i++){
        cout << "Працівник No " << i+1 << ":" << endl;
        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
        cout << " прізвище: "; 
        getline(cin, p[i].prizv);
        cout << " рік нар.: "; 
        cin >> p[i].rik_nar;
        cout << " посада (0 - робітник, 1 - інженер, 2 - службовець): ";
        cin >> posada;
        p[i].posada = (Posada)posada;
        switch ( p[i].posada ){
            case ROBITNYK:
            cout << " тариф : "; cin >> p[i].taryf;
            break;
            case INZHENER:
            case SLUZHBOVETS:
            cout << " ставка : "; cin >> p[i].stavka;
            break;
        }
        cout << endl;
    }
}

void Print(Pracivnyk *p, const int N)
{
cout << "========================================================================="
<< endl;
cout << "| No  | Прізвище | Рік.нар. | Посада | Тариф | Ставка |"
<< endl;
cout << "-------------------------------------------------------------------------"
<< endl;
for (int i=0; i<N; i++)
{
cout << "| " << setw(3) << right << i+1 << " ";
cout << "| " << setw(13) << left << p[i].prizv
<< "| " << setw(4) << right << p[i].rik_nar << " "
<< "| " << setw(11) << left << posadaStr[ p[i].posada ];
switch ( p[i].posada )
{
case ROBITNYK:
cout << "| " << setw(9) << setprecision(2) << fixed << right
<< p[i].taryf << " |" << setw(13) << right << "|" << endl;
break;
case INZHENER:
case SLUZHBOVETS:
cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
<< p[i].stavka << " |" << endl;
break;
}
}
cout << "========================================================================="
<< endl;
cout << endl;
}