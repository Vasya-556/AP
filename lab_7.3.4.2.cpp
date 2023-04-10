#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** matrix,int rowCount, int colCount, int rowNo, int Low, int High);
void Create2(int** matrix,int rowCount, int colCount, int rowNo, int colNo, int Low, int High);
void Print(int** matrix, const int rowCount, const int colCount, int rowNo);
void Print2(int** matrix, const int rowNo, const int colCount, int colNo);
void RN1(int** matrix,int rowCount, int colCount, int rowNo, int colNo);
void RN2(int **matrix, int rowCount, int colCount, int rowNo,int colNo, int tmp, int count);
int maxCount = 0;
int maxLine = 0;

int main(){
	srand((unsigned)time(NULL));

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

    int Low = 0;
    int High = 1;

	int** matrix = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		matrix[i] = new int[colCount];

    Create(matrix, rowCount,colCount,0,Low,High);
    cout << endl;
	Print(matrix, rowCount, colCount, 0);
    // R - row, n - number
    RN1(matrix, rowCount,colCount,0,0);
    cout << endl << maxLine << endl;

    for (int i = 0; i < rowCount; i++)
		delete[] matrix[i];
	delete[] matrix;

    return 0;
}

void Create(int** matrix, int rowCount, int colCount, int rowNo, int Low, int High){
    Create2(matrix,rowCount,colCount,rowNo,0,Low,High);
    if (rowNo < rowCount - 1)
	{
		Create(matrix, rowCount, colCount, rowNo + 1, Low, High);
	}
}

void Create2(int** matrix, int rowCount, int colCount, int rowNo,int colNo, int Low, int High){
    matrix[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
	{
		Create2(matrix, rowCount, colCount,rowNo, colNo + 1,Low,High);
	}
}

void Print(int** matrix, const int rowCount, const int colCount, int rowNo)
{
	Print2(matrix, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Print(matrix, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Print2(int** matrix, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << matrix[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Print2(matrix, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void RN1(int **matrix, int rowCount, int colCount, int rowNo,int colNo){
    int tmp = matrix[rowNo][0];
    RN2(matrix, rowCount,colCount,rowNo,0, tmp, 0);
    // cout << endl;
    if (rowNo < rowCount - 1)
        RN1(matrix,rowCount,colCount,rowNo +1 ,colNo);
}

void RN2(int **matrix,int rowCount, int colCount, int rowNo, int colNo, int tmp, int count){
    // cout << "row = " << rowNo << "  " << "col = " << colNo << endl;
    // if (matrix[rowNo][colNo] == tmp){
    //     count ++;
    //     }
    // else{
    //     count =1;
    //     tmp = matrix[rowNo][colNo];
    // }
    
    // for (int i = 0; i < colCount; i++){
    //     if (matrix[rowNo][colNo] == matrix[rowNo][i]){
    //         count ++;
    //     }
    //     // cout << matrix[rowNo][i] << endl;
    // }
    // cout << endl;
    // if (maxCount < count) {
    //     maxCount = count;
    //     maxLine = rowNo;
    // }
    // cout << tmp << endl;

    int curr = 1;

    if(tmp == matrix[rowNo][colNo])
        count++;
    else{
        tmp == matrix[rowNo][colNo];
        if(count <= curr)
            count = curr;
        else
            curr = count;
    }

    if (colNo < colCount - 1)
        RN2(matrix,rowCount,colCount,rowNo,colNo + 1, tmp, count);
    else
        cout << count << endl;
}