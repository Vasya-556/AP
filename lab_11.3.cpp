#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

enum Specialnists
{
	computer_science,
	informatic,
	math_a_economics,
	physics_and_informatic,
	labor_education
};

struct Student
{
	string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};
	float average;
};

string List[] = {
	"computer science",
	"informatic",
	"math and economics",
	"physics and informatic",
	"labor education",
	"average"
};

void Create(Student& stud, const int N, string filename);
void Print(Student& stud, const int N, string filename);
void Sort(Student& stud, const int N, string filename);
void IndexSort(Student& stud, const int N, string filename1, string filename2);
void IndexPrint(Student& stud, const int N, string filename1, string filename2);
void Find(Student& stud, const int N, string filename);
void ToFile(Student& stud, const int N, string filename);
void fWrite(fstream& f, const int i, Student x);
Student fRead(fstream& f, const int i);
Student fRead2(ifstream& f, const int i);
void fChange(fstream& f, const int i, const int j);
int BinSearch(Student& stud1, const int N, string prizv, Specialnists special, float average, string filename);

int main(){
    int MenuItem, N, spec, num;
	float average;
    string prizv, filename, filename2;
	Student st;
	Specialnists sp;
	cout << "Enter count of student:" << endl;
	cin >> N;
	cout << "Enter filename:" << endl;
	cin >> filename;
    
    do
    {
        cout << endl << endl;
        cout << "[1] - Create" << endl;
        cout << "[2] - Print" << endl;
        cout << "[3] - Sort" << endl;
        cout << "[4] - Index" << endl;
        cout << "[5] - Find" << endl;
        cout << "[0] - Exit" << endl;
        cout << "Chose:" << endl;
        cin >> MenuItem;
        switch (MenuItem)
        {
        case 1:
		Create(st, N, filename);
            break;

        case 2:
		Print(st,N,filename);
            break;

        case 3:
		Sort(st,N,filename);
            break;

        case 4:
		cout << "Enter filename2:" << endl;
		cin >> filename2;
		IndexSort(st,N,filename,filename2);
		IndexPrint(st,N,filename,filename2);
            break;

        case 5:
			cout << "Enter prizv.: " << endl;
			cin >> prizv;
			cout << "chose specialnist: " << endl;
			cout << "0 - computer scient, 1 - informatic, 2 - math_a_economics, 3 - physics_and_informatic, 4 - labor_education: ";
			cin >> spec;
			if (cin.fail() || spec < 0 || spec>4)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "0 - computer scient, 1 - informatic, 2 - math_a_economics, 3 - physics_and_informatic, 4 - labor_education: ";
					cin >> spec;
				} while (cin.fail() || spec < 0 || spec>4);
			}
			sp = (Specialnists)spec;
			cout << " enter average: "; 
			cin >> average;
			if (cin.fail() || average < 1 || average>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');		
					cout << " enter average: "; 
					cin >> average;
				} while (cin.fail() || average < 1 || average>5);
			}

			num = BinSearch(st, N, prizv, sp, average, filename);
			if (num == -1)
			{
				cout << "can`t find" << endl;
			}
			else
			{
				cout << "your student: " << num + 1 << endl;
			}
            break;

        case 0:
            break;
        
        default:
        cout << "Wrond data" << endl;
            break;
        }
    } while (MenuItem != 0);
    
    return 0;
}

void Create(Student& stud, const int N, string filename){
    int specialst;
    for (int i = 0; i < N; i++){
        cout << "student No " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " prizv.: "; 
		cin >> stud.prizv;
		do
		{
			if (stud.prizv.find_first_of("0 123456789", 0) != -1)
			{
				stud.prizv.erase(0, -1);
				cout << "You wrong, please repeat " << endl;
				cout << " prizv.: "; 
				cin >> stud.prizv;
			}
		} while (stud.prizv.find_first_of("0 123456789", 0) != -1);
		cout << " kyrs: "; cin >> stud.kyrs;
		if (cin.fail()||stud.kyrs<1||stud.kyrs>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "You wrong, please repeat " << endl;
				cout << " kyrs: "; cin >> stud.kyrs;
			} while (cin.fail() || stud.kyrs < 1 || stud.kyrs>5);
		}
		cout << " Specialnists (0 - computer science, 1 - informatic, 2 - math and economics, 3 - physics and informatic, 4 - labor education): ";
		cin >> specialst;
		if (cin.fail()||specialst<0||specialst>4)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "you wrong, please repeat " << endl;
				cout << " Specialnists (0 - computer science, 1 - informatic, 2 - math and economics, 3 - physics and informatic, 4 - labor education): ";
				cin >> specialst;
			} while (cin.fail() || specialst < 0 || specialst>4);
		}
		stud.specialst = (Specialnists)specialst;
		cout << " rating math: "; cin >> stud.math_grade;
		if (cin.fail()||stud.math_grade<1||stud.math_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "you wrong, please repeat  " << endl;
				cout << " rating math: "; cin >> stud.math_grade;
			} while (cin.fail() || stud.math_grade < 1 || stud.math_grade>5);
		}
		cout << " rating fizik: "; cin >> stud.physics_grade;

		if (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "you wrong, please repeat  " << endl;
				cout << " rating fizik: "; cin >> stud.physics_grade;
			} while (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5);
		}

		switch (stud.specialst)
		{
		case computer_science:
			cout << "rating programing: "; cin >> stud.programing_grade;
			if (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat  " << endl;
					cout << "rating programing: "; cin >> stud.programing_grade;
				} while (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5);
			}
			break;
		case informatic:
			cout << " rating chisel metod: "; cin >> stud.chisel_metod_grade;
			if (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat " << endl;
					cout << " rating chisel metod : "; cin >> stud.chisel_metod_grade;
				} while (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5);
			}
			break;
		default:
			cout << " rating pedagogic: "; cin >> stud.pedagogic_grade;
			if (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat " << endl;
					cout << " rating pedagogic: "; cin >> stud.pedagogic_grade;
				} while (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5);
			}
			break;
		}
		cout << endl;
		stud.average = (stud.math_grade + stud.physics_grade + stud.specialst) / 3;
        ToFile(stud, N, filename);
    }
}

void ToFile(Student& stud, const int N, string filename)
{
	ofstream f(filename, ios::binary | ios::app);
	f.write((char*)&stud, sizeof(Student));
	f.close();
}

void Print(Student& stud, const int N, string filename){
    ifstream f(filename, ios::binary);
    int num = 1;
    cout << "=====================================================================================================================================================" << endl;
	cout << "| No | prizv. | kyrs |         spec.          | rating math | rating fizik | average | rating programing: | rating chisel metod: | rating pedagogic |" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (f.read((char*)&stud, sizeof(Student))){
        cout << "|  " << setw(1) << right << num++ << " ";
		cout << "| " << setw(7) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(22) << left << List[stud.specialst] << " "
			<< "| " << setw(11) << right << stud.math_grade << " "
			<< "| " << setw(12) << right << stud.physics_grade << " "
			<< "| " << setw(7) << right << stud.average << " ";
        switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(18) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(23) << right << " |" << setw(19) << right << " |" << endl;
			break;
		case informatic:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(21) << right << stud.chisel_metod_grade << " |" << setw(19) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(23) << right << " |" << setw(17) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
    }
    cout << "=====================================================================================================================================================" << endl;
	cout << endl;
}

void Sort(Student& stud, const int N, string filename){
    fstream f(filename, ios::binary | ios::in | ios::out);
	for (int i0 = 0; i0 < N-1; i0++)
	{
		for (int i1 = 0; i1 < N - i0-1; i1++)
		{
			Student a = fRead(f, i1);
			Student b = fRead(f, i1+1);
			if ((a.specialst > b.specialst)
				||
				(a.specialst == b.specialst &&
					a.average < b.average)
				||
				(a.specialst == b.specialst &&
					a.average == b.average &&
					a.prizv[0] > b.prizv[0])
				||
				(a.specialst == b.specialst &&
					a.average == b.average &&
					a.prizv[0] == b.prizv[0]&&
					a.prizv[1] == b.prizv[1]))
			{
				fChange(f, i1 , i1 + 1);
			}
		}
	}
	f.seekp(0, ios::end);
}

void fWrite(fstream& f, const int i, Student x)
{
	f.seekp(i * (long)sizeof(Student)); // âñòàíîâèëè âêàç³âíèê
	f.write((char*)&x, sizeof(Student)); // çàïèñàëè çíà÷åííÿ
}

Student fRead(fstream& f, const int i)
{
	Student tmp;
	f.seekg(i * (long)sizeof(Student)); 
	f.read((char*)&tmp, sizeof(Student));
	return tmp;
}

Student fRead2(ifstream& f, const int i)
{
	Student tmp;
	f.seekg(i * (long)sizeof(Student)); // âñòàíîâèëè âêàç³âíèê
	f.read((char*)&tmp, sizeof(Student)); // ïðî÷èòàëè çíà÷åííÿ
	return tmp;
}

void fChange(fstream& f, const int i, const int j)
{
	Student x = fRead(f, i);
	Student y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void IndexSort(Student& stud, const int N, string filename1, string filename2){
    ifstream f1(filename1, ios::binary);
	ofstream f2(filename2, ios::binary);
	int* I = new int[N]; // ñòâîðèëè ³íäåêñíèé ìàñèâ
	for (int i = 0; i < N; i++)
		I[i] = i; // çàïîâíèëè éîãî ïî÷àòêîâèìè äàíèìè
	int i0, i1, value,i,j;
    for (i = 1; i < N; i++)
	{
		value = I[i];
		Student b = fRead2(f1, value);
		for (j = i - 1; j >= 0; j--)
		{
			Student a = fRead2(f1, I[j]);
			if ((a.specialst > b.specialst)
				||
				(a.specialst == b.specialst &&
					a.average < b.average)
				||
				(a.specialst == b.specialst &&
					a.average == b.average &&
					a.prizv[0] > b.prizv[0])
				||
				(a.specialst == b.specialst &&
					a.average == b.average &&
					a.prizv[0] == b.prizv[0]&&
					a.prizv[1] > b.prizv[1]))
			{
				I[j + 1] = I[j];
			}
			else
			{
				break;
			}
		}
		I[j + 1] = value;
	}
	for (int i = 0; i < N; i++)
	{
		f2.write((char*)&I[i], sizeof(int));
	}
	f2.close();
	delete[] I;
}

void IndexPrint(Student& stud, const int N, string filename1, string filename2){
    int* I = new int[N];
	ifstream f1(filename1, ios::binary);
	ifstream f2(filename2, ios::binary);
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		f2.read((char*)&I[i], sizeof(int));
	}
	cout << endl;
    cout << "==================================================================================================================================================" << endl;
	cout << "| No | prizv. | kyrs |        spec.        | rating math | rating fizik | average | rating programing: | rating chisel metod: | rating pedagogic |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		f1.seekg(I[i] * (long)sizeof(Student)); 
		f1.read((char*)&stud, sizeof(Student));
		cout << "|  " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(6) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(22) << left << List[stud.specialst] << " "
			<< "| " << setw(11) << right << stud.math_grade << " "
			<< "| " << setw(12) << right << stud.physics_grade << " "
			<< "| " << setw(7) << right << stud.average << " ";
        switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(18) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(23) << right << " |" << setw(19) << right << " |" << endl;
			break;
		case informatic:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(21) << right << stud.chisel_metod_grade << " |" << setw(19) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(23) << right << " |" << setw(17) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
	}
    cout << "==================================================================================================================================================" << endl;
	cout << endl;
    delete[] I;
	f1.close();
	f2.close();
}

int BinSearch(Student& stud1, const int N, string prizv, Specialnists special, float average, string filename)
{
	Student stud;
	fstream f(filename, ios::binary | ios::out | ios::in);
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		stud = fRead(f, m);
		if (stud.prizv == prizv && stud.specialst == special && stud.average == average)
			return m;
		if ((stud.average < average)
			||
			(stud.average == average &&
				stud.specialst < special) ||
			(stud.average == average &&
				stud.specialst == special &&
				stud.prizv < prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}