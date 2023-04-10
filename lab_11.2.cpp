#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

enum Specialyty {
    CS,
    INFORM,
    MATHandECONOM,
    PHISYCSandINFORM,
    WORKTRAINING};

std::string specialytyStr[] = {"CS","IN","MATH","PHISIC","INF"};

struct Student
{
    std::string lastName;
    int course;
    Specialyty specialyty;
    int markPHISICS;
    int markMATH;
    union 
    {
        int markPROGRAMMING;
        int markNUMERICALMETHODS;
        int markPEDAGOGICS;
    };
    
};

void create(Student& s, std::string filename, const int N);
void print(Student& s, std::string filename, const int N);
void name(Student& s, std::string filename, const int N);
void number(Student& s, std::string filename, const int N);
void toFile(Student& s, std::string filename, const int N);

int main(){
    std::string filename;
    int N;
    std::cout << "Enter filename:" << std::endl;
    std::cin >> filename;
    std::cout << "Enter count of student: " << std::endl;
    std::cin >> N;
    Student s;
    create(s,filename,N);
    print(s,filename,N);
    name(s,filename,N);
    number(s,filename,N);
    return 0;
}

void create(Student& s, std::string filename, const int N){
    int specialyty;
    for (int i = 0; i < N; i++)
    {
        std::cout << "student No " << i + 1 << ":" << std::endl;
        std::cin.get();
        std::cin.sync();
        std::cout << " Prizv.: "; getline(std::cin, s.lastName);
        std::cout << " Kyrs: "; std::cin >> s.course;
        std::cout << " Spec(0 - CS, 1 - IN, 2 - ME, 3 - FE, 4 - TN): ";
        std::cin >> specialyty;
        s.specialyty = (Specialyty)specialyty;
        std::cout << " rating fizik: "; std::cin >> s.markPHISICS;
        std::cout << " rating math: "; std::cin >> s.markMATH;
        switch (s.specialyty)
        {
        case CS:
            std::cout << " rating programing: "; std::cin >> s.markPROGRAMMING;
            break;
        case INFORM:
            std::cout << " rating number method: "; std::cin >> s.markNUMERICALMETHODS;
            break;
        case MATHandECONOM:
            std::cout << " rating pedagogig: "; std::cin >> s.markPEDAGOGICS;
            break;
        case PHISYCSandINFORM:
            std::cout << " rating pedagogig: "; std::cin >> s.markPEDAGOGICS;
            break;
        case WORKTRAINING:
            std::cout << " rating pedagogig: "; std::cin >> s.markPEDAGOGICS;
            break;
        }
        std::cout << std::endl;
        toFile(s, filename, N);
    }
}

void print(Student& s, std::string filename, const int N){
    std::ifstream f(filename, std::ios::binary);
    int count = 1;
    std::cout << std::endl << std::endl;
    std::cout << " ================================================================================================================  " << std::endl;
    std::cout << " |    |        |      |        |                                   rating                                       | " << std::endl;
    std::cout << " | No | prizv. | kurs | spec.  |--------------------------------------------------------------------------------| " << std::endl;
    std::cout << " |    |        |      |        |  fizik   |     math     |    programin    |    number method    |  pedagogig   | " << std::endl;
    std::cout << " ================================================================================================================  " << std::endl;
    while (f.read((char*)&s, sizeof(Student))){
        std::cout << " |  " << std::right << count++ << " ";
        std::cout << "| " << std::setw(6) << std::left << s.lastName << " "
            << "| " << std::setw(4) << std::right << s.course << " "
            << "| " << std::setw(6) << std::left << specialytyStr[s.specialyty] << " ";
        std::cout << "| " << std::setw(8) << std::right << s.markPHISICS << " "
            << "| " << std::setw(12) << std::right << s.markMATH << " ";
        switch (s.specialyty)
        {
        case CS:
            std::cout << "| " << std::setw(15) << std::right << s.markPROGRAMMING << " |                     |              |" << std::endl;
            break;
        case INFORM:
            std::cout << "|                 | " << std::setw(19) << std::right << s.markNUMERICALMETHODS << " |              |" << std::endl;
            break;
        case MATHandECONOM:
            std::cout << "|                 |                     |" << std::setw(13) << std::right << s.markPEDAGOGICS << " |" << std::endl;
            break;
        case PHISYCSandINFORM:
            std::cout << "|                 |                     |" << std::setw(13) << std::right << s.markPEDAGOGICS << " |" << std::endl;
            break;
        case WORKTRAINING:
            std::cout << "|                 |                     |" << std::setw(13) << std::right << s.markPEDAGOGICS << " |" << std::endl;
            break;
        }
    }

    std::cout << " ================================================================================================================  " << std::endl;
    std::cout << std::endl;
}

void name(Student& s, std::string filename, const int N){
    std::ifstream f (filename, std::ios::binary);
    std::cout << "prizv of student that dont have rating less then 4" << std::endl;
    while (f.read((char*)&s, sizeof(Student)))
    {
         if (
            (s.markPHISICS > 3)
            &&
            (s.markMATH > 3)
            &&
            (s.markPROGRAMMING > 3)
            &&
            (s.markNUMERICALMETHODS > 3)
            &&
            (s.markPEDAGOGICS > 3)
        )
        std::cout << s.lastName << std::endl;
    }
    f.close();
}

void number(Student& s, std::string filename, const int N){
    std::ifstream f(filename, std::ios::binary);
    int x = 0;
    while (f.read((char*)&s, sizeof(Student)))
    {
        if(s.markPHISICS == 5){
            x++;
        }
    }
    std::cout << "count of student that have 5 on fizik: " << x << std::endl;
}

void toFile(Student& s, std::string filename, const int N){
    std::ofstream f(filename, std::ios::binary | std::ios::app);
    f.write((char*)&s, sizeof(Student));
    f.close();
}