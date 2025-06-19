#include <iostream>
using namespace std;
#define ZD_1
//#define tab "\t"
#define delimiter "\n-----------------------\n"
//#define COLUMS_SHIFT
//#define CROSS_CUTING

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 10;
	const int COLS = 10;
	int arr[ROWS][COLS] =
	{
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 },
		{ 11, 12, 13, 14, 15, 17, 18, 19 },
		{ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29  },
	};

#ifdef DEBUG

	int min, max;
	min = max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)max = arr[i][j];
			if (arr[i][j] > min)max = arr[i][j];
		}
	}
#endif // DEBUG
	
	/*int number_of_shifts;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;*/

#ifdef COLUMS_SHIFT
	for (int i = 9; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	for (int i; i < ROWS; i++)
	{
		int buffer = arr[i][0];
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j - 1] = arr[i][j];
		}
		arr[i][COLS - 1] = buffer;
	}
#endif // tab "\t"
#ifdef CROSS_CUTING
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0][0];
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 1; j < COLS; j++)
			{
				arr[i][j - 1] = arr[i][j];
			}
			if (i != ROWS - 1)arr[i][COLS - 1] = arr[i + 1][0];
		}
		arr[ROWS - 1][COLS - 1] = buffer;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{

		}
	}
#endif // DEBUG
	int iterrations = 0;
	int exchanges = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					//arr[i][j] //выбранный 
					//arr[k][l] //перебираемый
					iterrations++;
					if (arr[k][l] < arr[i][j])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
						exchanges++;
					}
				}
			}
		}
	}
	cout << "Количество итераций: " << iterrations << endl;
	cout << "Количество обменов: " << exchanges << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
		cout << endl;
	}
}
