#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount, int rowNo);
void Create2(int** matrix, const int rowNo, const int colCount, int colNo);
void Print(int** matrix, const int rowCount, const int colCount, int rowNo);
void Print2(int** matrix, const int rowNo, const int colCount, int colNo);
int Low = 0;
int High = 1;
int maxCount = 0;
int maxRow = 0;
int currentCount = 0;
int currentNumber = 0;
void Part2_row(int** matrix, const int rowCount, const int colCount, int rowNo, int colNo, int cur_count, int count);
void Part2_col(int** matrix, const int rowCount, const int colCount, int rowNo, int colNo, int cur_count, int count);

int main() {
	srand((unsigned)time(NULL));
	
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** matrix = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		matrix[i] = new int[colCount];

	Create(matrix, rowCount, colCount,0);
	Print(matrix, rowCount, colCount,0);

	// Part2(matrix, rowCount, colCount,0,0,1,0);
	Part2_row(matrix,rowCount,colCount,0,0,0,1);

	for (int i = 0; i < rowCount; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}

void Create(int** matrix, const int rowCount, const int colCount, int rowNo)
{
	Create2(matrix, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Create(matrix, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Create2(int** matrix, const int rowNo, const int colCount, int colNo)
{
    matrix[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
	{
		Create2(matrix, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
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

// void Part2(int** matrix, const int rowCount, const int colCount, int rowNo, int colNo, int cur_count, int count){
// 	int tmp = matrix[rowNo][colNo];
// 	if (cur_count > count){
// 		count = cur_count;
// 	}
// 	cout << count << endl;
// 	if (rowNo < rowCount -1){
// 		if(tmp == matrix[rowNo+1][colNo]){
// 			cur_count++;
// 		}
// 		Part2(matrix,rowCount,colCount,rowNo +1,colNo,cur_count,count );
// 	}
// }


void Part2_row(int** matrix, const int rowCount, const int colCount, int rowNo, int colNo, int cur_count, int count){
	// cout << "rowNo" << endl;		
	// Part2_col(matrix,rowCount,colCount,rowNo,0,cur_count,count);
	// if(rowNo < rowCount -1){
	// 	Part2_row(matrix,rowCount,colCount,rowNo + 1,0,cur_count,count);
	// }
	Part2_col(matrix,rowCount,colCount,rowNo,0,cur_count,count);
	cout << maxRow <<endl;

	
}

void Part2_col(int** matrix, const int rowCount, const int colCount, int rowNo, int colNo, int cur_count, int count){
	// cout << "colNo" << endl;
	// cout << colNo << endl;

	// int tmp = matrix[0][0];
	// for (int i = 0; i < rowNo; i++){
	// 	cur_count = 0;
	// 	for(int j = 0; j < colNo;j++){
	// 		if (tmp == matrix[i][j]){
	// 			cur_count ++;
	// 			}
	// 		else{
	// 			tmp == matrix[i][j];
	// 			if (cur_count <= count)
	// 				cur_count = count;
	// 			else
	// 				count = cur_count;
	// 		}
	// 	}
	// }
	// int tmp = matrix[rowNo][colNo];
	// if (tmp == matrix[rowNo][colNo+1]){
	// 	cur_count++;
	// }
	// else{
	// 	tmp == matrix[rowNo][colNo+1];
	// 	if (cur_count < count)
	// 		cur_count = count;
	// 	else
	// 		count = cur_count;
	// }
	int tmp = matrix[rowNo][0];
	// cout << count << endl;
	// count ++;

	
		if (rowNo == rowCount){
		return;
	}
	if (colNo == colCount){
		if (currentCount > maxCount){
			maxCount = currentCount;
			maxRow = rowNo - 1;
		}
		currentCount = 0;
		Part2_col(matrix,rowCount,colCount,rowNo,colNo + 1,cur_count,count);
		return;
	}
	if (matrix[rowNo][colNo]==tmp)
		currentCount ++;
	else{
		tmp = matrix[rowNo][colNo];
		currentCount = 1;
	}
	Part2_col(matrix,rowCount,colCount,rowNo,colNo + 1,cur_count,count);




	//  if (colNo < colCount - 1)
		// Part2_col(matrix,rowCount,colCount,rowNo,colNo + 1,cur_count,count);
}