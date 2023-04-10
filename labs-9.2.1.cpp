#include<iostream>
#include<iomanip>
#include<string>

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
	long average;
};

void Create(Student* stud, const int N)
{
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "student No " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " prizv.: "; getline(cin, stud[i].prizv);
		do
		{
			if (stud[i].prizv.find_first_of("0 123456789", 0) != -1)
			{
				stud[i].prizv.erase(0, -1);
				cout << "You wrong, please repeat " << endl;
				cout << " prizv.: "; getline(cin, stud[i].prizv);
			}
		} while (stud[i].prizv.find_first_of("0 123456789", 0) != -1);
		cout << " kyrs: "; cin >> stud[i].kyrs;
		if (cin.fail()||stud[i].kyrs<1||stud[i].kyrs>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "You wrong, please repeat " << endl;
				cout << " kyrs: "; cin >> stud[i].kyrs;
			} while (cin.fail() || stud[i].kyrs < 1 || stud[i].kyrs>5);
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
		stud[i].specialst = (Specialnists)specialst;
		cout << " rating math: "; cin >> stud[i].math_grade;
		if (cin.fail()||stud[i].math_grade<1||stud[i].math_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "you wrong, please repeat  " << endl;
				cout << " rating math: "; cin >> stud[i].math_grade;
			} while (cin.fail() || stud[i].math_grade < 1 || stud[i].math_grade>5);
		}
		cout << " rating fizik: "; cin >> stud[i].physics_grade;

		if (cin.fail() || stud[i].physics_grade < 1 || stud[i].physics_grade>5)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "you wrong, please repeat  " << endl;
				cout << " rating fizik: "; cin >> stud[i].physics_grade;
			} while (cin.fail() || stud[i].physics_grade < 1 || stud[i].physics_grade>5);
		}

		switch (stud[i].specialst)
		{
		case computer_science:
			cout << "rating programing: "; cin >> stud[i].programing_grade;
			if (cin.fail() || stud[i].programing_grade < 1 || stud[i].programing_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat  " << endl;
					cout << "rating programing: "; cin >> stud[i].programing_grade;
				} while (cin.fail() || stud[i].programing_grade < 1 || stud[i].programing_grade>5);
			}
			break;
		case informatic:
			cout << " rating chisel metod: "; cin >> stud[i].chisel_metod_grade;
			if (cin.fail() || stud[i].chisel_metod_grade < 1 || stud[i].chisel_metod_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat " << endl;
					cout << " rating chisel metod : "; cin >> stud[i].chisel_metod_grade;
				} while (cin.fail() || stud[i].chisel_metod_grade < 1 || stud[i].chisel_metod_grade>5);
			}
			break;
		default:
			cout << " rating pedagogic: "; cin >> stud[i].pedagogic_grade;
			if (cin.fail() || stud[i].pedagogic_grade < 1 || stud[i].pedagogic_grade>5)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "you wrong, please repeat " << endl;
					cout << " rating pedagogic: "; cin >> stud[i].pedagogic_grade;
				} while (cin.fail() || stud[i].pedagogic_grade < 1 || stud[i].pedagogic_grade>5);
			}
			break;
		}
		cout << endl;
		stud[i].average = (stud[i].math_grade + stud[i].physics_grade + stud[i].specialst) / 3;
	}
}

void Print(Student* stud, const int N, string* List)
{
	cout << "=============================================================================================================================================================="
		<< endl;
	cout << "| No |     prizv.      | kyrs |         spec.          | rating math | rating fizik | average | rating programing: | rating chisel metod: | rating pedagogic |"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|  " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << stud[i].prizv
			<< "| " << setw(4) << right << stud[i].kyrs << " "
			<< "| " << setw(22) << left << List[stud[i].specialst] << " "
			<< "| " << setw(11) << right << stud[i].math_grade << " "
			<< "| " << setw(12) << right << stud[i].physics_grade << " "
			<< "| " << setw(7) << right << stud[i].average << " ";
		switch (stud[i].specialst)
		{
		case computer_science:
			cout << "| " << setw(18) << setprecision(2) << fixed << right
				<< stud[i].programing_grade << " |" << setw(23) << right << " |" << setw(19) << right << " |" << endl;
			break;
		case informatic:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(21) << right << stud[i].chisel_metod_grade << " |" << setw(19) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< " |" << setw(23) << right << " |" << setw(17) << right << stud[i].pedagogic_grade << " |" << endl;
			break;
		}
	}
	cout << "=============================================================================================================================================================="

		<< endl;
	cout << endl;
}

void Sort(Student* stud, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) 
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((stud[i1].specialst > stud[i1 + 1].specialst)
				||
				(stud[i1].specialst == stud[i1 + 1].specialst &&
					stud[i1].average < stud[i1 + 1].average)
				|| 
				(stud[i1].specialst == stud[i1 + 1].specialst &&
					stud[i1].average == stud[i1 + 1].average&&
					stud[i1].prizv > stud[i1 + 1].prizv))
			{
				tmp = stud[i1];
				stud[i1] = stud[i1 + 1];
				stud[i1 + 1] = tmp;
			}
}

int main()
{
	string List[] = {
	"computer science",
	"informatic",
	"math and economics",
	"physics and informatic",
	"labor education",
	"average"
	};

	int N;
	cout << "Enter N:"; cin >> N;
	if (cin.fail())
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "You wrong, please repeat " << endl;
			cout << "Enter N: "; cin >> N;
		} while (cin.fail());
	}

	Student* stud = new Student[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "select action:" << endl << endl;
		cout << " [1] - enter data from the keyboard" << endl;
		cout << " [2] - display the data" << endl;
		cout << " [3] - sort" << endl;
		cout << " [0] - exit" << endl << endl;
		cout << "select a value: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(stud, N);
			break;
		case 2:
			Print(stud, N, List);
			break;
		case 3:
			Sort(stud, N);
			break;
		case 0:
			break;
		default:
			cout << "you wrong, please repeat "<< endl;
		}
	} while (menuItem != 0);

	return 0;
}