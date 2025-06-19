#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "");
    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % (ROWS * COLS);
        }
    }
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